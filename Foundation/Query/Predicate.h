//
// Created by LE, Duc Anh on 6/9/15.
//

#ifndef CLOUD_E_CPLUS_FOUNDATION_QUERY_PREDICATE_H
#define CLOUD_E_CPLUS_FOUNDATION_QUERY_PREDICATE_H

#include <iterator>
#include <Foundation/Column.h>
#include <Foundation/Type/cldeValue.h>
#include <Foundation/Query/Enumeration/ComparativeType.h>
#include <Foundation/Query/Contract/IPredicationFormatter.h>

namespace Cloude {
    namespace Foundation {
        namespace Query {

            using SPtrPredicate = std::shared_ptr<Predicate>;
            using WPtrPredicate = std::weak_ptr<Predicate>;

            class Predicate {

            public:
                Predicate() = default;
                virtual ~Predicate() = default;
                Predicate(const Predicate &srcExpression) = default;
                Predicate &operator=(const Predicate &srcExpression) = default;

                virtual const bool isComposite() const = 0;
                virtual const Column &getColumn() const = 0;
                virtual const Enumeration::ComparativeType &getComparativeType() const = 0;
                virtual const Type::SPtrCldeValue &getValue() const = 0;

                virtual const std::string CopyToString(const Contract::IPredicationFormatter &formatter) const {
                    return formatter.CopyFormat(*this);
                };
            };


        }
    }
}


#endif //CLOUD_E_CPLUS_FOUNDATION_QUERY_PREDICATE_H
