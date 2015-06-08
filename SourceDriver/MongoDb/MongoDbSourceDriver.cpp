//
// Created by LE, Duc Anh on 6/5/15.
//

#include <iostream>
#include <mongoc.h>
#include <Framework/Exception/EntityException.h>
#include "MongoDbSourceDriver.h"
#include "MongoDbSourceException.h"

namespace Cloude {
    namespace SourceDriver {
        namespace MongoDb {

            class Command {
            public:
                Command(const mongoc_client_t &client, const mongoc_collection_t &collection) : collection(collection),
                                                                                                client(client) {
                    _ptrBsonPredicate = bson_new();
                    _ptrBsonProjection = bson_new();
                };

                ~Command() {

                    if (_ptrBsonPredicate != nullptr) {
                        bson_destroy(_ptrBsonPredicate);
                    }

                    if (_ptrBsonProjection != nullptr) {
                        bson_destroy(_ptrBsonProjection);
                    }
                }

                bson_t *_ptrBsonPredicate = nullptr;
                bson_t *_ptrBsonProjection = nullptr;

                bson_error_t error;
                bson_oid_t oid;

                const mongoc_client_t &client;
                const mongoc_collection_t &collection;

            private:
                //
            };

            class MongoDbSourceDriver::MongoDbApiImpl {
            public:
                MongoDbApiImpl() {
                    mongoc_init();
                }

                ~MongoDbApiImpl() {

                    if (_ptrCollection != nullptr) {
                        mongoc_collection_destroy(_ptrCollection);
                    }

                    if (_ptrClient != nullptr) {
                        mongoc_client_destroy(_ptrClient);
                    }

                    mongoc_cleanup();
                }

                std::shared_ptr<Command> createCommand() {

                    if (_ptrClient == nullptr || _ptrCollection == nullptr) {
                        std::string message("Either client or collection is a nullptr");
                        MongoDbSourceException ex;
                        ex.setMessage(message);
                        throw ex;
                    }

                    auto command = std::make_shared<Command>(*_ptrClient, *_ptrCollection);

                    return command;
                }

                std::string parseConnectionString(Options &optionArgs) {

                    std::string connStr = "mongodb://";

                    if (optionArgs.User.length() > 0 && optionArgs.Pass.length() > 0) {
                        connStr += optionArgs.User + ":" + optionArgs.Pass;
                        connStr += "@";
                    }

                    connStr += optionArgs.Host;
                    connStr += ":";
                    connStr += std::to_string(optionArgs.Port);

                    return connStr;
                }

                mongoc_client_t *_ptrClient = nullptr;
                mongoc_collection_t *_ptrCollection = nullptr;

            private:
                //
            };


            MongoDbSourceDriver::MongoDbSourceDriver(Framework::EntityMap &entityMap)
                    : EntitySourceDriver(entityMap),
                      _mongoDbApiImpl(new MongoDbApiImpl()) {
                //
            }

            int MongoDbSourceDriver::LoadEntity(std::shared_ptr<Entity> &entity) const {

                auto &columnsForKey = _entityMap.getColumnsForKey();
                auto &columnsForGet = _entityMap.getColumnsForGet();

                std::shared_ptr<Command> command = _mongoDbApiImpl->createCommand();

                std::for_each(columnsForKey.cbegin(),
                              columnsForKey.cend(),
                              [&command, &entity](const std::shared_ptr<Column> &column) {

                                  auto field = entity->getField(column->getName());

                                  switch (column->getDbType()) {
                                      case DbType::Int64:
                                          BSON_APPEND_INT64(command->_ptrBsonPredicate,
                                                            column->getDatasourceName().c_str(),
                                                            field->getInt64());
                                          break;
                                      case DbType::String:
                                          BSON_APPEND_UTF8(command->_ptrBsonPredicate,
                                                           column->getDatasourceName().c_str(),
                                                           field->getCString());
                                          break;
                                      default:
                                          break;
                                  }
                              });

                std::for_each(columnsForGet.cbegin(),
                              columnsForGet.cend(),
                              [&command](const std::shared_ptr<Column> &column) {

                                  BSON_APPEND_INT32(command->_ptrBsonProjection,
                                                    column->getDatasourceName().c_str(),
                                                    1);
                              });

                const bson_t *ptrDoc;
                mongoc_cursor_t *ptrCursor;
                bson_iter_t iter;

                // TODO: Implement explicit projection
                ptrCursor = mongoc_collection_find(_mongoDbApiImpl->_ptrCollection,
                                                   MONGOC_QUERY_NONE,
                                                   0,
                                                   0,
                                                   0,
                                                   command->_ptrBsonPredicate,
                                                   NULL,
                                                   NULL);

                int rowCount = 0;

                while (mongoc_cursor_next(ptrCursor, &ptrDoc)) {

                    size_t err_offset;

                    if (!bson_validate(ptrDoc, BSON_VALIDATE_NONE, &err_offset)) {
                        // TODO: throw an appropriate exception if document is invalid
                        fprintf(stderr, "The document failed to validate at offset: %u\n", (unsigned) err_offset);
                    }

                    if (bson_iter_init(&iter, ptrDoc)) {

                        while (bson_iter_next(&iter)) {

                            std::string columnName(bson_iter_key(&iter));

                            try {

                                auto field = entity->getField(columnName);
                                auto column = field->getColumn();

                                switch (column->getDbType()) {
                                    case DbType::Int64:
                                        field->setInt64(bson_iter_as_int64(&iter));
                                        break;
                                    case DbType::String:
                                        field->setCString(bson_iter_utf8(&iter, 0));
                                        break;
                                    default:
                                        break;
                                }

                            } catch (Framework::Exception::EntityException &ex) {
                                continue;
                            }
                        }
                    }

                    ++rowCount;
                }

                mongoc_cursor_destroy(ptrCursor);

                return rowCount;
            }

