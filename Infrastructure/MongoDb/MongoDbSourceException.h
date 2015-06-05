//
// Created by LE, Duc Anh on 6/5/15.
//

#ifndef CLOUD_E_CPLUS_MONGODBSOURCEEXCEPTION_H
#define CLOUD_E_CPLUS_MONGODBSOURCEEXCEPTION_H

namespace Cloude {
    namespace Infrastructure {
        namespace MongoDb {
            class MongoDbSourceException {
            public:
                MongoDbSourceException() = default;
                virtual ~MongoDbSourceException() = default;
                MongoDbSourceException(const MongoDbSourceException &srcMongoDbSourceException) = default;
                MongoDbSourceException &operator=(const MongoDbSourceException &srcMongoDbSourceException) = default;

            };
        }
    }
}


#endif //CLOUD_E_CPLUS_MONGODBSOURCEEXCEPTION_H
