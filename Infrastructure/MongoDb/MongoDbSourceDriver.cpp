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
                };

                ~Command() {

                    if (_ptrQuery) {
                        bson_destroy(_ptrQuery);
                    }
                }

                bson_t *_ptrQuery = nullptr;
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

                    connStr += optionArgs.User + ":" + optionArgs.Pass;
                    connStr += "@";
                    connStr += optionArgs.Host;
                    connStr += optionArgs.Port;

                    return connStr;
                }

                mongoc_client_t *_ptrClient = nullptr;
                mongoc_collection_t *_ptrCollection = nullptr;

            private:
                //
            };


            MongoDbSourceDriver::MongoDbSourceDriver(Architecture::EntityMap &entityMap)
                    : EntitySourceDriver(entityMap) {
                //
            }

            int MongoDbSourceDriver::LoadEntity(std::shared_ptr<Entity> &entity,
                                                const EntityMap &entityMap) const {
                return 0;
            }

            int MongoDbSourceDriver::CreateEntity(std::shared_ptr<Entity> &entity,
                                                  const EntityMap &entityMap) const {
                return 0;
            }

            int MongoDbSourceDriver::SaveEntity(std::shared_ptr<Entity> &entity,
                                                const EntityMap &entityMap) const {
                return 0;
            }

            int MongoDbSourceDriver::DeleteEntity(std::shared_ptr<Entity> &entity,
                                                  const EntityMap &entityMap) const {
                return 0;
            }

            void MongoDbSourceDriver::Connect() {

                std::string uriString = _mongoDbApiImpl->parseConnectionString(OptionArgs);
                _mongoDbApiImpl->_ptrClient = mongoc_client_new(uriString.c_str());
                _mongoDbApiImpl->_ptrCollection = mongoc_client_get_collection(_mongoDbApiImpl->_ptrClient,
                                                                               OptionArgs.Base.c_str(),
                                                                               _entityMap.TableName().c_str());
            }

            void MongoDbSourceDriver::Disconnect() {

            }

            void MongoDbSourceDriver::init() {

            }
        }
    }
}


