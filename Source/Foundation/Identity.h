//
// Created by LE, Duc Anh on 14/05/2015.
//

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
