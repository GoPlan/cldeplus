//
// Created by LE, Duc Anh on 6/24/15.
//

#ifndef CLDEPLUS_FOUNDATION_DATA_TYPE_BYTE_H
#define CLDEPLUS_FOUNDATION_DATA_TYPE_BYTE_H

#include "../NumericValue.h"

namespace CLDEPlus {
    namespace Foundation {
        namespace Data {
            namespace Type {

                class Byte : public NumericValue {

                    int _value;

                public:
                    explicit Byte(int byte);
                    Byte(const Byte &) = default;
                    Byte(Byte &&) = default;
                    Byte &operator=(const Byte &) = default;
                    Byte &operator=(Byte &&) = default;
                    ~Byte() = default;

                    // Value
                    virtual void *PointerToBuffer() override;

                    // IPrintable
                    virtual std::string ToString() const override;

                    // IComputable
                    virtual Value &operator+(const Value &rhs) override;
                    virtual Value &operator-(const Value &rhs) override;
                    virtual Value &operator*(const Value &rhs) override;
                    virtual Value &operator/(const Value &rhs) override;
                    virtual Value &operator%(const Value &rhs) override;
                };
            }
        }
    }
}


#endif //CLDEPLUS_FOUNDATION_DATA_TYPE_BYTE_H
