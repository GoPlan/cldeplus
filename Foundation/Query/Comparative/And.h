//
// Created by LE, Duc Anh on 6/9/15.
//

#ifndef CLOUD_E_CPLUS_AND_H
#define CLOUD_E_CPLUS_AND_H

#include <Foundation/Exception/cldeNonSupportedFunctionException.h>
#include <Foundation/Query/Predicate.h>

namespace Cloude {
    namespace Foundation {
        namespace Query {
            namespace Comparative {
                class And : public Query::Predicate {
                public:
                    And(const Query::Predicate &lhs, const Query::Predicate &rhs) : _lhs(lhs), _rhs(rhs) { };
                    ~And() = default;
                    And(const And &rhs) = default;
                    And &operator=(const And &rhs) = default;

                    // Predicate
                    const Enumeration::ComparativeType &getType() const override { return _type; };
                    const bool isComposite() const override { return true; }
                    const Type::cldeValue &getValue() const override {
                        const char *msg = "AND comparator does not support getValue() method.";
                        throw Exception::cldeNonSupportedFunctionException(msg);
                    };

                    // Locals
                    const Predicate &getLhs() const { return _lhs; };
                    const Predicate &getRhs() const { return _rhs; };

                private:
                    const Query::Predicate &_lhs;
                    const Query::Predicate &_rhs;
                    static Enumeration::ComparativeType _type;
                };
            }
        }
    }
}


#endif //CLOUD_E_CPLUS_AND_H
