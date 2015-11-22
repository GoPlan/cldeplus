/*

Copyright 2015 LE, Duc-Anh

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.

*/

#include "CriteriaIterator.h"
#include "CriteriaComposite.h"

namespace CLDEPlus {
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




