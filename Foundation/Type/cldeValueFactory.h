//
// Created by LE, Duc Anh on 6/10/15.
//

#ifndef CLOUD_E_CPLUS_FOUNDATION_TYPE_CLDEVALUEFACTORY_H
#define CLOUD_E_CPLUS_FOUNDATION_TYPE_CLDEVALUEFACTORY_H

#include <memory>
#include "cldeValue.h"

namespace Cloude {
    namespace Foundation {
        namespace Type {

            class cldeValueFactory {

            public:
                cldeValueFactory() = delete;
                cldeValueFactory(const cldeValueFactory &) = delete;
                cldeValueFactory(cldeValueFactory &&) = delete;
                cldeValueFactory &operator=(const cldeValueFactory &) = delete;
                cldeValueFactory &operator=(cldeValueFactory &&) = delete;
                ~cldeValueFactory() = delete;

                static SPtrCldeValue CreateDouble(double value);
                static SPtrCldeValue CreateInt32(int32_t value);
                static SPtrCldeValue CreateInt64(int64_t value);
                static SPtrCldeValue CreateString(const char *value);
                static SPtrCldeValue CreateVarChar(const char *value);
                static SPtrCldeValue CreateVarChar(const std::string &value);
                static SPtrCldeValue CreateVarChar(unsigned long length);
            };
        }
    }
}


#endif //CLOUD_E_CPLUS_FOUNDATION_TYPE_CLDEVALUEFACTORY_H
