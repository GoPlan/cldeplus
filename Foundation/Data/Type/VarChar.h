//
// Created by LE, Duc Anh on 6/10/15.
//

#ifndef CLOUD_E_CPLUS_FOUNDATION_DATA_TYPE_VARCHAR_H
#define CLOUD_E_CPLUS_FOUNDATION_DATA_TYPE_VARCHAR_H

#include <Foundation/Exception/cldeNonSupportedFunctionException.h>
#include <Foundation/Data/CharacterValue.h>

namespace Cloude {
    namespace Foundation {
        namespace Data {
            namespace Type {

                class VarChar : public CharacterValue {
                    char *_value;

                    void init();
                    void init(const char *value);

                public:
                    explicit VarChar(size_t length);
                    explicit VarChar(const std::string &value);
                    explicit VarChar(const char *value);
                    VarChar(const VarChar &);
                    VarChar(VarChar &&);
                    VarChar &operator=(const VarChar &);
                    VarChar &operator=(VarChar &&);
                    ~VarChar();

                    // Value
                    virtual void *RawPointerToValueBuffer() override;

                    // IEquatable
                    virtual bool Equal(const Common::IEquatable &rhs) const override;

                    // IPrintable
                    virtual const std::string CopyToString() const override;
                    virtual const std::string &ToString() const override;
                    virtual const char *ToCString() const override;
                };
            }
        }
    }
}


#endif //CLOUD_E_CPLUS_FOUNDATION_DATA_TYPE_VARCHAR_H
