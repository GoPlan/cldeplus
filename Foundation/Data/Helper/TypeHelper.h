//
// Created by LE, Duc Anh on 7/1/15.
//

#ifndef CLOUD_E_PLUS_FOUNDATION_DATA_HELPER_TYPEHELPER_H
#define CLOUD_E_PLUS_FOUNDATION_DATA_HELPER_TYPEHELPER_H

#include <string>
#include <Foundation/Data/TypeEnums.h>

namespace Cloude{
    namespace Foundation {
        namespace Data{
            namespace Helper{
                struct TypeHelper {
                    static std::string CopyToString(const ValueCategory &category);
                    static std::string CopyToString(const ValueType &type);
                };
            }
        }
    }
}



#endif //CLOUD_E_PLUS_FOUNDATION_DATA_HELPER_TYPEHELPER_H
