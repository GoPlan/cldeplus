//
// Created by LE, Duc Anh on 14/05/2015.
//

#ifndef CLOUD_E_CPLUS_FOUNDATION_IDENTITY_H
#define CLOUD_E_CPLUS_FOUNDATION_IDENTITY_H

#include "cldeplus_default"
#include "Store/AbstractEntity.h"
#include "Cell.h"

namespace CLDEPlus {
    namespace Foundation {

        class Identity : public Store::AbstractEntity {

        public:
            explicit Identity(const vector<SPtrCell> &sptrCells);
            Identity() = default;
            Identity(const Identity &) = default;
            Identity(Identity &&) = default;
            Identity &operator=(const Identity &) = default;
            Identity &operator=(Identity &&) = default;
            ~Identity() = default;

            // Factory methods
            static unique_ptr<Identity> Create() {
                return cldeplus_make_unique<Identity>();
            }

            static unique_ptr<Identity> Create(SPtrCellVector const &cells) {
                return cldeplus_make_unique<Identity>(cells);
            }
        };

        using UPtrIdentity = unique_ptr<Identity>;
        using SPtrIdentity = shared_ptr<Identity>;
    }
}

#endif //CLOUD_E_CPLUS_FOUNDATION_IDENTITY_H
