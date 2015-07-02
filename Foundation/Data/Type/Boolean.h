//
// Created by LE, Duc Anh on 6/24/15.
//

#ifndef CLOUD_E_PLUS_FOUNDATION_DATA_TYPE_BOOLEAN_H
#define CLOUD_E_PLUS_FOUNDATION_DATA_TYPE_BOOLEAN_H

#include <Foundation/Data/Value.h>
#include <Foundation/Data/NumericValue.h>

namespace Cloude {
    namespace Foundation {
        namespace Data {
            namespace Type {

                class Boolean : public NumericValue {
                    bool _value;
                    mutable std::string _string;

                public:
                    explicit Boolean(bool value);
                    Boolean(const Boolean &) = default;
                    Boolean(Boolean &&) = default;
                    Boolean &operator=(const Boolean &) = default;
                    Boolean &operator=(Boolean &&) = default;
                    ~Boolean() = default;

                    // Value
                    virtual void *RawPointerToValueBuffer() override;

                    // IEquatable
                    virtual bool Equal(const Common::IEquatable &rhs) const override;

                    // IPrintable
                    virtual const std::string CopyToString() const override;
                    virtual const std::string &ToString() const override;
                    virtual const char *ToCString() const override;

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


#endif //CLOUD_E_PLUS_FOUNDATION_DATA_TYPE_BOOLEAN_H
