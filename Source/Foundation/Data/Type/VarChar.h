//
// Created by LE, Duc Anh on 6/10/15.
//

#ifndef CLOUD_E_CPLUS_FOUNDATION_DATA_TYPE_VARCHAR_H
#define CLOUD_E_CPLUS_FOUNDATION_DATA_TYPE_VARCHAR_H

#include "../CharacterValue.h"

namespace CLDEPlus {
    namespace Foundation {
        namespace Data {
            namespace Type {

                class VarChar : public CharacterValue {

                    char *_value;

                    void init();
                    void init(const char *value);

                public:
                    explicit VarChar(size_t length);
                    explicit VarChar(const string &value);
                    explicit VarChar(const char *value);
                    VarChar(const VarChar &);
                    VarChar(VarChar &&);
                    VarChar &operator=(const VarChar &);
                    VarChar &operator=(VarChar &&);
                    ~VarChar();

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


#endif //CLOUD_E_CPLUS_FOUNDATION_DATA_TYPE_VARCHAR_H
