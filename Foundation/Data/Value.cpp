//
// Created by LE, Duc Anh on 6/9/15.
//

#include <Foundation/Exception/cldeNonSupportedFunctionException.h>
#include "Value.h"


namespace Cloude {
    namespace Foundation {
        namespace Data {

            Value::Value(ValueType dataType, size_t length)
                    : _dataType(dataType), _length(length) {
                //
            }

            bool Value::Equal(const Common::IEquatable &rhs) const {
                std::string msg{"IEquatable::Equal() function is not yet supported"};
                throw Exception::cldeNonSupportedFunctionException{msg};
            }
        }
    }
}

