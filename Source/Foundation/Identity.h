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

#ifndef CLOUD_E_CPLUS_FOUNDATION_IDENTITY_H
#define CLOUD_E_CPLUS_FOUNDATION_IDENTITY_H

#include "../Port/Definitions.h"
#include "Store/AbstractEntity.h"
#include "Cell.h"

namespace CLDEPlus {
    namespace Foundation {

        class Identity : public Store::AbstractEntity {

        public:
            explicit Identity(vector<SPtrCell> const &sptrCells);
            Identity() = default;
            Identity(Identity const &) = default;
            Identity(Identity &&) = default;
            Identity &operator=(Identity const &) = default;
            Identity &operator=(Identity &&) = default;
            ~Identity() = default;

            // Factory methods
            static unique_ptr<Identity> CreateUnique() { return cldeplus_make_unique<Identity>(); }
            static unique_ptr<Identity> CreateUnique(SPtrCellVector const &cells) { return cldeplus_make_unique<Identity>(cells); }
            static shared_ptr<Identity> CreateShared() { return cldeplus_make_shared<Identity>(); }
            static shared_ptr<Identity> CreateShared(SPtrCellVector const &cells) { return cldeplus_make_shared<Identity>(cells); }
        };

        using UPtrIdentity = unique_ptr<Identity>;
        using SPtrIdentity = shared_ptr<Identity>;
    }
}

#endif //CLOUD_E_CPLUS_FOUNDATION_IDENTITY_H
