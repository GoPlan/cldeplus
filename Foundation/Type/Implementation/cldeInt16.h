//
// Created by LE, Duc Anh on 6/10/15.
//

#ifndef CLOUD_E_CPLUS_FOUNDATION_TYPE_IMPLEMENTATION_CLDEINT16_H
#define CLOUD_E_CPLUS_FOUNDATION_TYPE_IMPLEMENTATION_CLDEINT16_H

#include "../cldeNumericValue.h"

namespace Cloude {
    namespace Foundation {
        namespace Type {
            namespace Implementation {

                class cldeInt16 : public cldeNumericValue {
                    int16_t _value;
                    mutable std::string _string;

                public:
                    explicit cldeInt16(int16_t value);
                    cldeInt16(const cldeInt16 &rhs) = default;
                    cldeInt16(cldeInt16 &&) = default;
                    cldeInt16 &operator=(const cldeInt16 &) = default;
                    cldeInt16 &operator=(cldeInt16 &&) = default;
                    ~cldeInt16() = default;

                    // cldeValue
                    virtual void *RawPointerToValueBuffer() override;

                    // IEquatable
                    virtual bool Equal(const Common::IEquatable &rhs) override;

                    // IPrintable
                    virtual const std::string CopyToString() const override;
                    virtual const std::string &ToString() const override;
                    virtual const char *ToCString() const override;

                    // IComputable
                    virtual cldeValue &operator+(const cldeValue &rhs) override;
                    virtual cldeValue &operator-(const cldeValue &rhs) override;
                    virtual cldeValue &operator*(const cldeValue &rhs) override;
                    virtual cldeValue &operator/(const cldeValue &rhs) override;
                    virtual cldeValue &operator%(const cldeValue &rhs) override;

                };
            }
        }
    }
}


#endif //CLOUD_E_CPLUS_FOUNDATION_TYPE_IMPLEMENTATION_CLDEINT16_H
