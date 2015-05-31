#include <cstdlib>
#include <iostream>

#include <Cloude.h>
#include <Architecture/Helper/SqlGenerator.h>
#include <Application/Mapper/SequenceMap.h>
#include <Application/Mapper/SequenceLoader.h>
#include <Infrastructure/MySqlSourceDriver.h>
#include "Infrastructure/Exception/MySqlSourceDriverException.h"

using namespace std;
using namespace Cloude;

int main(int argc, char **argv) {

    Infrastructure::MySqlSourceDriver mySqlDriver;
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
    string strUpdateQuery = Architecture::Helper::CreateUpdatePreparedQuery(sequenceMap);
    string strDeleteQuery = Architecture::Helper::CreateDeletePreparedQuery(sequenceMap);

    cout << strGetQuery << endl;
    cout << strInsertQuery << endl;
    cout << strUpdateQuery << endl;
    cout << strDeleteQuery << endl;

    mySqlDriver.setGetStatement(strGetQuery);
    mySqlDriver.setInsertStatement(strInsertQuery);
    mySqlDriver.setUpdateStatement(strUpdateQuery);
    mySqlDriver.setDeleteStatement(strDeleteQuery);

    try {

        mySqlDriver.Connect();

        auto spAccountIdField_04 = std::make_shared<Architecture::Field>(sequenceMap.Id, (long) 4);
        auto spAccountIdentity_04 = std::make_shared<Architecture::Identity>()->SetField(spAccountIdField_04);
        auto spAccountSequence_04 = sequenceStore.Get(spAccountIdentity_04);

        cout << spAccountSequence_04->operator[]("Id")->getInt64() << " - " <<
        spAccountSequence_04->operator[]("UniqueName")->getCString() << endl;


        auto spNewIdField = std::make_shared<Architecture::Field>(sequenceMap.Id, (long) 7);
        auto spNewIdentity = std::make_shared<Architecture::Identity>()->SetField(spNewIdField);
        auto spNewSequence = sequenceStore.Create(spNewIdentity);

        spNewSequence->operator[]("UniqueName")->setCString("vinamilk");

        sequenceStore.Save(spNewSequence);

        cout << spNewSequence->operator[]("Id")->getInt64() << " - " <<
        spNewSequence->operator[]("UniqueName")->getCString() << endl;

        sequenceStore.Delete(spNewSequence);

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


    } catch (Infrastructure::Exception::MySqlSourceDriverException &mySqlDriverException) {

        cerr << mySqlDriverException.what() << endl;

    }

    mySqlDriver.Disconnect();

    return EXIT_SUCCESS;
};