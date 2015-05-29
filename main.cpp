#include <cstdlib>
#include <iostream>

#include "Cloude.h"
#include "Architecture/Helper/SqlGenerator.h"
#include "Infrastructure/MySqlDriver.h"
#include "Application/Mapper/SequenceMap.h"
#include "Application/Mapper/SequenceLoader.h"

using namespace std;
using namespace Cloude;

int main(int argc, char **argv) {

    std::cout << "Running Debug" << std::endl;

    Application::Mapper::SequenceMap _sequenceMap;
    Application::Mapper::SequenceLoader _sequenceLoader;


    Infrastructure::MySqlDriver _mySqlDriver;
    _mySqlDriver.OptionArgs.Host = "dell-3020";
    _mySqlDriver.OptionArgs.User = "cloud-e";
    _mySqlDriver.OptionArgs.Pass = "cloud-e";
    _mySqlDriver.OptionArgs.DBase = "cloud-e";
    _mySqlDriver.OptionArgs.Port = 3306;

    _mySqlDriver.setGetStatement(Architecture::Helper::CreateGetPreparedQuery(_sequenceMap));
    _mySqlDriver.Connect();


    Architecture::EntityStore _sequenceStore(_sequenceMap, _sequenceLoader, _mySqlDriver);


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

    _mySqlDriver.Disconnect();

    return EXIT_SUCCESS;
};