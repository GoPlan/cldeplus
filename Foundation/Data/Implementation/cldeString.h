//
// Created by LE, Duc Anh on 6/10/15.
//

#ifndef CLOUD_E_CPLUS_CLDESTRING_H
#define CLOUD_E_CPLUS_CLDESTRING_H

#include <string>
#include "../cldeCharacterValue.h"

namespace Cloude {
    namespace Foundation {
        namespace Data {
            namespace Implementation {
                class cldeString : public cldeCharacterValue {
                public:
                    cldeString(const char *string);
                    virtual ~cldeString() = default;
                    cldeString(const cldeString &rhs) = default;
                    cldeString &operator=(const cldeString &rhs) = default;

                    virtual bool Equal(const Common::IEquatable &rhs);
                    virtual const std::string ToString() const;
                    virtual const void *RawPointerToValueBuffer();

                private:
                    std::string _value;
                };
            }
        }
    }
}


#endif //CLOUD_E_CPLUS_CLDESTRING_H
