//
// Created by LE, Duc Anh on 14/05/2015.
//

#ifndef CLOUD_E_CPLUS_FOUNDATION_IDENTITY_H
#define CLOUD_E_CPLUS_FOUNDATION_IDENTITY_H

#include <unordered_map>
#include "Store/AbstractEntity.h"
#include "Cell.h"

namespace Cloude {
    namespace Foundation {

        class Identity : public Store::AbstractEntity {

        public:
            explicit Identity(const std::vector<SPtrCell> &sptrCells);
            Identity() = default;
            Identity(const Identity &) = default;
            Identity(Identity &&) = default;
            Identity &operator=(const Identity &) = default;
            Identity &operator=(Identity &&) = default;
            ~Identity() = default;

            // Factory methods
            static std::unique_ptr<Identity> Create(){
                return std::unique_ptr<Identity>(new Identity());
            }

            static std::unique_ptr<Identity> Create(SPtrCellVector const &cells){
                return std::unique_ptr<Identity>(new Identity(cells));
            }
        };

        using UPtrIdentity = std::unique_ptr<Identity>;
        using SPtrIdentity = std::shared_ptr<Identity>;
    }
}

#endif //CLOUD_E_CPLUS_FOUNDATION_IDENTITY_H
