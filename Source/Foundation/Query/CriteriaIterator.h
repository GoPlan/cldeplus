//
// Created by LE, Duc Anh on 6/13/15.
//

#ifndef CLOUD_E_CPLUS_FOUNDATION_QUERY_CRITERIAITERATOR_H
#define CLOUD_E_CPLUS_FOUNDATION_QUERY_CRITERIAITERATOR_H

#include <memory>
#include <iterator>
#include "Criteria.h"

namespace CLDEPlus {
    namespace Foundation {
        namespace Query {

            class CriteriaIterator;

            using SPtrCriteriaIterator = shared_ptr<CriteriaIterator>;
            using WPtrCriteriaIterator = std::weak_ptr<CriteriaIterator>;

            class CriteriaIterator : public std::enable_shared_from_this<CriteriaIterator> {
                bool _finishedLeft = false;
                bool _finishedRight = false;
                bool _isVisited = false;
                SPtrCriteria _sptrCriteria;
                SPtrCriteriaIterator _parent;

            public:
                CriteriaIterator(const SPtrCriteria &sptrCriteria) : _sptrCriteria(sptrCriteria) { };
                CriteriaIterator(const CriteriaIterator &rhs) : _sptrCriteria(rhs._sptrCriteria) { };
                SPtrCriteriaIterator operator++();

                const SPtrCriteria &getPredicate() const { return _sptrCriteria; };
                bool isVisited() const { return _isVisited; }
                bool isLeaf() const { return !getPredicate()->isComposite(); }
            };
        }
    }
}


#endif //CLOUD_E_CPLUS_FOUNDATION_QUERY_CRITERIAITERATOR_H
