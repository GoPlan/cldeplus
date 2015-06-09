//
// Created by LE, Duc Anh on 5/27/15.
//

#include "SequenceLoader.h"

namespace Cloude {
    namespace Application {
        namespace Mapper {

            std::shared_ptr<Foundation::Identity> SequenceLoader::NextPrimaryKey() const {
                return std::make_shared<Foundation::Identity>();
            }
        }
    }
}


