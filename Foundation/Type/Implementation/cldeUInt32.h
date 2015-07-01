//
// Created by LE, Duc Anh on 6/24/15.
//

#ifndef CLOUD_E_PLUS_FOUNDATION_TYPE_IMPLEMENTATION_CLDEUINT32_H
#define CLOUD_E_PLUS_FOUNDATION_TYPE_IMPLEMENTATION_CLDEUINT32_H

#include "../cldeNumericValue.h"

namespace Cloude {
    namespace Foundation {
        namespace Type {
            namespace Implementation {

                class cldeUInt32 : public cldeNumericValue {
                    uint32_t _value;
                    mutable std::string _string;

                public:
                    explicit cldeUInt32(int value);
                    cldeUInt32(const cldeUInt32 &) = default;
                    cldeUInt32(cldeUInt32 &&) = default;
                    cldeUInt32 &operator=(const cldeUInt32 &) = default;
                    cldeUInt32 &operator=(cldeUInt32 &&) = default;
                    ~cldeUInt32() = default;

                    // cldeValue
                    virtual void *RawPointerToValueBuffer() override;

                    // IEquatable
                    virtual bool Equal(const Common::IEquatable &rhs) const override;

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

#endif //CLOUD_E_PLUS_FOUNDATION_TYPE_IMPLEMENTATION_CLDEUINT32_H
