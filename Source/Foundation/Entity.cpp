//
// Created by LE, Duc Anh on 14/05/2015.
//

#include "Entity.h"

using namespace std;

namespace CLDEPlus {
    namespace Foundation {

        Entity::Entity(SPtrIdentity const &identity) : _identity(identity) {

            if (!identity) {
                string msg{"Identity can not be nullptr or undefined"};
                throw Exception::CLDEEntityException{msg};
            }

            for (auto fieldPair : _identity->getCellsMap()) {
                auto field = fieldPair.second;
                setCell(field);
            }
        }
    }
}