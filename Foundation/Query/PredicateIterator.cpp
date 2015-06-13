//
// Created by LE, Duc Anh on 6/13/15.
//

#include "PredicateIterator.h"
#include "PredicateComposite.h"

namespace Cloude {
    namespace Foundation {
        namespace Query {

            SPtrPredicateIterator PredicateIterator::operator++() {

                _isVisited = true;

                if (_sptrPredicate->isComposite()) {

                    auto composite = std::dynamic_pointer_cast<PredicateComposite>(_sptrPredicate);

                    // Check left
                    if (!_finishedLeft) {
                        _finishedLeft = true;
                        SPtrPredicateIterator next(new PredicateIterator(composite->getLhs()));
                        next->_parent = shared_from_this();
                        return next;
                    }

                    // Check right
                    if (!_finishedRight) {
                        _finishedRight = true;
                        SPtrPredicateIterator next(new PredicateIterator(composite->getRhs()));
                        next->_parent = shared_from_this();
                        return next;
                    }

                    // Check whether iterator has parent, if it does not, it is the root
                    return (_parent) ? _parent : SPtrPredicateIterator(nullptr);

                } else {

                    // Check whether iterator has parent, if it does not, it is the root
                    return (_parent) ? _parent : SPtrPredicateIterator(nullptr);

                }
            }
        }
    }
}




