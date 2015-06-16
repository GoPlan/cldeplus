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

            public:
                CriteriaLeaf(const SPtrColumn &column, const Type::SPtrCldeValue &value)
                        : _column(column), _value(value) { };
                virtual ~CriteriaLeaf() = default;
                CriteriaLeaf(const CriteriaLeaf &rhs) = default;
                CriteriaLeaf &operator=(const CriteriaLeaf &rhs) = default;

                // Criteria
                virtual const bool isComposite() const override;
                virtual const SPtrColumn &getColumn() const override;
                virtual const Type::SPtrCldeValue &getValue() const override;

            private:
                const SPtrColumn &_column;
                const Type::SPtrCldeValue &_value;
            };
        }
    }
}


#endif //CLOUD_E_CPLUS_FOUNDATION_QUERY_CRITERIALEAF_H
