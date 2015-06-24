//
// Created by LE, Duc Anh on 6/10/15.
//

#ifndef CLOUD_E_CPLUS_FOUNDATION_TYPE_IMPLEMENTATION_CLDEVARCHAR_H
#define CLOUD_E_CPLUS_FOUNDATION_TYPE_IMPLEMENTATION_CLDEVARCHAR_H

#include <Foundation/Exception/cldeNonSupportedFunctionException.h>
#include <Foundation/Type/cldeCharacterValue.h>

namespace Cloude {
    namespace Foundation {
        namespace Type {
            namespace Implementation {

                class cldeVarChar : public cldeCharacterValue {
                    char *_value;

                    void init();
                    void init(const char *value);

                public:
                    explicit cldeVarChar(size_t length);
                    explicit cldeVarChar(const std::string &value);
                    explicit cldeVarChar(const char *value);
                    cldeVarChar(const cldeVarChar &);
                    cldeVarChar(cldeVarChar &&);
                    cldeVarChar &operator=(const cldeVarChar &);
                    cldeVarChar &operator=(cldeVarChar &&);
                    ~cldeVarChar();

                    // cldeValue
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


#endif //CLOUD_E_CPLUS_FOUNDATION_TYPE_IMPLEMENTATION_CLDEVARCHAR_H
