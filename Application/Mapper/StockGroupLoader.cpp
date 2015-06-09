//
// Created by GoPlan on 15/05/2015.
//

#include "StockGroupLoader.h"

namespace Cloude {
    namespace Application {
        namespace Mapper {

            StockGroupLoader::~StockGroupLoader() {
                //
            }

            std::shared_ptr<Identity> StockGroupLoader::NextPrimaryKey() const {
                return std::make_shared<Identity>();
            }
        }
    }
}
