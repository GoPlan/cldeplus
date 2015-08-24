//
// Created by LE, Duc Anh on 6/26/15.
//

#ifndef CLOUD_E_PLUS_FOUNDATION_TYPE_COMPARER_GREATER_H
#define CLOUD_E_PLUS_FOUNDATION_TYPE_COMPARER_GREATER_H

#include "../Value.h"

namespace Cloude {
    namespace Foundation {
        namespace Data {
            namespace Comparer {

                class Greater : public std::binary_function<SPtrValue, SPtrValue, bool> {

                public:
                    Greater() = default;
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

#endif //CLOUD_E_PLUS_FOUNDATION_TYPE_COMPARER_GREATER_H
