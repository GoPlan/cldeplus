//
// Created by LE, Duc Anh on 8/24/15.
//

#ifndef CLOUD_E_PLUS_CONFIGURATION_JSONCONFIGURATION_H
#define CLOUD_E_PLUS_CONFIGURATION_JSONCONFIGURATION_H

#include "CLDEParser.h"
#include "../Foundation/EntityMap.h"
#include "../Foundation/Query/Criteria.h"

namespace Cloude {
    namespace Configuration {

        class JsonConfiguration {

            CLDEParser::Scanner _scanner;
            CLDEParser::Parser _parser;

        public:
            JsonConfiguration() = default;
            JsonConfiguration(const JsonConfiguration &) = default;
            JsonConfiguration(JsonConfiguration &&) = default;
            JsonConfiguration &operator=(const JsonConfiguration &) = default;
            JsonConfiguration &operator=(JsonConfiguration &&) = default;
            virtual ~JsonConfiguration() = default;

            Foundation::SPtrEntityMap CreateSPtrEntityMap(std::string const &jsonEntityMap);
            Foundation::Query::SPtrCriteria CreateSPtrCriteria(std::string const &jsonCriteria);
        };
    }
}


#endif //CLOUD_E_PLUS_CONFIGURATION_JSONCONFIGURATION_H
