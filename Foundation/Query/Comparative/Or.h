//
// Created by LE, Duc Anh on 6/9/15.
//

#ifndef CLOUD_E_CPLUS_OR_H
#define CLOUD_E_CPLUS_OR_H

#include <Foundation/Exception/cldeNonSupportedFunctionException.h>
#include <Foundation/Query/Predicate.h>

namespace Cloude {
    namespace Foundation {
        namespace Query {
            namespace Comparative {
                class Or : public Query::Predicate {
                public:
                    Or(const Predicate &lhs, const Predicate &rhs) : _lhs(lhs), _rhs(rhs) { };
                    ~Or() = default;
                    Or(const Or &rhs) = default;
                    Or &operator=(const Or &rhs) = default;

                    // Predicate
                    virtual const Column &getColumn() const override;
                    const Enumeration::ComparativeType &getType() const override { return _type; };
                    const bool isComposite() const override { return true; }
                    const Type::cldeValue &getValue() const override {
                        const char *msg = "OR comparator does not support getValue() method.";
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


#endif //CLOUD_E_CPLUS_OR_H
