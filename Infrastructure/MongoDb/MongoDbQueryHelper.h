//
// Created by LE, Duc Anh on 6/6/15.
//

#ifndef CLOUD_E_CPLUS_MONGODBQUERYHELPER_H
#define CLOUD_E_CPLUS_MONGODBQUERYHELPER_H

namespace Cloude {
    namespace Infrastructure {
        namespace MongoDb {
            class MongoDbQueryHelper {
            public:
                MongoDbQueryHelper() = default;
                virtual ~MongoDbQueryHelper() = default;
                MongoDbQueryHelper(const MongoDbQueryHelper &srcMongoDbQueryHelper) = default;
                MongoDbQueryHelper &operator=(const MongoDbQueryHelper &srcMongoDbQueryHelper) = default;

            };
        }
    }
}

#endif //CLOUD_E_CPLUS_MONGODBQUERYHELPER_H
