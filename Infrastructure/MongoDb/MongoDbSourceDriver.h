//
// Created by LE, Duc Anh on 6/5/15.
//

#ifndef CLOUD_E_CPLUS_MONGODBSOURCEDRIVER_H
#define CLOUD_E_CPLUS_MONGODBSOURCEDRIVER_H

#include <memory>
#include <string>
#include <Architecture/EntitySourceDriver.h>

namespace Cloude {
    namespace Infrastructure {
        namespace MongoDb {

            using EntitySourceDriver = Architecture::EntitySourceDriver;
            using Entity = Architecture::Entity;
            using EntityMap = Architecture::EntityMap;

            class MongoDbSourceDriver : public EntitySourceDriver {
            public:
                MongoDbSourceDriver() = default;
                virtual ~MongoDbSourceDriver() = default;
                MongoDbSourceDriver(const MongoDbSourceDriver &srcMongoDbSourceDriver) = default;
                MongoDbSourceDriver &operator=(const MongoDbSourceDriver &srcMongoDbSourceDriver) = default;

                explicit MongoDbSourceDriver(Architecture::EntityMap &entityMap);
                int LoadEntity(std::shared_ptr<Entity> &entity, const EntityMap &entityMap) const override;
                int CreateEntity(std::shared_ptr<Entity> &entity, const EntityMap &entityMap) const override;
                int SaveEntity(std::shared_ptr<Entity> &entity, const EntityMap &entityMap) const override;
                int DeleteEntity(std::shared_ptr<Entity> &entity, const EntityMap &entityMap) const override;

                void Connect();
                void Disconnect();

            private:
                class MongoDbApiImpl;

                std::shared_ptr<MongoDbApiImpl> _mongoDbApiImpl;

                std::string _getStatement;
                std::string _insertStatement;
                std::string _updateStatement;
                std::string _deleteStatement;

                bool _isConnected = false;

                void init();
            };
        }
    }
}


#endif //CLOUD_E_CPLUS_MONGODBSOURCEDRIVER_H
