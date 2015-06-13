//
// Created by LE, Duc Anh on 6/13/15.
//

#ifndef CLOUD_E_CPLUS_PREDICATEITERATOR_H
#define CLOUD_E_CPLUS_PREDICATEITERATOR_H

#include <iterator>
#include "Predicate.h"

namespace Cloude {
    namespace Foundation {
        namespace Query {

            class PredicateIterator;

            using SPtrPredicateIterator = std::shared_ptr<PredicateIterator>;
            using WPtrPredicateIterator = std::weak_ptr<PredicateIterator>;

            class PredicateIterator : public std::iterator<std::output_iterator_tag, Predicate> {

            public:
                PredicateIterator(SPtrPredicate &predicate) : _sptrPredicate(predicate) { };
                PredicateIterator(const PredicateIterator &rhs) : _sptrPredicate(rhs._sptrPredicate) { };
                SPtrPredicateIterator operator++();

                bool isFinishedLeft() const {
                    return _finishedLeft;
                }
                void setFinishedLeft(bool finishedLeft) {
                    PredicateIterator::_finishedLeft = finishedLeft;
                }
                bool isFinishedRight() const {
                    return _finishedRight;
                }
                void setFinishedRight(bool finishedRight) {
                    PredicateIterator::_finishedRight = finishedRight;
                }
                const WPtrPredicateIterator&getParent() const {
                    return _parent;
                }
                void setParent(const WPtrPredicateIterator &parent) {
                    _parent = parent;
                }

            private:
                bool _finishedLeft;
                bool _finishedRight;
                SPtrPredicate _sptrPredicate;
                WPtrPredicateIterator _parent;
            };
        }
    }
}


#endif //CLOUD_E_CPLUS_PREDICATEITERATOR_H
