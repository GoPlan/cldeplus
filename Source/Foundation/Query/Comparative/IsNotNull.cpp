//
// Created by LE, Duc Anh on 6/9/15.
//

#include "IsNotNull.h"
#include "../../Exception/CLDENonSupportedFunctionException.h"

namespace CLDEPlus {
    namespace Foundation {
        namespace Query {
            namespace Comparative {

                ComparativeType IsNotNull::_type = ComparativeType::IsNotNull;

                const ComparativeType &IsNotNull::getComparativeType() const {
                    return _type;
                }
                const SPtrColumn &IsNotNull::getColumn() const {
                    return _column;
                }
                const bool IsNotNull::isComposite() const {
                    return false;
                }
                const Data::SPtrValue &IsNotNull::getValue() const {
                    string msg{"IsNotNull comparator does not support getValue() method."};
                    throw Exception::CLDENonSupportedFunctionException(msg);
                }
            }
        }
    }
}


