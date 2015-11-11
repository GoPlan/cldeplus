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

#ifndef CLDEPLUS_RELATION_NAMEDENTITYLOADER_H
#define CLDEPLUS_RELATION_NAMEDENTITYLOADER_H

#include "../Foundation/Identity.h"
#include "../Foundation/Entity.h"

namespace CLDEPlus {
    namespace Relation {

        template<typename TEntity>
        struct NamedEntityLoader {
            std::function<TEntity(Foundation::Entity const &entity)> fptrNamedEntityCreator;
            std::function<Foundation::SPtrIdentity()> fptrIdentityCreator;
        };
    }
}


#endif //CLDEPLUS_RELATION_NAMEDENTITYLOADER_H
