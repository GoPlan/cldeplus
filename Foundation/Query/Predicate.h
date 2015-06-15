//
// Created by LE, Duc Anh on 6/9/15.
//

#ifndef CLOUD_E_CPLUS_FOUNDATION_QUERY_PREDICATE_H
#define CLOUD_E_CPLUS_FOUNDATION_QUERY_PREDICATE_H

#include <memory>
#include <iterator>
#include <Foundation/Column.h>
#include <Foundation/Type/cldeValue.h>
#include <Foundation/Query/Enumeration/ComparativeType.h>

namespace Cloude {
    namespace Foundation {
        namespace Query {

            class Predicate;

            using SPtrPredicate = std::shared_ptr<Predicate>;
            using WPtrPredicate = std::weak_ptr<Predicate>;

            class Predicate : public std::enable_shared_from_this<Predicate> {

            public:
                Predicate() = default;
                virtual ~Predicate() = default;
                Predicate(const Predicate &srcExpression) = default;
                Predicate &operator=(const Predicate &srcExpression) = default;

                virtual const bool isComposite() const = 0;
                virtual const Column &getColumn() const = 0;
                virtual const Enumeration::ComparativeType &getComparativeType() const = 0;
                virtual const Type::SPtrCldeValue &getValue() const = 0;
            };
        }
    }
}


#endif //CLOUD_E_CPLUS_FOUNDATION_QUERY_PREDICATE_H
