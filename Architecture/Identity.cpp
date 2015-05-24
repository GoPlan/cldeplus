//
// Created by GoPlan on 14/05/2015.
//

#include "Identity.h"

using namespace std;

namespace Cloude {
    namespace Architecture {

        Identity::Identity(std::shared_ptr<Field> spField) {
            SetField(spField);
        }

        Identity::Identity(Field *ptrField) {
            SetField(ptrField);
        }

        shared_ptr<Identity> Identity::SetField(shared_ptr<Field> spField) {

            if (!_spEntity) {
                _spEntity = make_shared<Entity>(shared_from_this());
            }

            _spEntity->InsertField(spField);

            return shared_from_this();
        }

        std::shared_ptr<Identity> Identity::SetField(Field *ptrField) {

            if (!_spEntity) {
                _spEntity = make_shared<Entity>(shared_from_this());
            }

            _spEntity->InsertField(ptrField);

            return shared_from_this();
        }

        std::shared_ptr<Identity> Identity::SetField(const std::initializer_list<Field *> &ptrFieldList) {
            for(auto ptrField : ptrFieldList){
                SetField(ptrField);
            }
            return shared_from_this();
        }
    }
}
