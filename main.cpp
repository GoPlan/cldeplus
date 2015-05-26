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
    StockGroupLoader _stockGroupLoader(_stockGroupMap.getColumnsMap());
    EntityStore _entityStore(_stockGroupMap, _stockGroupLoader);



    return EXIT_SUCCESS;
};