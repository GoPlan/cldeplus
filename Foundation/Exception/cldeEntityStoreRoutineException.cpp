//
// Created by LE, Duc Anh on 5/26/15.
//

#include "../EntityStore.h"
#include "cldeEntityStoreRoutineException.h"

using namespace std;
using namespace Cloude::Foundation;

using namespace std;

namespace Cloude {
    namespace Foundation {
        namespace Exception {
            cldeEntityStoreRoutineException::cldeEntityStoreRoutineException(const EntityStore &store,
                                                                     const string &sstrMessage)
                    : _store(store),
                      _message(sstrMessage) {
                //
            }

            cldeEntityStoreRoutineException::cldeEntityStoreRoutineException(const EntityStore &store,
                                                                     const char *cstrMessage)
                    : _store(store),
                      _message(cstrMessage) {
                //
            }

            const char *cldeEntityStoreRoutineException::what() const noexcept {
                return _message.c_str();
            }

        }
    }
}