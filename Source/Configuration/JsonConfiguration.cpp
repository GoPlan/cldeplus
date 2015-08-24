//
// Created by LE, Duc Anh on 8/24/15.
//

#include "JsonConfiguration.h"

namespace Cloude {
    namespace Configuration {

        Foundation::SPtrEntityMap JsonConfiguration::CreateSPtrEntityMap(std::string const &jsonEntityMap) {
            return std::shared_ptr<Foundation::EntityMap>();
        }

        Foundation::Query::SPtrCriteria JsonConfiguration::CreateSPtrCriteria(std::string const &jsonCriteria) {
            return std::shared_ptr<Foundation::Query::Criteria>();
        }
    }
}


