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

                class cldeVarchar : public cldeCharacterValue {
                    char *_value;

                    void init();
                    void init(const char *value);

                public:
                    explicit cldeVarchar(size_t length);
                    explicit cldeVarchar(const char *value);
                    cldeVarchar(const cldeVarchar &) = default;
                    cldeVarchar(cldeVarchar &&) = default;
                    cldeVarchar &operator=(const cldeVarchar &) = default;
                    cldeVarchar &operator=(cldeVarchar &&) = default;
                    ~cldeVarchar();

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
