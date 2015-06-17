//
// Created by LE, Duc Anh on 6/10/15.
//

#ifndef CLOUD_E_CPLUS_FOUNDATION_TYPE_IMPLEMENTATION_CLDEDOUBLE_H
#define CLOUD_E_CPLUS_FOUNDATION_TYPE_IMPLEMENTATION_CLDEDOUBLE_H

#include "../cldeNumericValue.h"
#include <Foundation/Exception/cldeNonSupportedFunctionException.h>

namespace Cloude {
    namespace Foundation {
        namespace Type {
            namespace Implementation {

                class cldeDouble : public cldeNumericValue {
                    double _value;
                    mutable std::string _string;

                public:
                    explicit cldeDouble(double value);
                    cldeDouble(const cldeDouble &) = default;
                    cldeDouble(cldeDouble &&) = default;
                    cldeDouble &operator=(const cldeDouble &) = default;
                    cldeDouble &operator=(cldeDouble &&) = default;
                    ~cldeDouble() = default;

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

#endif //CLOUD_E_CPLUS_FOUNDATION_TYPE_IMPLEMENTATION_CLDEDOUBLE_H
