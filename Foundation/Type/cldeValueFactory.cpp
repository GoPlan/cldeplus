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

            std::shared_ptr<cldeValue> cldeValueFactory::CreateDouble(double value) {
                auto spValue = std::make_shared<Implementation::cldeDouble>(value);
                return spValue;
            }

            std::shared_ptr<cldeValue> cldeValueFactory::CreateInt32(int32_t value) {
                auto spValue = std::make_shared<Implementation::cldeInt32>(value);
                return spValue;
            }

            std::shared_ptr<cldeValue> cldeValueFactory::CreateInt64(int64_t value) {
                auto spValue = std::make_shared<Implementation::cldeInt64>(value);
                return spValue;
            }

            std::shared_ptr<cldeValue> cldeValueFactory::CreateString(const char *value) {
                auto spValue = std::make_shared<Implementation::cldeString>(value);
                return spValue;
            }

            std::shared_ptr<cldeValue> cldeValueFactory::CreateVarchar(const char *value) {
                auto spValue = std::make_shared<Implementation::cldeVarchar>(value);
                return spValue;
            }

            std::shared_ptr<cldeValue> cldeValueFactory::CreateVarchar(unsigned long length) {
                auto spValue = std::make_shared<Implementation::cldeVarchar>(length);
                return spValue;
            }
        }
    }
}


