//
// Created by LE, Duc Anh on 6/5/15.
//

#ifndef CLOUD_E_CPLUS_SOURCEDRIVER_MONGODB_MONGODBSOURCEDRIVER_H
#define CLOUD_E_CPLUS_SOURCEDRIVER_MONGODB_MONGODBSOURCEDRIVER_H

#include <memory>
#include <string>
#include <Foundation/EntitySourceDriver.h>
#include "MongoDbSourceException.h"

namespace Cloude {
    namespace SourceDriver {
        namespace MongoDb {

            class MongoDbSourceDriver : public Foundation::EntitySourceDriver {

            public:
                using Options = struct {
                    string Host;
                    string User;
                    string Pass;
                    string Base;
                    unsigned int Port = 27017;
                };

            public:
                explicit MongoDbSourceDriver(const Foundation::EntityMap &entityMap);
                virtual ~MongoDbSourceDriver() = default;
                MongoDbSourceDriver(const MongoDbSourceDriver &srcMongoDbSourceDriver) = default;
                MongoDbSourceDriver &operator=(const MongoDbSourceDriver &srcMongoDbSourceDriver) = default;

                // Locals
                void Connect();
                void Disconnect();
                Options &getOptionArgs() { return _optionArgs; }

                // EntitySourceDriver
                int Load(shared_ptr<Foundation::Entity> &entity) const override;
                int Insert(shared_ptr<Foundation::Entity> &entity) const override;
                int Save(shared_ptr<Foundation::Entity> &entity) const override;
                int Delete(shared_ptr<Foundation::Entity> &entity) const override;
                SPtrProxySPtrVector Select(const SPtrPredicate &predicate,
                                           Foundation::EntityStore &entityStore) const override;
            private:
                class MongoDbApiImpl;

                Options _optionArgs;
                shared_ptr<MongoDbApiImpl> _mongoDbApiImpl;
                string _getStatement;
                string _insertStatement;
                string _updateStatement;
                string _deleteStatement;
                bool _isConnected = false;

            private:
                void Init();
            };
        }
    }
}


#endif //CLOUD_E_CPLUS_SOURCEDRIVER_MONGODB_MONGODBSOURCEDRIVER_H
