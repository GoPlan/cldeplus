//
// Created by LE, Duc Anh on 6/9/15.
//

#ifndef CLOUD_E_CPLUS_CLDEVALUE_H
#define CLOUD_E_CPLUS_CLDEVALUE_H

#include <Foundation/Common/IPrintable.h>
#include <Foundation/Common/IEquatable.h>
#include <Foundation/Common/IComputable.h>
#include "cldeValueType.h"

namespace Cloude {
    namespace Foundation {
        namespace Type {
            class cldeValue : public Common::IPrintable,
                              public Common::IEquatable,
                              public Common::IComputable<cldeValue> {

            public:
                cldeValue(cldeValueType dataType, size_t length);
                virtual ~cldeValue() = default;
                cldeValue(const cldeValue &rhs) = default;
                virtual cldeValue &operator=(const cldeValue &rhs) = default;

                virtual cldeValueCategory getCategory() = 0;
                virtual bool isNumeric() = 0;
                virtual void *RawPointerToValueBuffer() = 0;

                void *RawPointerToValueLength() {
                    return &_length;
                }

                cldeValueType &DataType() {
                    return _dataType;
                }

                size_t getLength() {
                    return _length;
                }

            protected:
                cldeValueType _dataType;
                size_t _length;
            };
        }
    }
}


#endif //CLOUD_E_CPLUS_CLDEVALUE_H
