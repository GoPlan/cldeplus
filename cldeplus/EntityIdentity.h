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

#ifndef CLDEPLUS_IDENTITY_H
#define CLDEPLUS_IDENTITY_H

#include "CldePlus-Portable.h"
#include "EntityCell.h"
#include "DataRecord.h"

namespace CLDEPlus {

    class EntityIdentity : public DataRecord {

    public:
        explicit EntityIdentity(vector<SPtrCell> const &sptrCells);
        EntityIdentity() = default;
        EntityIdentity(EntityIdentity const &) = default;
        EntityIdentity(EntityIdentity &&) = default;
        EntityIdentity &operator=(EntityIdentity const &) = default;
        EntityIdentity &operator=(EntityIdentity &&) = default;
        ~EntityIdentity() = default;

        // Factory methods
        static unique_ptr<EntityIdentity> CreateUnique() { return cldeplus_make_unique<EntityIdentity>(); }
        static unique_ptr<EntityIdentity> CreateUnique(SPtrCellVector const &cells) { return cldeplus_make_unique<EntityIdentity>(cells); }
        static shared_ptr<EntityIdentity> CreateShared() { return cldeplus_make_shared<EntityIdentity>(); }
        static shared_ptr<EntityIdentity> CreateShared(SPtrCellVector const &cells) { return cldeplus_make_shared<EntityIdentity>(cells); }
    };

    using UPtrIdentity = unique_ptr<EntityIdentity>;
    using SPtrIdentity = shared_ptr<EntityIdentity>;
}

#endif //CLDEPLUS_IDENTITY_H
