#include <iostream>
#include "Cloude.h"
#include "Application/Mapper/StockGroupLoader.h"
#include "Application/Mapper/StockGroupMap.h"


int main(int argc, char **argv) {

    std::cout << "Running Debug" << std::endl;


    Cloude::Application::Mapper::StockGroupMap _stockGroupMap;
    Cloude::Application::Mapper::StockGroupLoader _stockGroupLoader;
    Cloude::Architecture::EntityStore _entityStore(_stockGroupMap, _stockGroupLoader);


    std::string codeName = "Code";
    std::string codeSourceName = "Code";
    std::string codeValue = "VNM";


    auto spColumnId = std::make_shared<Cloude::Architecture::Column>(codeName,
                                                                     codeSourceName,
                                                                     Cloude::Architecture::Enumeration::DbType::String);


    auto spFieldId = std::make_shared<Cloude::Architecture::Field>(spColumnId,
                                                                   codeValue);


    std::shared_ptr<Cloude::Architecture::Identity> spIdentity =
            std::make_shared<Cloude::Architecture::Identity>()->SetField(spFieldId);

    std::shared_ptr<Cloude::Architecture::Entity> spIdentEntity = spIdentity->getSpEntity();
    std::shared_ptr<Cloude::Architecture::Field> spIdentEntityField = spIdentEntity->operator[](codeName);

    std::cout << spIdentEntityField->getString() << std::endl;


    return EXIT_SUCCESS;
};