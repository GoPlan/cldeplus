//
// Created by LE, Duc Anh on 6/24/15.
//

#ifndef CLDEPLUS_FOUNDATION_DATA_TYPE_UINT64_H
#define CLDEPLUS_FOUNDATION_DATA_TYPE_UINT64_H

#include "../NumericValue.h"

namespace CLDEPlus {
    namespace Foundation {
        namespace Data {
            namespace Type {

                class UInt64 : public NumericValue {

                    uint64_t _value = 0;

                public:
                    explicit UInt64(uint64_t value);
                    UInt64(UInt64 const &) = default;
                    UInt64(UInt64 &&) = default;
                    UInt64 &operator=(UInt64 const &) = default;
                    UInt64 &operator=(UInt64 &&) = default;
                    ~UInt64() = default;

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

#endif //CLDEPLUS_FOUNDATION_DATA_TYPE_UINT64_H
