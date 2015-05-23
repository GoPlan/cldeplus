//
// Created by GoPlan on 14/05/2015.
//

#include "Identity.h"

namespace Cloude {
    namespace Architecture {
        namespace Foundation {

            Identity::Identity() {
                //
            }

            Identity::~Identity() {
            }

            shared_ptr<Identity> Identity::SetField(shared_ptr<Field> spField) {

                if (!_spEntity) {
                    _spEntity = make_shared<Entity>(shared_from_this());
                }

                _spEntity->InsertField(spField);

                return shared_from_this();
            }
        }
    }
}
