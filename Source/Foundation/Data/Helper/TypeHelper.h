//
// Created by LE, Duc Anh on 7/1/15.
//

#ifndef CLDEPLUS_FOUNDATION_DATA_HELPER_TYPEHELPER_H
#define CLDEPLUS_FOUNDATION_DATA_HELPER_TYPEHELPER_H

#include "cldeplus_default"
#include "../TypeEnums.h"

namespace CLDEPlus {
    namespace Foundation {
        namespace Data{
            namespace Helper{
                struct TypeHelper {
                    static std::string CopyCategoryToString(const ValueCategory &category);
                    static std::string CopyValueTypeToString(const ValueType &type);
                };
            }
        }
    }
}



#endif //CLDEPLUS_FOUNDATION_DATA_HELPER_TYPEHELPER_H
