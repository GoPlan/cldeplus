//
// Created by LE, Duc Anh on 14/05/2015.
//

#include "Entity.h"

using namespace std;

namespace Cloude {
    namespace Foundation {

        Entity::Entity(const SPtrIdentity &identity) : _identity(identity) {

            if (!identity) {
                std::string msg{"Identity can not be nullptr or undefined"};
                throw Exception::CLDEEntityException{msg};
            }

            for (auto fieldPair : _identity->getCellsMap()) {
                auto field = fieldPair.second;
                setCell(field);
            }
        }

        std::shared_ptr<Entity> Entity::CreateSharedPtr(const SPtrIdentity &identity) {
            return std::make_shared<Entity>(identity);
        }

        std::unique_ptr<Entity> Entity::CreateUniquePtr(const SPtrIdentity &identity) {
            return std::unique_ptr<Entity>(new Entity(identity));
        }
    }
}