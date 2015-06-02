//
// Created by GoPlan on 14/05/2015.
//

#include "Identity.h"

using namespace std;

namespace Cloude {
    namespace Architecture {

        shared_ptr<Identity> Identity::SetField(std::shared_ptr<Field> &field) {

            if (!_entity) {
                _entity = make_shared<Entity>(shared_from_this());
            }

            _entity->InsertField(field);

            return shared_from_this();
        }

        std::shared_ptr<Identity> Identity::SetField(Field *ptrField) {

            if (!_entity) {
                _entity = make_shared<Entity>(shared_from_this());
            }

            _entity->InsertField(ptrField);

            return shared_from_this();
        }

        std::shared_ptr<Identity> Identity::SetField(const std::initializer_list<Field *> &ptrFieldList) {

            for (auto ptrField : ptrFieldList) {
                SetField(ptrField);
            }

            return shared_from_this();
        }

        std::shared_ptr<Identity> Identity::SetField(const std::initializer_list<std::shared_ptr<Field>> &spFieldList) {

            for (auto spField : spFieldList) {
                SetField(const_cast<std::shared_ptr<Field> &>(spField));
            }

            return shared_from_this();
        }
    }
}
