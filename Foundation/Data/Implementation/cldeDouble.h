//
// Created by LE, Duc Anh on 6/10/15.
//

#ifndef CLOUD_E_CPLUS_CLDEDOUBLE_H
#define CLOUD_E_CPLUS_CLDEDOUBLE_H

#include "../cldeNumericValue.h"
#include <Foundation/Exception/cldeNonSupportedFunctionException.h>

namespace Cloude {
    namespace Foundation {
        namespace Data {
            namespace Implementation {
                class cldeDouble : public cldeNumericValue {
                public:
                    cldeDouble(double value);
                    virtual ~cldeDouble() = default;
                    cldeDouble(const cldeDouble &rhs) = default;
                    cldeDouble &operator=(const cldeDouble &rhs) = default;

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

                private:
                    double _value;
                    mutable std::string _string;
                };
            }
        }
    }
}

#endif //CLOUD_E_CPLUS_CLDEDOUBLE_H
