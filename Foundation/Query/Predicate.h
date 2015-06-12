//
// Created by LE, Duc Anh on 6/9/15.
//

#ifndef CLOUD_E_CPLUS_FOUNDATION_QUERY_PREDICATE_H
#define CLOUD_E_CPLUS_FOUNDATION_QUERY_PREDICATE_H

#include <Foundation/Column.h>
#include <Foundation/Type/cldeValue.h>
#include <Foundation/Query/Enumeration/ComparativeType.h>
#include <Foundation/Query/Contract/IPredicationFormatter.h>

namespace Cloude {
    namespace Foundation {
        namespace Query {
            class Predicate {
            public:
                Predicate() = default;
                virtual ~Predicate() = default;
                Predicate(const Predicate &srcExpression) = default;
                Predicate &operator=(const Predicate &srcExpression) = default;

                virtual const Column &getColumn() const = 0;
                virtual const Enumeration::ComparativeType &getType() const = 0;
                virtual const Type::cldeValue &getValue() const = 0;

                virtual const bool isComposite() const { return false; }
                virtual const std::string CopyToString(const Contract::IPredicationFormatter &formatter) const {
                    return formatter.CopyFormat(*this);
                };
            };
        }
    }
}


#endif //CLOUD_E_CPLUS_FOUNDATION_QUERY_PREDICATE_H
