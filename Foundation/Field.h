//
// Created by GoPlan on 14/05/2015.
//

#ifndef CLOUD_E_CPLUS_FIELD_H
#define CLOUD_E_CPLUS_FIELD_H

#include <string>
#include <memory>
#include "Data/cldeValue.h"
#include "Column.h"


namespace Cloude {
    namespace Foundation {

        class Field {
        public:
            using cldeValue = Foundation::Data::cldeValue;

        public:
            explicit Field(const std::shared_ptr<Column> &column);
            ~Field() = default;
            Field(const Field &srcField) = default;
            Field &operator=(const Field &srcField) = default;

            void *PointerToFieldValue();

            const std::shared_ptr<Column> &getColumn() const {
                return _column;
            }

            int64_t getInt64() const {
                return _int64;
            }

            void setInt64(int64_t int64) {
                _int64 = int64;
            }

            void setCString(const char *value) {
                strncpy(_cstr, value, 255);
            }

            char *getCString() {
                return &_cstr[0];
            }

            const std::shared_ptr<cldeValue> &getValue() const {
                return _value;
            }

            void setValue(const std::shared_ptr<cldeValue> &value) {
                _value = value;
            }

        private:
            std::shared_ptr<Column> _column;
            std::shared_ptr<cldeValue> _value;

            int64_t _int64;
            char _cstr[255];

            void ResetField();
        };
    }
}


#endif //CLOUD_E_CPLUS_FIELD_H
