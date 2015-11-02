//
// Created by LE, Duc Anh on 8/24/15.
//

#ifndef CLDEPLUS_CONFIGURATION_JSONCONFIGURATOR_H
#define CLDEPLUS_CONFIGURATION_JSONCONFIGURATOR_H

#include <cldeparser/CldeParser.h>
#include "../Foundation/EntityMap.h"
#include "../Foundation/Query/Criteria.h"

namespace Cloude {
    namespace Configuration {

        class JsonConfigurator {

            CLDEParser::Scanner _scanner;
            CLDEParser::ParserSingle _parser;

            void init();
            CLDEParser::Parsing::Json::SPtrJsonEntity parse(string const &json) const;

        public:
            JsonConfigurator();
            JsonConfigurator(const JsonConfigurator &) = default;
            JsonConfigurator(JsonConfigurator &&) = default;
            JsonConfigurator &operator=(const JsonConfigurator &) = default;
            JsonConfigurator &operator=(JsonConfigurator &&) = default;
            virtual ~JsonConfigurator() = default;

            virtual Foundation::SPtrEntityMap CreateSPtrEntityMap(string const &jsonEntityMap);
            virtual Foundation::Query::SPtrCriteria CreateSPtrCriteria(string const &jsonCriteria);
        };
    }
}


#endif //CLDEPLUS_CONFIGURATION_JSONCONFIGURATOR_H
