//
// Created by LE, Duc Anh on 8/24/15.
//

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

        CLDEParser::Parsing::Json::SPtrJsonEntity JsonConfigurator::parse(std::string const &json) const {

            // Scanning
            auto tokens = _scanner.Scan(json);
            auto filteredCodes = CLDEParser::Scanning::TokenHelper::DefaultFilterCodes();
            auto filteredTokens = CLDEParser::Scanning::TokenHelper::Filter(filteredCodes, tokens);

            // Parsing
            auto sptrSyntaxModel = _parser.ParseCast<CLDEParser::Parsing::Json::JsonSyntaxModel>(filteredTokens);
            auto sptrJsonEntity = sptrSyntaxModel->CreateSPtrJsonEnity();

            return sptrJsonEntity;
        }

        Foundation::SPtrEntityMap JsonConfigurator::CreateSPtrEntityMap(std::string const &jsonEntityMap) {
            return std::shared_ptr<Foundation::EntityMap>();
        }

        Foundation::Query::SPtrCriteria JsonConfigurator::CreateSPtrCriteria(std::string const &jsonCriteria) {
            return std::shared_ptr<Foundation::Query::Criteria>();
        }
    }
}

