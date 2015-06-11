//
// Created by GoPlan on 14/05/2015.
//

#ifndef CLOUD_E_CPLUS_FIELD_H
#define CLOUD_E_CPLUS_FIELD_H

#include <string>
#include <memory>
#include "Type/cldeValue.h"
#include "Column.h"


namespace Cloude {
    namespace Foundation {
        class Field {
        public:
            explicit Field(const std::shared_ptr<Column> &column);
            ~Field() = default;
            Field(const Field &srcField) = default;
            Field &operator=(const Field &srcField) = default;

            const std::shared_ptr<Column> &getColumn() const { return _column; }
            const std::shared_ptr<Foundation::Type::cldeValue> &getValue() const { return _value; }
            void setValue(const std::shared_ptr<Foundation::Type::cldeValue> &value) { _value = value; }

        private:
            std::shared_ptr<Column> _column;
            std::shared_ptr<Foundation::Type::cldeValue> _value;
        };
    }
}


#endif //CLOUD_E_CPLUS_FIELD_H
