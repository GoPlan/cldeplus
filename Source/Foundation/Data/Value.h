//
// Created by LE, Duc Anh on 6/9/15.
//

#ifndef CLOUD_E_CPLUS_FOUNDATION_TYPE_VALUE_H
#define CLOUD_E_CPLUS_FOUNDATION_TYPE_VALUE_H

#include "../../Port/Definitions.h"
#include "../Common/IPrintable.h"
#include "../Common/IComputable.h"
#include "../Common/IPrimitiveAssignable.h"
#include "TypeEnums.h"

namespace CLDEPlus {
    namespace Foundation {
        namespace Data {

            class Value : public Common::IPrintable {

            public:
                Value(ValueType dataType, size_t size);

                virtual size_t getActualSize() { return _actualSize; }
                virtual const ValueCategory &getCategory() const = 0;
                virtual bool isNumeric() const = 0;
                virtual void *PointerToBuffer() = 0;
                virtual void *PointerToActualSizeVar() { return &_actualSize; };

                //
                void *PointerToReservedSizeVar() { return &_reservedSize; }
                size_t getReservedSize() const { return _reservedSize; }
                ValueType getDataType() const { return _dataType; }

                //
                virtual Value &operator+(Value const &rhs) = 0;
                virtual Value &operator-(Value const &rhs) = 0;
                virtual Value &operator*(Value const &rhs) = 0;
                virtual Value &operator/(Value const &rhs) = 0;
                virtual Value &operator%(Value const &rhs) = 0;

                //
                virtual Value &operator=(bool value) = 0;
                virtual Value &operator=(double value) = 0;
                virtual Value &operator=(float value) = 0;
                virtual Value &operator=(int16 value) = 0;
                virtual Value &operator=(int32 value) = 0;
                virtual Value &operator=(int64 value) = 0;
                virtual Value &operator=(uint16 value) = 0;
                virtual Value &operator=(uint32 value) = 0;
                virtual Value &operator=(uint64 value) = 0;

            protected:
                ValueType _dataType;
                size_t _reservedSize;
                size_t _actualSize;

            };

            using SPtrValue = shared_ptr<Value>;
        }
    }
}


#endif //CLOUD_E_CPLUS_FOUNDATION_TYPE_VALUE_H
