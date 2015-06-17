//
// Created by LE, Duc Anh on 6/10/15.
//

#ifndef CLOUD_E_CPLUS_FOUNDATION_TYPE_IMPLEMENTATION_CLDESTRING_H
#define CLOUD_E_CPLUS_FOUNDATION_TYPE_IMPLEMENTATION_CLDESTRING_H

#include <string>
#include <Foundation/Exception/cldeNonSupportedFunctionException.h>
#include "../cldeCharacterValue.h"

namespace Cloude {
    namespace Foundation {
        namespace Type {
            namespace Implementation {

                class cldeString : public cldeCharacterValue {
                    mutable std::string _value;

                public:
                    cldeString(const char *string);
                    cldeString(const cldeString &) = default;
                    cldeString(cldeString &&) = default;
                    cldeString &operator=(const cldeString &) = default;
                    cldeString &operator=(cldeString &&) = default;
                    ~cldeString() = default;

                    // cldeValue
                    virtual void *RawPointerToValueBuffer();

                    // IEquatable
                    virtual bool Equal(const Common::IEquatable &rhs);

                    // IPrintable
                    virtual const std::string CopyToString() const;
                    virtual const std::string &ToString() const;
                    virtual const char *ToCString() const override;
                };
            }
        }
    }
}


#endif //CLOUD_E_CPLUS_FOUNDATION_TYPE_IMPLEMENTATION_CLDESTRING_H
