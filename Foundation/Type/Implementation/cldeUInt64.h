//
// Created by LE, Duc Anh on 6/24/15.
//

#ifndef CLOUD_E_PLUS_FOUNDATION_TYPE_IMPLEMENTATION_CLDEUINT64_H
#define CLOUD_E_PLUS_FOUNDATION_TYPE_IMPLEMENTATION_CLDEUINT64_H

#include "../cldeNumericValue.h"

namespace Cloude {
    namespace Foundation {
        namespace Type {
            namespace Implementation {

                class cldeUInt64 : public cldeNumericValue {
                    uint64_t _value;
                    mutable std::string _string;

                public:
                    explicit cldeUInt64(uint64_t value);
                    cldeUInt64(const cldeUInt64 &) = default;
                    cldeUInt64(cldeUInt64 &&) = default;
                    cldeUInt64 &operator=(const cldeUInt64 &) = default;
                    cldeUInt64 &operator=(cldeUInt64 &&) = default;
                    ~cldeUInt64() = default;

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

#endif //CLOUD_E_PLUS_FOUNDATION_TYPE_IMPLEMENTATION_CLDEUINT64_H
