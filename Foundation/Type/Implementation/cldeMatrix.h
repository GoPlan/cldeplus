//
// Created by LE, Duc Anh on 6/10/15.
//

#ifndef CLOUD_E_CPLUS_FOUNDATION_TYPE_IMPLEMENTATION_CLDEMATRIX_H
#define CLOUD_E_CPLUS_FOUNDATION_TYPE_IMPLEMENTATION_CLDEMATRIX_H

#include <Foundation/Type/cldeValue.h>

namespace Cloude {
    namespace Foundation {
        namespace Type {
            namespace Implementation {

                class cldeMatrix : public cldeValue {

                public:
                    cldeMatrix() = default;
                    cldeMatrix(const cldeMatrix &) = default;
                    cldeMatrix(cldeMatrix &&) = default;
                    cldeMatrix &operator=(const cldeMatrix &) = default;
                    cldeMatrix &operator=(cldeMatrix &&) = default;
                    ~cldeMatrix() = default;
                };
            }
        }
    }
}

#endif //CLOUD_E_CPLUS_FOUNDATION_TYPE_IMPLEMENTATION_CLDEMATRIX_H
