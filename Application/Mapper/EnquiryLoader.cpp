//
// Created by LE, Duc Anh on 6/5/15.
//

#include "EnquiryLoader.h"

namespace Cloude {
    namespace Application {
        namespace Mapper {
            std::shared_ptr<Identity> EnquiryLoader::NextPrimaryKey() const {
                auto identity = std::make_shared<Identity>();
                return identity;
            }
        }
    }
}


