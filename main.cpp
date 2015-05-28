#include <cstdlib>
#include <iostream>

#include "Cloude.h"
#include "Application/Mapper/StockGroupLoader.h"
#include "Application/Mapper/StockGroupMap.h"
#include "Application/Mapper/SequenceMap.h"
#include "Application/Mapper/SequenceLoader.h"
#include "Architecture/Helper/SqlGenerator.h"
#include "Infrastructure/MySqlDriver.h"

using namespace std;
using namespace Cloude;

int main(int argc, char **argv) {

    std::cout << "Running Debug" << std::endl;

    Infrastructure::MySqlDriver _mySqlDriver;
    _mySqlDriver.setHost("dell-3020");
    _mySqlDriver.setUser("cloud-e");
    _mySqlDriver.setPass("cloud-e");
    _mySqlDriver.setDbase("cloud-e");
    _mySqlDriver.setPort(3306);

    Application::Mapper::StockGroupMap _stockGroupMap;
    Application::Mapper::StockGroupLoader _stockGroupLoader;
    Architecture::EntityStore _stockGroupStore(_stockGroupMap, _stockGroupLoader, _mySqlDriver);

    Application::Mapper::SequenceMap _sequenceMap;
    Application::Mapper::SequenceLoader _sequenceLoader;
    Architecture::EntityStore _sequenceStore(_sequenceMap, _sequenceLoader, _mySqlDriver);

    auto query = Cloude::Architecture::Helper::CreateGetPreparedQuery(_sequenceMap);
    _mySqlDriver.setQuery(query);

    std::cout << query << std::endl;


    auto spFieldId = make_shared<Architecture::Field>(_sequenceMap.Id, (long) 6);
    auto spIdentity = make_shared<Architecture::Identity>()->SetField(spFieldId);
    auto spSequence = (std::shared_ptr<Architecture::Entity>)_sequenceStore.Get(spIdentity);

    std::cout << spSequence->GetField("Id")->getInt64() << " - " << spSequence->GetField("SequenceStart")->getInt64() << std::endl;


    return EXIT_SUCCESS;
};