//
// Created by LE, Duc Anh on 6/13/15.
//

#include "PredicateIterator.h"
#include "PredicateComposite.h"
#include "PredicateSentinel.h"

namespace Cloude {
    namespace Foundation {
        namespace Query{

            SPtrPredicateIterator PredicateIterator::operator++() {

                if (_sptrPredicate->isComposite()) {

//                    auto composite = dynamic_cast<const PredicateComposite &>(_sptrPredicate);

                    // Check left
                    if (!_finishedLeft) {
                        _finishedLeft = true;
                        SPtrPredicateIterator parent(this);
                        SPtrPredicateIterator next;
                        next->setParent(parent);
                        return next;
                    }

                    // Check right
                    if (!_finishedRight) {
                        _finishedRight = true;
                        SPtrPredicateIterator parent(this);
                        SPtrPredicateIterator next;
                        next->setParent(parent);
                        return next;
                    }

                    auto SPtrParent = _parent.lock();
                    return (SPtrParent) ? SPtrParent : SPtrParent;

                } else {

                    auto SPtrParent = _parent.lock();
                    return (SPtrParent) ? SPtrParent : SPtrParent;

                }
            }
        }
    }
}




