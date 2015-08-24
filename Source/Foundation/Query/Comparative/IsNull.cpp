//
// Created by LE, Duc Anh on 6/9/15.
//

#include "IsNull.h"

namespace Cloude {
    namespace Foundation {
        namespace Query {
            namespace Comparative {

                ComparativeType IsNull::_type = ComparativeType::IsNull;

                const ComparativeType &IsNull::getComparativeType() const {
                    return _type;
                }

                const SPtrColumn &IsNull::getColumn() const {
                    return _column;
                }

                const bool IsNull::isComposite() const {
                    return false;
                }

                const Data::SPtrValue &IsNull::getValue() const {
                    const char *msg = "IsNull comparator does not support getValue() method.";
                    throw Exception::CLDENonSupportedFunctionException(msg);
                }
            }
        }
    }
}


