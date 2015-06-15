//
// Created by LE, Duc Anh on 6/9/15.
//

#include "IsNotNull.h"

namespace Cloude {
    namespace Foundation {
        namespace Query {
            namespace Comparative {

                Enumeration::ComparativeType IsNotNull::_type = Enumeration::ComparativeType::IsNotNull;

                const Enumeration::ComparativeType &IsNotNull::getComparativeType() const {
                    return _type;
                }
                const SPtrColumn &IsNotNull::getColumn() const {
                    return _column;
                }
                const bool IsNotNull::isComposite() const {
                    return false;
                }
                const Type::SPtrCldeValue &IsNotNull::getValue() const {
                    const char *msg = "IsNotNull comparator does not support getValue() method.";
                    throw Exception::cldeNonSupportedFunctionException(msg);
                }
            }
        }
    }
}


