//
// Created by LE, Duc Anh on 7/6/15.
//

#include "CustomerLoader.h"

namespace Cloude {
    namespace AppTest {
        namespace Application {
            Foundation::SPtrIdentity CustomerLoader::NextPrimaryKey() const {
                return std::shared_ptr<Foundation::Identity>();
            }
        }
    }
}

