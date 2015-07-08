//
// Created by LE, Duc Anh on 14/05/2015.
//

#ifndef CLOUD_E_CPLUS_FOUNDATION_ENTITY_H
#define CLOUD_E_CPLUS_FOUNDATION_ENTITY_H

#include <memory>
#include <stdexcept>
#include <list>
#include <set>
#include "Store/AbstractEntity.h"
#include "Cell.h"
#include "Identity.h"

namespace Cloude {
    namespace Foundation {

        class Entity : public Store::AbstractEntity {

            SPtrIdentity _identity;

        public:
            explicit Entity(const SPtrIdentity &identity) : _identity(identity) {

                if (!identity) {
                    std::string msg{"Identity can not be nullptr or undefined"};
                    throw std::invalid_argument{msg};
                }

                for (auto fieldPair : _identity->getCellsMap()) {
                    auto field = fieldPair.second;
                    setCell(field);
                }
            };

            Entity(const Entity &) = default;
            Entity(Entity &&) = default;
            Entity &operator=(const Entity &) = default;
            Entity &operator=(Entity &&) = default;
            virtual ~Entity() = default;

            // Locals
            const SPtrIdentity &getIdentity() { return _identity; }

            template<class TEntity>
            TEntity NamedEntity(std::function<TEntity(const Entity &)> converter) { return converter(*this); };
        };

        using SPtrEntity = std::shared_ptr<Entity>;
        using SPtrEntityVector = std::vector<SPtrEntity>;
        using SPtrEntityList = std::list<SPtrEntity>;
        using SPtrEntitySet = std::set<SPtrEntity>;
    }
}


#endif //CLOUD_E_CPLUS_FOUNDATION_ENTITY_H
