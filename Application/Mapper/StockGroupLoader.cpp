//
// Created by GoPlan on 15/05/2015.
//

#include "StockGroupLoader.h"

using namespace std;
using namespace Cloude::Framework;

namespace Cloude {
    namespace Application {
        namespace Mapper {

            StockGroupLoader::~StockGroupLoader() {
                //
            }

            std::shared_ptr<Identity> StockGroupLoader::NextPrimaryKey() const {
                return make_shared<Identity>();
            }
        }
    }
}
