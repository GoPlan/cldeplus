//
// Created by LE, Duc Anh on 6/10/15.
//

#ifndef CLOUD_E_CPLUS_FOUNDATION_DATA_TYPE_INT32_H
#define CLOUD_E_CPLUS_FOUNDATION_DATA_TYPE_INT32_H

#include "../NumericValue.h"

namespace CLDEPlus {
    namespace Foundation {
        namespace Data {
            namespace Type {

                class Int32 : public NumericValue {

                    int32_t _value = 0;

                public:
                    explicit Int32(int32_t value);
                    Int32(Int32 const &) = default;
                    Int32(Int32 &&) = default;
                    Int32 &operator=(Int32 const &) = default;
                    Int32 &operator=(Int32 &&) = default;
                    ~Int32() = default;

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

#endif //CLOUD_E_CPLUS_FOUNDATION_DATA_TYPE_INT32_H
