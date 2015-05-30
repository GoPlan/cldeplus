#include <cstdlib>
#include <iostream>
#include <Infrastructure/MySqlDriver.h>
#include <Infrastructure/Exception/MySqlDriverException.h>

#include "Cloude.h"
#include "Architecture/Helper/SqlGenerator.h"
#include "Application/Mapper/SequenceMap.h"
#include "Application/Mapper/SequenceLoader.h"

using namespace std;
using namespace Cloude;

int main(int argc, char **argv) {

    Infrastructure::MySqlDriver mySqlDriver;
    Application::Mapper::SequenceMap sequenceMap;
    Application::Mapper::SequenceLoader sequenceLoader;
    Architecture::EntityStore sequenceStore(sequenceMap, sequenceLoader, mySqlDriver);

    mySqlDriver.OptionArgs.Host = "dell-3020";
    mySqlDriver.OptionArgs.User = "cloud-e";
    mySqlDriver.OptionArgs.Pass = "cloud-e";
    mySqlDriver.OptionArgs.Base = "cloud-e";
    mySqlDriver.OptionArgs.Port = 3306;

    string strGetQuery = Architecture::Helper::CreateGetPreparedQuery(sequenceMap);
    string strInsertQuery = Architecture::Helper::CreateInsertPreparedQuery(sequenceMap);

    cout << strGetQuery << endl;
    cout << strInsertQuery << endl;

    mySqlDriver.setGetStatement(strGetQuery);
    mySqlDriver.setInsertStatement(strInsertQuery);
    mySqlDriver.Connect();

    auto spAccountIdField_04 = std::make_shared<Architecture::Field>(sequenceMap.Id, (long) 4);
    auto spAccountIdentity_04 = std::make_shared<Architecture::Identity>()->SetField(spAccountIdField_04);
    auto spAccountSequence_04 = sequenceStore.Get(spAccountIdentity_04);

    cout << spAccountSequence_04->operator[]("Id")->getInt64() << " - " <<
    spAccountSequence_04->operator[]("UniqueName")->getCString() << endl;

    try {

        auto spNewIdField = std::make_shared<Architecture::Field>(sequenceMap.Id, (long) 7);
        auto spNewIdentity = std::make_shared<Architecture::Identity>()->SetField(spNewIdField);
        auto spNewSequence = sequenceStore.Create(spNewIdentity);

        cout << spNewSequence->operator[]("Id")->getInt64() << endl;

    } catch (Infrastructure::Exception::MySqlDriverException &mySqlException) {
        cout << mySqlException.what() << endl;
    }

    auto spAccountIdField_05 = std::make_shared<Architecture::Field>(sequenceMap.Id, (long) 5);
    auto spAccountIdentity_05 = std::make_shared<Architecture::Identity>()->SetField(spAccountIdField_05);
    auto spAccountSequence_05 = sequenceStore.Get(spAccountIdentity_05);

    cout << spAccountSequence_05->operator[]("Id")->getInt64() << " - " <<
    spAccountSequence_05->operator[]("UniqueName")->getCString() << endl;

    auto spAccountIdField_06 = std::make_shared<Architecture::Field>(sequenceMap.Id, (long) 6);
    auto spAccountIdentity_06 = std::make_shared<Architecture::Identity>()->SetField(spAccountIdField_06);
    auto spAccountSequence_06 = sequenceStore.Get(spAccountIdentity_06);

    cout << spAccountSequence_06->operator[]("Id")->getInt64() << " - " <<
    spAccountSequence_06->operator[]("UniqueName")->getCString() << endl;

    mySqlDriver.Disconnect();

    return EXIT_SUCCESS;
};