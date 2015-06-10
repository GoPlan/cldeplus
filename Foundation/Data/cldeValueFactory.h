//
// Created by LE, Duc Anh on 6/10/15.
//

#ifndef CLOUD_E_CPLUS_CLDEVALUEFACTORY_H
#define CLOUD_E_CPLUS_CLDEVALUEFACTORY_H

#include <memory>
#include "cldeValue.h"

namespace Cloude {
    namespace Foundation {
        namespace Data {
            class cldeValueFactory {
            public:
                cldeValueFactory() = delete;
                ~cldeValueFactory() = delete;
                cldeValueFactory(const cldeValueFactory &rhs) = delete;
                cldeValueFactory &operator=(const cldeValueFactory &rhs) = delete;

                static std::shared_ptr<cldeValue> CreateDouble(double value);
                static std::shared_ptr<cldeValue> CreateInt32(int32_t value);
                static std::shared_ptr<cldeValue> CreateInt64(int64_t value);
                static std::shared_ptr<cldeValue> CreateString(const char *value);
                static std::shared_ptr<cldeValue> CreateVarchar(const char *value);
            };
        }
    }
}


#endif //CLOUD_E_CPLUS_CLDEVALUEFACTORY_H
