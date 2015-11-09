//
// Created by LE, Duc Anh on 6/24/15.
//

#ifndef CLDEPLUS_FOUNDATION_DATA_TYPE_UINT16_H
#define CLDEPLUS_FOUNDATION_DATA_TYPE_UINT16_H

#include "../NumericValue.h"

namespace CLDEPlus {
    namespace Foundation {
        namespace Data {
            namespace Type {

                class UInt16 : public NumericValue {

                    uint16_t _value = 0;

                public:
                    explicit UInt16(uint16_t value);
                    UInt16(UInt16 const &rhs) = default;
                    UInt16(UInt16 &&) = default;
                    UInt16 &operator=(UInt16 const &) = default;
                    UInt16 &operator=(UInt16 &&) = default;
                    ~UInt16() = default;

                    // Value
                    virtual void *PointerToBuffer() override;

                    // IPrintable
                    virtual string ToString() const override;

                    // IComputable
                    virtual Value &operator+(Value const &rhs) override;
                    virtual Value &operator-(Value const &rhs) override;
                    virtual Value &operator*(Value const &rhs) override;
                    virtual Value &operator/(Value const &rhs) override;
                    virtual Value &operator%(Value const &rhs) override;

                    // IPrimitiveAssignable
                    virtual Value &operator=(bool value) override;
                    virtual Value &operator=(double value) override;
                    virtual Value &operator=(float value) override;
                    virtual Value &operator=(int16 value) override;
                    virtual Value &operator=(int32 value) override;
                    virtual Value &operator=(int64 value) override;
                    virtual Value &operator=(uint16 value) override;
                    virtual Value &operator=(uint32 value) override;
                    virtual Value &operator=(uint64 value) override;
                };
            }
        }
    }
}

#endif //CLDEPLUS_FOUNDATION_DATA_TYPE_UINT16_H
