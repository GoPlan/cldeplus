//
// Created by LE, Duc Anh on 6/9/15.
//

#include "IsNull.h"

namespace Cloude {
    namespace Foundation {
        namespace Query {
            namespace Comparative {

                Enumeration::ComparativeType IsNull::_type = Enumeration::ComparativeType::IsNull;

                const Enumeration::ComparativeType &IsNull::getType() const {
                    return _type;
                }
                const Column &IsNull::getColumn() const {
                    return _column;
                }
                const bool IsNull::isComposite() const {
                    return false;
                }

                const Type::cldeValue &IsNull::getValue() const {
                    const char *msg = "IsNull comparator does not support getValue() method.";
                    throw Exception::cldeNonSupportedFunctionException(msg);
                }
            }
        }
    }
}


