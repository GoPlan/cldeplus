//
// Created by LE, Duc Anh on 6/10/15.
//

#ifndef CLOUD_E_CPLUS_CLDEVARCHAR_H
#define CLOUD_E_CPLUS_CLDEVARCHAR_H

#include <Foundation/Exception/cldeNonSupportedFunctionException.h>
#include <Foundation/Type/cldeCharacterValue.h>

namespace Cloude {
    namespace Foundation {
        namespace Type {
            namespace Implementation {
                class cldeVarchar : public cldeCharacterValue {
                public:
                    explicit cldeVarchar(size_t length);
                    explicit cldeVarchar(const char *value);
                    virtual ~cldeVarchar();
                    cldeVarchar(const cldeVarchar &rhs) = default;
                    cldeVarchar &operator=(const cldeVarchar &rhs) = default;

                    // cldeValue
                    virtual void *RawPointerToValueBuffer() override;

                    // IEquatable
                    virtual bool Equal(const Common::IEquatable &rhs) override;

                    // IPrintable
                    virtual const std::string CopyToString() const override;
                    virtual const std::string &ToString() const override;
                    virtual const char *ToCString() const override;

                private:
                    char *_value;

                    void init();
                    void init(const char *value);
                };
            }
        }
    }
}


#endif //CLOUD_E_CPLUS_CLDEVARCHAR_H