            int MongoDbSourceDriver::CreateEntity(std::shared_ptr<Entity> &entity) const {

                auto &columnsForKey = _entityMap.getColumnsForKey();

                std::shared_ptr<Command> command = _mongoDbApiImpl->createCommand();

                bson_oid_init(&command->oid, NULL);

                std::for_each(columnsForKey.cbegin(),
                              columnsForKey.cend(),
                              [&command, &entity](const std::shared_ptr<Column> &column) {

                                  auto field = entity->getField(column->getName());

                                  switch (column->getDbType()) {
                                      case DbType::Int64:
                                          BSON_APPEND_INT64(command->_ptrBsonProjection,
                                                            column->getDatasourceName().c_str(),
                                                            field->getInt64());
                                          break;
                                      case DbType::String:
                                          BSON_APPEND_UTF8(command->_ptrBsonProjection,
                                                           column->getDatasourceName().c_str(),
                                                           field->getCString());
                                          break;
                                      default:
                                          break;
                                  }
                              });

                if (!mongoc_collection_insert(_mongoDbApiImpl->_ptrCollection,
                                              MONGOC_INSERT_NONE,
                                              command->_ptrBsonProjection,
                                              NULL,
                                              &command->error)) {
                    // TODO: throw an approriate exception
                    return 0;
                }

                return 1;
            }

            int MongoDbSourceDriver::SaveEntity(std::shared_ptr<Entity> &entity) const {

                auto &columnsForKey = _entityMap.getColumnsForKey();
                auto &columnsForUpdate = _entityMap.getColumnsForUpdate();

                std::shared_ptr<Command> command = _mongoDbApiImpl->createCommand();

                std::for_each(columnsForKey.cbegin(),
                              columnsForKey.cend(),
                              [&command, &entity](const std::shared_ptr<Column> &column) {

                                  auto field = entity->getField(column->getName());

                                  switch (column->getDbType()) {
                                      case DbType::Int64:
                                          BSON_APPEND_INT64(command->_ptrBsonPredicate,
                                                            column->getDatasourceName().c_str(),
                                                            field->getInt64());
                                          break;
                                      case DbType::String:
                                          BSON_APPEND_UTF8(command->_ptrBsonPredicate,
                                                           column->getDatasourceName().c_str(),
                                                           field->getCString());
                                          break;
                                      default:
                                          break;
                                  }
                              });

                bson_t *ptrProj;
                ptrProj = bson_new();

                std::for_each(columnsForUpdate.cbegin(),
                              columnsForUpdate.cend(),
                              [&ptrProj, &entity](const std::shared_ptr<Column> &column) {

                                  auto field = entity->getField(column->getName());

                                  switch (column->getDbType()) {
                                      case DbType::Int64:
                                          BSON_APPEND_INT64(ptrProj,
                                                            column->getDatasourceName().c_str(),
                                                            field->getInt64());
                                          break;
                                      case DbType::String:
                                          BSON_APPEND_UTF8(ptrProj,
                                                           column->getDatasourceName().c_str(),
                                                           field->getCString());
                                          break;
                                      default:
                                          break;
                                  }
                              });

                BSON_APPEND_DOCUMENT(command->_ptrBsonProjection, "$set", ptrProj);

                if (!mongoc_collection_update(_mongoDbApiImpl->_ptrCollection,
                                              MONGOC_UPDATE_NONE,
                                              command->_ptrBsonPredicate,
                                              command->_ptrBsonProjection,
                                              NULL,
                                              &command->error)) {
                    // TODO: throw an appropriate exception
                    printf("%s\n", command->error.message);
                    return 0;
                }

                return 1;
            }

            int MongoDbSourceDriver::DeleteEntity(std::shared_ptr<Entity> &entity) const {

                auto &columnsForKey = _entityMap.getColumnsForKey();

                std::shared_ptr<Command> command = _mongoDbApiImpl->createCommand();

                std::for_each(columnsForKey.cbegin(),
                              columnsForKey.cend(),
                              [&command, &entity](const std::shared_ptr<Column> &column) {

                                  auto field = entity->getField(column->getName());

                                  switch (column->getDbType()) {
                                      case DbType::Int64:
                                          BSON_APPEND_INT64(command->_ptrBsonPredicate,
                                                            column->getDatasourceName().c_str(),
                                                            field->getInt64());
                                          break;
                                      case DbType::String:
                                          BSON_APPEND_UTF8(command->_ptrBsonPredicate,
                                                           column->getDatasourceName().c_str(),
                                                           field->getCString());
                                          break;
                                      default:
                                          break;
                                  }
                              });

                if (!mongoc_collection_remove(_mongoDbApiImpl->_ptrCollection,
                                              MONGOC_REMOVE_NONE,
                                              command->_ptrBsonPredicate,
                                              NULL,
                                              &command->error)) {
                    // TODO: throw an approriate exception
                    return 0;
                }

                return 1;
            }

            void MongoDbSourceDriver::Connect() {

                std::string uriString = _mongoDbApiImpl->parseConnectionString(_optionArgs);

                _mongoDbApiImpl->_ptrClient = mongoc_client_new(uriString.c_str());
                _mongoDbApiImpl->_ptrCollection = mongoc_client_get_collection(_mongoDbApiImpl->_ptrClient,
                                                                               _optionArgs.Base.c_str(),
                                                                               _entityMap.TableName().c_str());
            }

            void MongoDbSourceDriver::Disconnect() {
                //
            }

            void MongoDbSourceDriver::init() {
                //
            }
        }
    }
}


