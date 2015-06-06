//
// Created by LE, Duc Anh on 6/5/15.
//

#include "MongoDbSourceException.h"

namespace Cloude {
    namespace Infrastructure {
        namespace MongoDb {

            const char *MongoDbSourceException::what() const noexcept {
                return message.c_str();
            }
        }
    }
}


