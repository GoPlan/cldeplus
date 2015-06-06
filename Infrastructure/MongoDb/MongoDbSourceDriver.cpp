//
// Created by LE, Duc Anh on 6/5/15.
//

#include <mongoc.h>
#include "MongoDbSourceDriver.h"
#include "MongoDbSourceException.h"

namespace Cloude {
    namespace Infrastructure {
        namespace MongoDb {

            class Command {
            public:
                Command(const mongoc_client_t &client, const mongoc_collection_t &collection) : collection(collection),
                                                                                                client(client) {
                    _ptrQuery = bson_new();
                    _ptrDoc = bson_new();
                };

                ~Command() {

                    if (_ptrQuery != nullptr) {
                        bson_destroy(_ptrQuery);
                    }

                    if (_ptrDoc != nullptr) {
                        bson_destroy(_ptrDoc);
                    }
                }

                bson_t *_ptrQuery = nullptr;
                bson_t *_ptrDoc = nullptr;
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


            MongoDbSourceDriver::MongoDbSourceDriver(Architecture::EntityMap &entityMap)
                    : EntitySourceDriver(entityMap), _mongoDbApiImpl(new MongoDbApiImpl()) {
                //
            }

            int MongoDbSourceDriver::LoadEntity(std::shared_ptr<Entity> &entity,
                                                const EntityMap &entityMap) const {

                std::shared_ptr<Command> command = _mongoDbApiImpl->createCommand();

                mongoc_cursor_t *ptrCursor;

                ptrCursor = mongoc_collection_find(_mongoDbApiImpl->_ptrCollection,
                                                   MONGOC_QUERY_NONE,
                                                   0,
                                                   0,
                                                   0,
                                                   command->_ptrQuery,
                                                   NULL,
                                                   NULL);

                // Load cursor fields to entity fields

                mongoc_cursor_destroy(ptrCursor);

                return 1;
            }

            int MongoDbSourceDriver::CreateEntity(std::shared_ptr<Entity> &entity,
                                                  const EntityMap &entityMap) const {

                auto &columnsForKey = entityMap.getColumnsForKey();

                std::shared_ptr<Command> command = _mongoDbApiImpl->createCommand();

                bson_oid_init(&command->oid, NULL);

                std::for_each(columnsForKey.cbegin(),
                              columnsForKey.cend(),
                              [&command, &entity](const std::shared_ptr<Column> &column) {

                                  auto field = entity->getField(column->getName());

                                  switch (column->getDbType()) {
                                      case DbType::Int64:
                                          BSON_APPEND_INT64(command->_ptrDoc,
                                                            column->getDatasourceName().c_str(),
                                                            field->getInt64());
                                          break;
                                      case DbType::String:
                                          BSON_APPEND_UTF8(command->_ptrDoc,
                                                           column->getDatasourceName().c_str(),
                                                           field->getCString());
                                          break;
                                      default:
                                          break;
                                  }
                              });

                if (!mongoc_collection_insert(_mongoDbApiImpl->_ptrCollection,
                                              MONGOC_INSERT_NONE,
                                              command->_ptrDoc,
                                              NULL,
                                              &command->error)) {

                    // TODO: throw an approriate exception

                }

                return 1;
            }

            int MongoDbSourceDriver::SaveEntity(std::shared_ptr<Entity> &entity,
                                                const EntityMap &entityMap) const {
                return 1;
            }

            int MongoDbSourceDriver::DeleteEntity(std::shared_ptr<Entity> &entity,
                                                  const EntityMap &entityMap) const {
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


