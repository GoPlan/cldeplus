//
// Created by LE, Duc Anh on 6/26/15.
//

#ifndef CLOUD_E_PLUS_FOUNDATION_TYPE_COMPARER_CLDEVALUEGREATER_H
#define CLOUD_E_PLUS_FOUNDATION_TYPE_COMPARER_CLDEVALUEGREATER_H

#include <Foundation/Exception/cldeNonSupportedDataTypeException.h>
#include <Foundation/Type/cldeValue.h>

namespace Cloude {
    namespace Foundation {
        namespace Type {
            namespace Comparer {

                class cldeValueGreater : public std::binary_function<SPtrValue, SPtrValue, bool> {

                public:
                    cldeValueGreater() = default;
                    bool operator()(const SPtrValue &lhs, const SPtrValue &rhs) const;

                protected:
                    virtual bool CompareNumeric(const SPtrValue &lhs, const SPtrValue &rhs) const;
                    virtual bool CompareCharacterBased(const SPtrValue &lhs, const SPtrValue &rhs) const;
                    virtual bool CompareDateTime(const SPtrValue &lhs, const SPtrValue &rhs) const;
                    virtual bool CompareMathematic(const SPtrValue &lhs, const SPtrValue &rhs) const;
                };
            }
        }
    }
}

#endif //CLOUD_E_PLUS_FOUNDATION_TYPE_COMPARER_CLDEVALUEGREATER_H
