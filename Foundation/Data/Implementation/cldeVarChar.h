//
// Created by LE, Duc Anh on 6/10/15.
//

#ifndef CLOUD_E_CPLUS_CLDEVARCHAR_H
#define CLOUD_E_CPLUS_CLDEVARCHAR_H

namespace Cloude {
    namespace Foundation {
        namespace Data {
            namespace Implementation {
                class cldeVarchar {
                public:
                    cldeVarchar() = default;
                    virtual ~cldeVarchar() = default;
                    cldeVarchar(const cldeVarchar &rhs) = default;
                    cldeVarchar &operator=(const cldeVarchar &rhs) = default;

                };
            }
        }
    }
}


#endif //CLOUD_E_CPLUS_CLDEVARCHAR_H
