//
// Created by LE, Duc Anh on 6/5/15.
//

#ifndef CLOUD_E_CPLUS_MONGODBSOURCEDRIVER_H
#define CLOUD_E_CPLUS_MONGODBSOURCEDRIVER_H

#include <memory>
#include <string>
#include <Foundation/EntitySourceDriver.h>
#include "MongoDbSourceException.h"

namespace Cloude {
    namespace SourceDriver {
        namespace MongoDb {

            class MongoDbSourceDriver : public Foundation::EntitySourceDriver {
            public:
                using QueryExpression = Foundation::Query::Expression;
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

                explicit MongoDbSourceDriver(EntityMap &entityMap);

                int Load(std::shared_ptr<Entity> &entity) const override;
                int Insert(std::shared_ptr<Entity> &entity) const override;
                int Save(std::shared_ptr<Entity> &entity) const override;
                int Delete(std::shared_ptr<Entity> &entity) const override;

                std::vector<Foundation::EntityProxy> Select(std::shared_ptr<QueryExpression> &expr) const override;

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
