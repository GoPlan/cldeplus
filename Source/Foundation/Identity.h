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
            Identity() = default;
            Identity(const Identity &) = default;
            Identity(Identity &&) = default;
            Identity &operator=(const Identity &) = default;
            Identity &operator=(Identity &&) = default;
            ~Identity() = default;

            Identity(const std::vector<SPtrCell> &fieldVector);
            Identity(const std::vector<Cell *> &fieldVector);
        };

        using SPtrIdentity = std::shared_ptr<Identity>;

        SPtrIdentity CreateIdentity();
        SPtrIdentity CreateIdentity(const std::vector<SPtrCell> &cells);
        SPtrIdentity CreateIdentity(const std::vector<Cell *> &cells);
    }
}

#endif //CLOUD_E_CPLUS_FOUNDATION_IDENTITY_H