//
// Created by LE, Duc Anh on 6/10/15.
//

#ifndef CLOUD_E_CPLUS_FOUNDATION_TYPE_IMPLEMENTATION_CLDETEXT_H
#define CLOUD_E_CPLUS_FOUNDATION_TYPE_IMPLEMENTATION_CLDETEXT_H

#include <Foundation/Type/cldeCharacterValue.h>

namespace Cloude {
    namespace Foundation {
        namespace Type {
            namespace Implementation {

                class cldeText : public cldeCharacterValue {
                    char *buffer;

                public:
                    cldeText() = default;
                    cldeText(const cldeText &) = default;
                    cldeText(cldeText &&) = default;
                    cldeText &operator=(const cldeText &) = default;
                    cldeText &operator=(cldeText &&) = default;
                    ~cldeText() = default;
                };
            }
        }
    }
}


#endif //CLOUD_E_CPLUS_FOUNDATION_TYPE_IMPLEMENTATION_CLDETEXT_H
