//
// Created by LE, Duc Anh on 14/05/2015.
//

#ifndef CLOUD_E_CPLUS_FOUNDATION_FIELD_H
#define CLOUD_E_CPLUS_FOUNDATION_FIELD_H

#include <string>
#include <memory>
#include <unordered_map>
#include "Type/cldeValue.h"
#include "Column.h"


namespace Cloude {
    namespace Foundation {

        class Field {

        public:
            Field() = delete;
            ~Field() = default;
            Field(const Field &srcField) = default;
            Field &operator=(const Field &srcField) = default;

            explicit Field(const SPtrColumn &column);

            const SPtrColumn &getColumn() const { return _column; }
            const Type::SPtrCldeValue &getValue() const { return _value; }
            void setValue(const Type::SPtrCldeValue &value) { _value = value; }

            bool isNull() const { return _value.get() == nullptr; };

        private:
            SPtrColumn _column;
            Type::SPtrCldeValue _value;
        };

        using SPtrField = std::shared_ptr<Field>;
        using SPtrFieldMap = std::unordered_map<std::string, SPtrField>;
        using SPtrFieldVector = std::vector<SPtrField>;
    }
}


#endif //CLOUD_E_CPLUS_FOUNDATION_FIELD_H
