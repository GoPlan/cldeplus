//
// Created by LE, Duc Anh on 6/5/15.
//

#ifndef CLOUD_E_CPLUS_MONGODBSOURCEDRIVER_H
#define CLOUD_E_CPLUS_MONGODBSOURCEDRIVER_H

#include <memory>
#include <string>
#include <Framework/EntitySourceDriver.h>

namespace Cloude {
    namespace SourceDriver {
        namespace MongoDb {

            class MongoDbSourceDriver : public Framework::EntitySourceDriver {
            public:
                using Column = Framework::Column;
                using DbType = Framework::Enumeration::DbType;
                using Field = Framework::Field;
                using EntitySourceDriver = Framework::EntitySourceDriver;
                using Entity = Framework::Entity;
                using EntityMap = Framework::EntityMap;
                using Options = struct {
                    std::string Host;
                    std::string User;
                    std::string Pass;
                    std::string Base;
                    unsigned int Port = 27017;
                };

            public:
                MongoDbSourceDriver() = default;
                virtual ~MongoDbSourceDriver() = default;
                MongoDbSourceDriver(const MongoDbSourceDriver &srcMongoDbSourceDriver) = default;
                MongoDbSourceDriver &operator=(const MongoDbSourceDriver &srcMongoDbSourceDriver) = default;

                explicit MongoDbSourceDriver(Framework::EntityMap &entityMap);
                int LoadEntity(std::shared_ptr<Entity> &entity) const override;
                int CreateEntity(std::shared_ptr<Entity> &entity) const override;
                int SaveEntity(std::shared_ptr<Entity> &entity) const override;
                int DeleteEntity(std::shared_ptr<Entity> &entity) const override;

                void Connect();
                void Disconnect();

                Options &getOptionArgs() {
                    return _optionArgs;
                }

            private:
                class MongoDbApiImpl;

                Options _optionArgs;
                std::shared_ptr<MongoDbApiImpl> _mongoDbApiImpl;
                std::string _getStatement;
                std::string _insertStatement;
                std::string _updateStatement;
                std::string _deleteStatement;
                bool _isConnected = false;

            private:
                void init();
            };
        }
    }
}


#endif //CLOUD_E_CPLUS_MONGODBSOURCEDRIVER_H
