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