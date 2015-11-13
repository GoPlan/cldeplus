//
// Created by LE, Duc Anh on 8/26/15.
//

#ifndef CLDEPLUS_APPTEST_APPLICATION_MAPFACTORY_H
#define CLDEPLUS_APPTEST_APPLICATION_MAPFACTORY_H

#include "../../Source/Portable/CommonTypes.h"

namespace CLDEPlus {
    namespace Test {
        namespace Application {

            template<class T>
            CLDEPlus::shared_ptr<T> Create() {
                return CLDEPlus::cldeplus_make_shared<T>();
            }

            template <class T>
            CLDEPlus::shared_ptr<T> Share(unique_ptr<T> uptrT){
                return CLDEPlus::shared_ptr<T>(uptrT);
            }
        }
    }
}


#endif //CLDEPLUS_APPTEST_APPLICATION_MAPFACTORY_H
