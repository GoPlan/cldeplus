//
// Created by LE, Duc Anh on 6/24/15.
//

#ifndef CLOUD_E_PLUS_FOUNDATION_DATA_TYPE_BYTE_H
#define CLOUD_E_PLUS_FOUNDATION_DATA_TYPE_BYTE_H

#include <Foundation/Data/NumericValue.h>

namespace Cloude {
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
                    virtual void *RawPointerToValueBuffer() override;

                    // IEquatable
                    virtual bool Equal(const Common::IEquatable &rhs) const override;

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


#endif //CLOUD_E_PLUS_FOUNDATION_DATA_TYPE_BYTE_H
