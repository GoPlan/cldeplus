//
// Created by LE, Duc Anh on 7/9/15.
//

#include "NamedEntityStoreException.h"

namespace CLDEPlus {
    namespace Relation {
        namespace Exception {

            std::string NamedEntityStoreException::_name{"NamedEntityStoreException"};

            const std::string &NamedEntityStoreException::Name() const noexcept {
                return _name;
            }
        }
    }
}


