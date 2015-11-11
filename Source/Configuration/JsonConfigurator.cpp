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

#include "JsonConfigurator.h"

namespace Cloude {
    namespace Configuration {

        JsonConfigurator::JsonConfigurator()
                : _scanner{}, _parser{CLDEParser::Parsing::ParserFactory::CreateJsonDerivative()} {
            //
            init();
        }

        void JsonConfigurator::init() {
            _scanner.Tokenizers().push_back(CLDEParser::Scanning::TokenizerFactory::CreateSpace());
            _scanner.Tokenizers().push_back(CLDEParser::Scanning::TokenizerFactory::CreateTab());
            _scanner.Tokenizers().push_back(CLDEParser::Scanning::TokenizerFactory::CreateCarriageReturn());
            _scanner.Tokenizers().push_back(CLDEParser::Scanning::TokenizerFactory::CreateLineFeed());
            _scanner.Tokenizers().push_back(CLDEParser::Scanning::TokenizerFactory::CreateNull());
            _scanner.Tokenizers().push_back(CLDEParser::Scanning::TokenizerFactory::CreateBoolTrue());
            _scanner.Tokenizers().push_back(CLDEParser::Scanning::TokenizerFactory::CreateBoolFalse());
            _scanner.Tokenizers().push_back(CLDEParser::Scanning::TokenizerFactory::CreateNumberInteger());
            _scanner.Tokenizers().push_back(CLDEParser::Scanning::TokenizerFactory::CreateNumber());
            _scanner.Tokenizers().push_back(CLDEParser::Scanning::TokenizerFactory::CreateId());
            _scanner.Tokenizers().push_back(CLDEParser::Scanning::TokenizerFactory::CreateString());
            _scanner.Tokenizers().push_back(CLDEParser::Scanning::TokenizerFactory::CreateColon());
            _scanner.Tokenizers().push_back(CLDEParser::Scanning::TokenizerFactory::CreateComma());
            _scanner.Tokenizers().push_back(CLDEParser::Scanning::TokenizerFactory::CreateCurlyBraceOpen());
            _scanner.Tokenizers().push_back(CLDEParser::Scanning::TokenizerFactory::CreateCurlyBraceClosing());
            _scanner.Tokenizers().push_back(CLDEParser::Scanning::TokenizerFactory::CreateBracketOpen());
            _scanner.Tokenizers().push_back(CLDEParser::Scanning::TokenizerFactory::CreateBracketClosing());
        }

        CLDEParser::Parsing::Json::SPtrJsonEntity JsonConfigurator::parse(string const &json) const {

            // Scanning
            auto tokens = _scanner.Scan(json);
            auto filteredCodes = CLDEParser::Scanning::TokenHelper::DefaultFilterCodes();
            auto filteredTokens = CLDEParser::Scanning::TokenHelper::Filter(filteredCodes, tokens);

            // Parsing
            auto sptrSyntaxModel = _parser.ParseCast<CLDEParser::Parsing::Json::JsonSyntaxModel>(filteredTokens);
            auto sptrJsonEntity = sptrSyntaxModel->CreateSPtrJsonEnity();

            return sptrJsonEntity;
        }

        Foundation::SPtrEntityMap JsonConfigurator::CreateSPtrEntityMap(string const &jsonEntityMap) {
            return shared_ptr<Foundation::EntityMap>();
        }

        Foundation::Query::SPtrCriteria JsonConfigurator::CreateSPtrCriteria(string const &jsonCriteria) {
            return shared_ptr<Foundation::Query::Criteria>();
        }
    }
}


