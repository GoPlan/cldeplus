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
                throw std::invalid_argument{msg};
            }

            for (auto fieldPair : _identity->getFieldsMap()) {
                auto field = fieldPair.second;
                setField(field);
            }
        }
    }
}