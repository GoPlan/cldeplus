//
// Created by LE, Duc Anh on 6/9/15.
//

#ifndef CLOUD_E_CPLUS_FOUNDATION_TYPE_VALUE_H
#define CLOUD_E_CPLUS_FOUNDATION_TYPE_VALUE_H

#include <Foundation/Common/IPrintable.h>
#include <Foundation/Common/IEquatable.h>
#include <Foundation/Common/IComputable.h>
#include "TypeEnums.h"

namespace Cloude {
    namespace Foundation {
        namespace Data {

            class Value : public Common::IPrintable,
                          public Common::IEquatable,
                          public Common::IComputable<Value> {

            public:
                Value(ValueType dataType, size_t length);
                Value(const Value &) = default;
                Value(Value &&) = default;
                Value &operator=(const Value &) = default;
                Value &operator=(Value &&) = default;
                virtual ~Value() = default;

                virtual const ValueCategory &getCategory() const = 0;
                virtual bool isNumeric() const = 0;
                virtual void *RawPointerToValueBuffer() = 0;

                void *RawPointerToValueLength() { return &_length; }
                ValueType getDataType() const { return _dataType; }
                size_t getLength() const { return _length; }

            protected:
                ValueType _dataType;
                size_t _length;
            };

            using SPtrValue = std::shared_ptr<Value>;
        }
    }
}


#endif //CLOUD_E_CPLUS_FOUNDATION_TYPE_VALUE_H
