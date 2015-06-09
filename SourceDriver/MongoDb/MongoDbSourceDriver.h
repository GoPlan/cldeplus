//
// Created by LE, Duc Anh on 6/5/15.
//

#ifndef CLOUD_E_CPLUS_MONGODBSOURCEDRIVER_H
#define CLOUD_E_CPLUS_MONGODBSOURCEDRIVER_H

#include <memory>
#include <string>
#include <Foundation/EntitySourceDriver.h>

namespace Cloude {
    namespace SourceDriver {
        namespace MongoDb {

            class MongoDbSourceDriver : public Foundation::EntitySourceDriver {
            public:
                using Column = Foundation::Column;
                using DbType = Foundation::Enumeration::DbType;
                using Field = Foundation::Field;
                using EntitySourceDriver = Foundation::EntitySourceDriver;
                using Entity = Foundation::Entity;
                using EntityMap = Foundation::EntityMap;
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

                explicit MongoDbSourceDriver(Foundation::EntityMap &entityMap);
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
