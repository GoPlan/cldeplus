//
// Created by LE, Duc Anh on 6/24/15.
//

#ifndef CLOUD_E_PLUS_FOUNDATION_TYPE_IMPLEMENTATION_CLDEDATE_H
#define CLOUD_E_PLUS_FOUNDATION_TYPE_IMPLEMENTATION_CLDEDATE_H

namespace Cloude {
    namespace Foundation {
        namespace Type{
            namespace Implementation {

                class cldeDate {

                public:
                    cldeDate() = default;
                    cldeDate(const cldeDate &) = default;
                    cldeDate(cldeDate &&) = default;
                    cldeDate &operator=(const cldeDate &) = default;
                    cldeDate &operator=(cldeDate &&) = default;
                    virtual ~cldeDate() = default;
                };
            }
        }
    }
}


#endif //CLOUD_E_PLUS_FOUNDATION_TYPE_IMPLEMENTATION_CLDEDATE_H
