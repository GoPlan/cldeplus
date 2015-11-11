/*

Copyright 2015 LE, Duc-Anh

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.

*/

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
