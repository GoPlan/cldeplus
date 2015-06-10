//
// Created by LE, Duc Anh on 6/10/15.
//

#ifndef CLOUD_E_CPLUS_CLDEINT64_H
#define CLOUD_E_CPLUS_CLDEINT64_H

#include "../cldeNumericValue.h"

namespace Cloude {
    namespace Foundation {
        namespace Data {
            namespace Implementation {
                class cldeInt64 : public cldeNumericValue {
                public:
                    cldeInt64(int64_t value);
                    virtual ~cldeInt64() = default;
                    cldeInt64(const cldeInt64 &rhs) = default;
                    cldeInt64 &operator=(const cldeInt64 &rhs) = default;

                    virtual const void *RawPointerToValueBuffer();
                    virtual bool Equal(const Common::IEquatable &rhs) override;
                    virtual const std::string ToString() const override;

                    virtual cldeValue &operator+(const cldeValue &rhs) override;
                    virtual cldeValue &operator-(const cldeValue &rhs) override;
                    virtual cldeValue &operator*(const cldeValue &rhs) override;
                    virtual cldeValue &operator/(const cldeValue &rhs) override;
                    virtual cldeValue &operator%(const cldeValue &rhs) override;

                private:
                    int64_t _value;
                };
            }
        }
    }
}


#endif //CLOUD_E_CPLUS_CLDEINT64_H
