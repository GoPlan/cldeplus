//
// Created by LE, Duc Anh on 6/10/15.
//

#ifndef CLOUD_E_CPLUS_FOUNDATION_DATA_TYPE_TEXT_H
#define CLOUD_E_CPLUS_FOUNDATION_DATA_TYPE_TEXT_H

#include <cstdlib>
#include "../CharacterValue.h"

namespace CLDEPlus {
    namespace Foundation {
        namespace Data {
            namespace Type {

                class Text : public CharacterValue {

                    char *_buffer = nullptr;

                public:
                    explicit Text(const string &text);
                    explicit Text(const char *text);
                    explicit Text(unsigned long length);
                    Text(const Text &) = default;
                    Text(Text &&) = default;
                    Text &operator=(const Text &) = default;
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
