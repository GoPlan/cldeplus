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

                    virtual bool Equal(const Common::IEquatable &rhs) override;
                    virtual const void *RawPointerToValueBuffer() override;
                    virtual const std::string CopyToString() const override;
                    virtual const std::string &ToString() const override;
                    virtual void SetValueToString(const char *value) override;

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
