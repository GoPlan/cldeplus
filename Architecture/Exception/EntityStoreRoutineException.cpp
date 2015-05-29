//
// Created by LE, Duc Anh on 5/26/15.
//

#include "../EntityStore.h"
#include "EntityStoreRoutineException.h"

using namespace std;
using namespace Cloude::Architecture;

using namespace std;

namespace Cloude {
    namespace Architecture {
        namespace Exception {
            EntityStoreRoutineException::EntityStoreRoutineException(EntityStore &store,
                                                                     const string &sstrMessage) : _store(store),
                                                                                                  _message(sstrMessage) {
                //
            }

            EntityStoreRoutineException::EntityStoreRoutineException(EntityStore &store,
                                                                     const char *cstrMessage) : _store(store),
                                                                                                _message(cstrMessage) {
                //
            }

            const char *EntityStoreRoutineException::what() const noexcept {
                return _message.c_str();
            }

        }
    }
}