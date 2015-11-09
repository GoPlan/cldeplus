//
// Created by LE, Duc Anh on 6/10/15.
//

#ifndef CLOUD_E_CPLUS_FOUNDATION_DATA_TYPE_TEXT_H
#define CLOUD_E_CPLUS_FOUNDATION_DATA_TYPE_TEXT_H

#include "../../../Port/Definitions.h"
#include "../CharacterValue.h"

namespace CLDEPlus {
    namespace Foundation {
        namespace Data {
            namespace Type {

                class Text : public CharacterValue {

                    char *_buffer = nullptr;

                public:
                    explicit Text(string const &text);
                    explicit Text(char const *text);
                    explicit Text(unsigned long length);
                    Text(Text const &) = default;
                    Text(Text &&) = default;
                    Text &operator=(Text const &) = default;
                    Text &operator=(Text &&) = default;
                    ~Text();

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


#endif //CLOUD_E_CPLUS_FOUNDATION_DATA_TYPE_TEXT_H
