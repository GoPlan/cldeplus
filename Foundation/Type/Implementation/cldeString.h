//
// Created by LE, Duc Anh on 6/10/15.
//

#ifndef CLOUD_E_CPLUS_CLDESTRING_H
#define CLOUD_E_CPLUS_CLDESTRING_H

#include <string>
#include <Foundation/Exception/cldeNonSupportedFunctionException.h>
#include "../cldeCharacterValue.h"

namespace Cloude {
    namespace Foundation {
        namespace Type {
            namespace Implementation {
                class cldeString : public cldeCharacterValue {
                public:
                    cldeString(const char *string);
                    virtual ~cldeString() = default;
                    cldeString(const cldeString &rhs) = default;
                    cldeString &operator=(const cldeString &rhs) = default;

                    // cldeValue
                    virtual void *RawPointerToValueBuffer();

                    // IEquatable
                    virtual bool Equal(const Common::IEquatable &rhs);

                    // IPrintable
                    virtual const std::string CopyToString() const;
                    virtual const std::string &ToString() const;
                    virtual const char *ToCString() const override;

                private:
                    mutable std::string _value;
                };
            }
        }
    }
}


#endif //CLOUD_E_CPLUS_CLDESTRING_H
