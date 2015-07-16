//
// Created by LE, Duc Anh on 6/10/15.
//

#ifndef CLOUD_E_CPLUS_FOUNDATION_DATA_TYPE_STRING_H
#define CLOUD_E_CPLUS_FOUNDATION_DATA_TYPE_STRING_H

#include <string>
#include <Foundation/Exception/cldeNonSupportedFunctionException.h>
#include <Foundation/Data/CharacterValue.h>

namespace Cloude {
    namespace Foundation {
        namespace Data {
            namespace Type {

                class String : public CharacterValue {

                    std::string _value;

                public:
                    explicit String(const std::string &string);
                    explicit String(unsigned long length);
                    String()=default;
                    String(const String &) = default;
                    String(String &&) = default;
                    String &operator=(const String &) = default;
                    String &operator=(String &&) = default;
                    ~String() = default;

                    // Value
                    virtual void *RawPointerToValueBuffer();

                    // IPrintable
                    virtual std::string ToString() const;
                };
            }
        }
    }
}


#endif //CLOUD_E_CPLUS_FOUNDATION_DATA_TYPE_STRING_H
