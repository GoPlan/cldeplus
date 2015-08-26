//
// Created by LE, Duc Anh on 8/26/15.
//

#ifndef CLOUD_E_PLUS_APPTEST_APPLICATION_MAPFACTORY_H
#define CLOUD_E_PLUS_APPTEST_APPLICATION_MAPFACTORY_H

#include <memory>

namespace Cloude {
    namespace Test {
        namespace Application {

            template<class T>
            std::shared_ptr<T> Create() {
                return std::make_shared<T>();
            }
        }
    }
}


#endif //CLOUD_E_PLUS_APPTEST_APPLICATION_MAPFACTORY_H