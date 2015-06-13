//
// Created by LE, Duc Anh on 6/13/15.
//

#include "PredicateIterator.h"
#include "PredicateComposite.h"
#include "PredicateSentinel.h"

namespace Cloude {
    namespace Foundation {
        namespace Query {

            SPtrPredicateIterator PredicateIterator::operator++() {

                if (_sptrPredicate->isComposite()) {

                    auto composite = std::dynamic_pointer_cast<PredicateComposite>(_sptrPredicate);

                    // Check left
                    if (!isFinishedLeft()) {
                        setFinishedLeft(true);
                        SPtrPredicateIterator parent(this);
                        SPtrPredicateIterator next(new PredicateIterator(composite->getLhs()));
                        next->setParent(parent);
                        return next;
                    }

                    // Check right
                    if (!isFinishedRight()) {
                        setFinishedRight(true);
                        SPtrPredicateIterator parent(this);
                        SPtrPredicateIterator next(new PredicateIterator(composite->getRhs()));
                        next->setParent(parent);
                        return next;
                    }

                    // Check whether iterator has parent, if it does not, it is the root
                    auto sptrParent = _parent.lock();
                    return (sptrParent) ? sptrParent : SPtrPredicateIterator(nullptr);

                } else {

                    // Check whether iterator has parent, if it does not, it is the root
                    auto sptrParent = _parent.lock();
                    return (sptrParent) ? sptrParent : SPtrPredicateIterator(nullptr);

                }
            }

            SPtrPredicate &PredicateIterator::operator->() {
                return _sptrPredicate;
            }
        }
    }
}




