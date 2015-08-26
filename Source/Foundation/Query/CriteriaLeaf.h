//
// Created by LE, Duc Anh on 6/11/15.
//

#ifndef CLOUD_E_CPLUS_FOUNDATION_QUERY_CRITERIALEAF_H
#define CLOUD_E_CPLUS_FOUNDATION_QUERY_CRITERIALEAF_H

#include "Criteria.h"

namespace Cloude {
    namespace Foundation {
        namespace Query {

            class CriteriaLeaf : public Criteria {

                SPtrColumn _column;
                Data::SPtrValue _value;

            public:
                CriteriaLeaf(const SPtrColumn &column, const Data::SPtrValue &value)
                        : _column(column), _value(value) { };

                CriteriaLeaf(const CriteriaLeaf &) = default;
                CriteriaLeaf(CriteriaLeaf &&) = default;
                CriteriaLeaf &operator=(const CriteriaLeaf &) = default;
                CriteriaLeaf &operator=(CriteriaLeaf &&) = default;
                virtual ~CriteriaLeaf() = default;

                // Criteria
                virtual const bool isComposite() const override;
                virtual const SPtrColumn &getColumn() const override;
                virtual const Data::SPtrValue &getValue() const override;
            };
        }
    }
}


#endif //CLOUD_E_CPLUS_FOUNDATION_QUERY_CRITERIALEAF_H
