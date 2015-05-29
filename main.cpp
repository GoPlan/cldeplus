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


    auto spAccountIdField = make_shared<Architecture::Field>(_sequenceMap.Id, (long) 4);
    auto spAccountIdentity = make_shared<Architecture::Identity>()->SetField(spAccountIdField);
    auto spAccountSequence = _sequenceStore.Get(spAccountIdentity);

    std::cout << spAccountSequence->GetField("Id")->getInt64()
    << " - " << spAccountSequence->GetField("UniqueName")->getCString()
    << " - " << spAccountSequence->GetField("SequenceStart")->getInt64()
    << " - " << spAccountSequence->GetField("SequenceCurrent")->getInt64()
    << " - " << spAccountSequence->GetField("SequenceIncrement")->getInt64()
    << std::endl;


    auto spEnquiryIdField = make_shared<Architecture::Field>(_sequenceMap.Id, (long) 5);
    auto spEnquiryIdentity = make_shared<Architecture::Identity>()->SetField(spEnquiryIdField);
    auto spEnquirySequence = _sequenceStore.Get(spEnquiryIdentity);

    std::cout << spEnquirySequence->GetField("Id")->getInt64()
    << " - " << spEnquirySequence->GetField("UniqueName")->getCString()
    << " - " << spEnquirySequence->GetField("SequenceStart")->getInt64()
    << " - " << spEnquirySequence->GetField("SequenceCurrent")->getInt64()
    << " - " << spEnquirySequence->GetField("SequenceIncrement")->getInt64()
    << std::endl;


    auto spVnHoseIdField = make_shared<Architecture::Field>(_sequenceMap.Id, (long) 6);
    auto spVnHoseIdentity = make_shared<Architecture::Identity>()->SetField(spVnHoseIdField);
    auto spVnHoseSequence = _sequenceStore.Get(spVnHoseIdentity);

    std::cout << spVnHoseSequence->GetField("Id")->getInt64()
    << " - " << spVnHoseSequence->GetField("UniqueName")->getCString()
    << " - " << spVnHoseSequence->GetField("SequenceStart")->getInt64()
    << " - " << spVnHoseSequence->GetField("SequenceCurrent")->getInt64()
    << " - " << spVnHoseSequence->GetField("SequenceIncrement")->getInt64()
    << std::endl;

    return EXIT_SUCCESS;
};