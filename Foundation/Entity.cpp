//
// Created by LE, Duc Anh on 14/05/2015.
//

#include "Entity.h"

using namespace std;

namespace Cloude {
    namespace Foundation {
        SPtrEntity CreateEntitySharedPtr(const SPtrIdentity &identity) {
            return std::make_shared<Entity>(identity);
        }
    }
}