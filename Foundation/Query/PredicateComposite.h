//
// Created by LE, Duc Anh on 6/13/15.
//

#ifndef CLOUD_E_CPLUS_PREDICATECOMPOSITE_H
#define CLOUD_E_CPLUS_PREDICATECOMPOSITE_H

#include <Foundation/Exception/cldeNonSupportedFunctionException.h>
#include "Predicate.h"

namespace Cloude {
    namespace Foundation {
        namespace Query {

            class PredicateComposite : public Predicate {

            public:
                PredicateComposite(const SPtrPredicate &lhs, const SPtrPredicate &rhs)
                        : _sptrLhs(lhs), _sptrRhs(rhs) { };

                virtual ~PredicateComposite() = default;
                PredicateComposite(const PredicateComposite &rhs) = default;
                PredicateComposite &operator=(const PredicateComposite &rhs) = default;

                // Predicate
                virtual const bool isComposite()
                const override {
                    return true;
                };
                virtual const Enumeration::ComparativeType &getComparativeType() const override {
                    const char *msg = "Composite compartive does not support getComparativeType()";
                    throw
                            Exception::cldeNonSupportedFunctionException(msg);
                };
                virtual const Column &getColumn()
                const override {
                    const char *msg = "Composite compartive does not support getColumn()";
                    throw
                            Exception::cldeNonSupportedFunctionException(msg);
                };
                virtual const Type::SPtrCldeValue &getValue()
                const override {
                    const char *msg = "Composite comparator does not support getValue() method.";
                    throw
                            Exception::cldeNonSupportedFunctionException(msg);
                };

                // Locals
                const SPtrPredicate &getRhs() const { return _sptrRhs; }
                const SPtrPredicate &getLhs() const { return _sptrLhs; }

            protected:
                SPtrPredicate _sptrRhs;
                SPtrPredicate _sptrLhs;
            };
        }
    }
}


#endif //CLOUD_E_CPLUS_PREDICATECOMPOSITE_H
