//
// Created by GoPlan on 14/05/2015.
//

#include "Identity.h"

using namespace std;

namespace Cloude {
    namespace Architecture {

        Identity::Identity() {
            //
        }

        Identity::Identity(const Identity &srcIdentity) {

        }

        Identity &Identity::operator=(const Identity &srcIdentity) {
            return *this;
        }

        Identity::~Identity() {
            //
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
