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
