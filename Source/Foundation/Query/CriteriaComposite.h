//
// Created by LE, Duc Anh on 6/13/15.
//

#ifndef CLOUD_E_CPLUS_FOUNDATION_QUERY_CRITERIACOMPOSITE_H
#define CLOUD_E_CPLUS_FOUNDATION_QUERY_CRITERIACOMPOSITE_H

#include <Foundation/Exception/cldeNonSupportedFunctionException.h>
#include "Criteria.h"

namespace Cloude {
    namespace Foundation {
        namespace Query {

            class CriteriaComposite : public Criteria {
                SPtrCriteria _sptrRhs;
                SPtrCriteria _sptrLhs;

            public:
                CriteriaComposite(const SPtrCriteria &lhs, const SPtrCriteria &rhs)
                        : _sptrLhs(lhs), _sptrRhs(rhs) { };

                CriteriaComposite(const CriteriaComposite &) = default;
                CriteriaComposite(CriteriaComposite &&) = default;
                CriteriaComposite &operator=(const CriteriaComposite &) = default;
                CriteriaComposite &operator=(CriteriaComposite &&) = default;
                virtual ~CriteriaComposite() = default;

                // Criteria
                virtual const bool isComposite() const override { return true; };
                virtual const ComparativeType &getComparativeType() const override;
                virtual const SPtrColumn &getColumn() const override;
                virtual const Data::SPtrValue &getValue() const override;

                // Locals
                const SPtrCriteria &getRhs() const { return _sptrRhs; }
                const SPtrCriteria &getLhs() const { return _sptrLhs; }
            };
        }
    }
}


#endif //CLOUD_E_CPLUS_FOUNDATION_QUERY_CRITERIACOMPOSITE_H
