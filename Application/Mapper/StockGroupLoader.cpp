//
// Created by GoPlan on 15/05/2015.
//

#include <random>
#include "StockGroupLoader.h"
#include "../../Architecture/Exception/NonSupportedDataTypeException.h"

using namespace std;
using namespace Cloude::Architecture;

namespace Cloude {
    namespace Application {
        namespace Mapper {

            StockGroupLoader::StockGroupLoader(const unordered_map<string, shared_ptr<Column>> &columnsMap) {
                //
            }

            StockGroupLoader::~StockGroupLoader() {
                //
            }

            std::unique_ptr<Identity> StockGroupLoader::NextPrimaryKey() {
                return std::unique_ptr<Identity>(nullptr);
            }

            void StockGroupLoader::LoadEntity(std::shared_ptr<Identity> &identity) {
                //
            }
        }
    }
}
