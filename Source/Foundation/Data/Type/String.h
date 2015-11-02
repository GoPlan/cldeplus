//
// Created by LE, Duc Anh on 6/10/15.
//

#ifndef CLOUD_E_CPLUS_FOUNDATION_DATA_TYPE_STRING_H
#define CLOUD_E_CPLUS_FOUNDATION_DATA_TYPE_STRING_H

#include "../../../Port/Definitions.h"
#include "../CharacterValue.h"

namespace CLDEPlus {
    namespace Foundation {
        namespace Data {
            namespace Type {

                class String : public CharacterValue {

                    string _value;

                public:
                    explicit String(const string &string);
                    explicit String(unsigned long size);
                    String() = default;
                    String(const String &) = default;
                    String(String &&) = default;
                    String &operator=(const String &) = default;
                    String &operator=(String &&) = default;
                    ~String() = default;

                    // Value
                    virtual void *PointerToBuffer() override;
                    virtual size_t getActualSize() override;

                    // IPrintable
                    virtual string ToString() const override;
                };
            }
        }
    }
}


#endif //CLOUD_E_CPLUS_FOUNDATION_DATA_TYPE_STRING_H
