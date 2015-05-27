#include <cstdlib>
#include <iostream>
#include "Cloude.h"
#include "Application/Mapper/StockGroupLoader.h"
#include "Application/Mapper/StockGroupMap.h"
#include "Architecture/Helper/SqlGenerator.h"
#include "Infrastructure/MySqlDriver.h"

using Column = Cloude::Architecture::Column;
using Field = Cloude::Architecture::Field;
using Identity = Cloude::Architecture::Identity;
using Entity = Cloude::Architecture::Entity;
using EnumDbType = Cloude::Architecture::Enumeration::DbType;

using StockGroupMap = Cloude::Application::Mapper::StockGroupMap;
using StockGroupLoader = Cloude::Application::Mapper::StockGroupLoader;
using EntityStore = Cloude::Architecture::EntityStore;

using MySqlDriver = Cloude::Infrastructure::MySqlDriver;

int main(int argc, char **argv) {

    std::cout << "Running Debug" << std::endl;

    MySqlDriver mySqlDriver;
    StockGroupMap _stockGroupMap;
    StockGroupLoader _stockGroupLoader(_stockGroupMap.getColumnsMap());
    EntityStore _entityStore(_stockGroupMap, _stockGroupLoader, mySqlDriver);

    std::string columns = Cloude::Architecture::Helper::CreateGetPreparedQuery(_stockGroupMap);
    std::cout<< columns << std::endl;

    return EXIT_SUCCESS;
};