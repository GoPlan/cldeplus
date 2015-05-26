//
// Created by LE, Duc Anh on 5/26/15.
//

#include "../EntityStore.h"
#include "EntityStoreRoutineException.h"

using namespace std;
using namespace Cloude::Architecture;

namespace Cloude {
    namespace Architecture {
        namespace Exception {
            EntityStoreRoutineException::EntityStoreRoutineException(
                    EntityStore &store, const std::string &message) :
                    _store(store),
                    _message("[" + store.getEntityMap().TableName() + "] store routine exception: " + message) {
                //
            }

            const char *EntityStoreRoutineException::what() const noexcept {
                return _message.c_str();
            }
        }
    }
}