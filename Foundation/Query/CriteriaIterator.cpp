//
// Created by LE, Duc Anh on 6/13/15.
//

#include "CriteriaIterator.h"
#include "CriteriaComposite.h"

namespace Cloude {
    namespace Foundation {
        namespace Query {

            SPtrCriteriaIterator CriteriaIterator::operator++() {

                _isVisited = true;

                if (_sptrCriteria->isComposite()) {

                    auto sptrComposite = std::dynamic_pointer_cast<CriteriaComposite>(_sptrCriteria);

                    // Check left
                    if (!_finishedLeft) {
                        _finishedLeft = true;
                        SPtrCriteriaIterator next(new CriteriaIterator(sptrComposite->getLhs()));
                        next->_parent = shared_from_this();
                        return next;
                    }

                    // Check right
                    if (!_finishedRight) {
                        _finishedRight = true;
                        SPtrCriteriaIterator next(new CriteriaIterator(sptrComposite->getRhs()));
                        next->_parent = shared_from_this();
                        return next;
                    }

                    return (_parent) ? _parent : SPtrCriteriaIterator(nullptr);

                } else {

                    return (_parent) ? _parent : SPtrCriteriaIterator(nullptr);

                }
            }
        }
    }
}




