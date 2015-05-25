#include <cstdlib>
#include <iostream>
#include "Cloude.h"
#include "Application/Mapper/StockGroupLoader.h"
#include "Application/Mapper/StockGroupMap.h"

using Column = Cloude::Architecture::Column;
using Field = Cloude::Architecture::Field;
using Identity = Cloude::Architecture::Identity;
using Entity = Cloude::Architecture::Entity;
using EnumDbType = Cloude::Architecture::Enumeration::DbType;

using StockGroupMap = Cloude::Application::Mapper::StockGroupMap;
using StockGroupLoader = Cloude::Application::Mapper::StockGroupLoader;
using EntityStore = Cloude::Architecture::EntityStore;

int main(int argc, char **argv) {

    std::cout << "Running Debug" << std::endl;

    StockGroupMap _stockGroupMap;
    StockGroupLoader _stockGroupLoader;
    EntityStore _entityStore(_stockGroupMap, _stockGroupLoader);

    std::string codeName = "Code";
    std::string codeSourceName = "Code";
    std::string codeValue = "VNM";

    auto spColumnId = std::make_shared<Column>(codeName,
                                               codeSourceName,
                                               EnumDbType::String);

    auto spFieldId = std::make_shared<Field>(spColumnId,
                                             codeValue);

    std::shared_ptr<Identity> spIdentity = std::make_shared<Identity>()->SetField(spFieldId);
    std::shared_ptr<Entity> spIdentEntity = spIdentity->getEntity();
    std::shared_ptr<Field> spIdentEntityField = spIdentEntity->operator[](codeName);

    std::cout << spIdentEntityField->getString() << std::endl;

    return EXIT_SUCCESS;
};