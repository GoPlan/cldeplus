//
// Created by LE, Duc Anh on 6/5/15.
//

#ifndef CLOUD_E_CPLUS_MONGODBSOURCEEXCEPTION_H
#define CLOUD_E_CPLUS_MONGODBSOURCEEXCEPTION_H

#include <exception>
#include <string>

namespace Cloude {
    namespace SourceDriver {
        namespace MongoDb {
            class MongoDbSourceException : public std::exception {
            public:
                MongoDbSourceException() = default;
                virtual ~MongoDbSourceException() = default;
                MongoDbSourceException(const MongoDbSourceException &srcMongoDbSourceException) = default;
                MongoDbSourceException &operator=(const MongoDbSourceException &srcMongoDbSourceException) = default;

                const char *what() const noexcept override;

                void setMessage(std::string &message) {
                    this->message = message;
                }

            private:
                std::string message;

            };
        }
    }
}


#endif //CLOUD_E_CPLUS_MONGODBSOURCEEXCEPTION_H
