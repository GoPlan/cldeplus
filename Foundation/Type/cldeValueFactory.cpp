//
// Created by LE, Duc Anh on 6/10/15.
//

#include "cldeValueFactory.h"
#include <Foundation/Type/Implementation/cldeInt32.h>
#include <Foundation/Type/Implementation/cldeInt64.h>
#include <Foundation/Type/Implementation/cldeString.h>
#include <Foundation/Type/Implementation/cldeVarChar.h>
#include <Foundation/Type/Implementation/cldeDouble.h>

namespace Cloude {
    namespace Foundation {
        namespace Type {

            SPtrCldeValue cldeValueFactory::CreateDouble(double value) {
                auto spValue = std::make_shared<Implementation::cldeDouble>(value);
                return spValue;
            }

            SPtrCldeValue cldeValueFactory::CreateInt32(int32_t value) {
                auto spValue = std::make_shared<Implementation::cldeInt32>(value);
                return spValue;
            }

            SPtrCldeValue cldeValueFactory::CreateInt64(int64_t value) {
                auto spValue = std::make_shared<Implementation::cldeInt64>(value);
                return spValue;
            }

            SPtrCldeValue cldeValueFactory::CreateString(const char *value) {
                auto spValue = std::make_shared<Implementation::cldeString>(value);
                return spValue;
            }

            SPtrCldeValue cldeValueFactory::CreateVarChar(const char *value) {
                auto spValue = std::make_shared<Implementation::cldeVarChar>(value);
                return spValue;
            }

            SPtrCldeValue cldeValueFactory::CreateVarChar(const std::string &value) {
                auto spValue = std::make_shared<Implementation::cldeVarChar>(value.c_str());
                return spValue;
            }

            SPtrCldeValue cldeValueFactory::CreateVarChar(unsigned long length) {
                auto spValue = std::make_shared<Implementation::cldeVarChar>(length);
                return spValue;
            }
        }
    }
}


