//
// Created by LE, Duc Anh on 7/6/15.
//

#include "PreOrderLoader.h"

namespace Cloude {
    namespace AppTest {
        namespace Application {
            Foundation::SPtrIdentity PreOrderLoader::NextPrimaryKey() const {
                return std::shared_ptr<Foundation::Identity>();
            }
        }
    }
}
