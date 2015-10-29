//
// Created by LE, Duc Anh on 8/26/15.
//

#ifndef CLDEPLUS_APPTEST_APPLICATION_MAPFACTORY_H
#define CLDEPLUS_APPTEST_APPLICATION_MAPFACTORY_H

#include <memory>

namespace CLDEPlus {
    namespace Test {
        namespace Application {

            template<class T>
            std::shared_ptr<T> Create() {
                return std::make_shared<T>();
            }

            template <class T>
            std::shared_ptr<T> Share(std::unique_ptr<T> uptrT){
                return std::shared_ptr<T>(uptrT);
            }
        }
    }
}


#endif //CLDEPLUS_APPTEST_APPLICATION_MAPFACTORY_H
