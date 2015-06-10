//
// Created by LE, Duc Anh on 6/10/15.
//

#ifndef CLOUD_E_CPLUS_CLDEINT32_H
#define CLOUD_E_CPLUS_CLDEINT32_H

#include "../cldeNumericValue.h"

namespace Cloude {
    namespace Foundation {
        namespace Data {
            namespace Implementation {
                class cldeInt32 : public cldeNumericValue {
                public:
                    cldeInt32(int32_t value);
                    virtual ~cldeInt32() = default;
                    cldeInt32(const cldeInt32 &rhs) = default;
                    cldeInt32 &operator=(const cldeInt32 &rhs) = default;

                    virtual const void *RawPointerToValueBuffer() override;
                    virtual bool Equal(const Common::IEquatable &rhs) override;
                    virtual const std::string CopyToString() const override;
                    virtual const std::string &ToString() const override;
                    virtual void SetValueToString(const char *value) override;

                    virtual cldeValue &operator+(const cldeValue &rhs) override;
                    virtual cldeValue &operator-(const cldeValue &rhs) override;
                    virtual cldeValue &operator*(const cldeValue &rhs) override;
                    virtual cldeValue &operator/(const cldeValue &rhs) override;
                    virtual cldeValue &operator%(const cldeValue &rhs);

                private:
                    int32_t _value;
                    mutable std::string _string;

                };
            }
        }
    }
}

#endif //CLOUD_E_CPLUS_CLDEINT32_H
