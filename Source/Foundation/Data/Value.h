//
// Created by LE, Duc Anh on 6/9/15.
//

#ifndef CLOUD_E_CPLUS_FOUNDATION_TYPE_VALUE_H
#define CLOUD_E_CPLUS_FOUNDATION_TYPE_VALUE_H

#include "../Common/IPrintable.h"
#include "../Common/IComputable.h"
#include "TypeEnums.h"

namespace Cloude {
    namespace Foundation {
        namespace Data {

            class Value : public Common::IPrintable,
                          public Common::IComputable<Value> {

            public:
                Value(ValueType dataType, size_t size);
                Value(const Value &) = default;
                Value(Value &&) = default;
                Value &operator=(const Value &) = default;
                Value &operator=(Value &&) = default;
                virtual ~Value() = default;

                virtual size_t getActualSize() { return _actualSize; }
                virtual const ValueCategory &getCategory() const = 0;
                virtual bool isNumeric() const = 0;
                virtual void *PointerToBuffer() = 0;
                virtual void *PointerToActualSizeVar() { return &_actualSize; };

                void *PointerToReservedSizeVar() { return &_reservedSize; }
                size_t getReservedSize() const { return _reservedSize; }
                ValueType getDataType() const { return _dataType; }

            protected:
                ValueType _dataType;
                size_t _reservedSize;
                size_t _actualSize;

            };

            using SPtrValue = std::shared_ptr<Value>;
        }
    }
}


#endif //CLOUD_E_CPLUS_FOUNDATION_TYPE_VALUE_H
