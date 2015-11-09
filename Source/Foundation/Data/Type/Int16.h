//
// Created by LE, Duc Anh on 6/10/15.
//

#ifndef CLOUD_E_CPLUS_FOUNDATION_DATA_TYPE_INT16_H
#define CLOUD_E_CPLUS_FOUNDATION_DATA_TYPE_INT16_H

#include "../NumericValue.h"

namespace CLDEPlus {
    namespace Foundation {
        namespace Data {
            namespace Type {

                class Int16 : public NumericValue {

                    int16_t _value = 0;

                public:
                    explicit Int16(int16_t value);
                    Int16(Int16 const &rhs) = default;
                    Int16(Int16 &&) = default;
                    Int16 &operator=(Int16 const &) = default;
                    Int16 &operator=(Int16 &&) = default;
                    ~Int16() = default;

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


#endif //CLOUD_E_CPLUS_FOUNDATION_DATA_TYPE_INT16_H
