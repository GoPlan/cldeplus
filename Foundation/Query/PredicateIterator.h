//
// Created by LE, Duc Anh on 6/13/15.
//

#ifndef CLOUD_E_CPLUS_FOUNDATION_QUERY_PREDICATEITERATOR_H
#define CLOUD_E_CPLUS_FOUNDATION_QUERY_PREDICATEITERATOR_H

#include <memory>
#include <iterator>
#include "Predicate.h"

namespace Cloude {
    namespace Foundation {
        namespace Query {

            class PredicateIterator;

            using SPtrPredicateIterator = std::shared_ptr<PredicateIterator>;
            using WPtrPredicateIterator = std::weak_ptr<PredicateIterator>;

            class PredicateIterator : public std::enable_shared_from_this<PredicateIterator> {

            public:
                PredicateIterator(const SPtrPredicate &predicate) : _sptrPredicate(predicate) { };
                PredicateIterator(const PredicateIterator &rhs) : _sptrPredicate(rhs._sptrPredicate) { };
                SPtrPredicateIterator operator++();

                const SPtrPredicate &getPredicate() const { return _sptrPredicate; };
                bool isVisited() const { return _isVisited; }
                bool isLeaf() const { return !getPredicate()->isComposite(); }

            private:
                bool _finishedLeft = false;
                bool _finishedRight = false;
                bool _isVisited = false;
                SPtrPredicate _sptrPredicate;
                SPtrPredicateIterator _parent;
            };
        }
    }
}


#endif //CLOUD_E_CPLUS_FOUNDATION_QUERY_PREDICATEITERATOR_H
