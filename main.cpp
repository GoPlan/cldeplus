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

    Application::Mapper::SequenceMap sequenceMap;
    Application::Mapper::SequenceLoader sequenceLoader;
    Infrastructure::MySqlSourceDriver mySqlDriver(sequenceMap);
    Architecture::EntityStore sequenceStore(sequenceMap, sequenceLoader, mySqlDriver);

    mySqlDriver.OptionArgs.Host = "dell-3020";
    mySqlDriver.OptionArgs.User = "cloud-e";
    mySqlDriver.OptionArgs.Pass = "cloud-e";
    mySqlDriver.OptionArgs.Base = "cloud-e";
    mySqlDriver.OptionArgs.Port = 3306;

    try {
        mySqlDriver.Connect();

        auto spAccountIdField_04 = std::make_shared<Architecture::Field>(sequenceMap.Id, (long) 4);
        auto spAccountIdentity_04 = std::make_shared<Architecture::Identity>()->setField(spAccountIdField_04);

        // GET
        auto spAccountSequence_04 = sequenceStore.Get(spAccountIdentity_04);
        cout << spAccountSequence_04->operator[]("Id")->getInt64() << endl;

        auto spNewIdField = std::make_shared<Architecture::Field>(sequenceMap.Id, (long) 7);
        auto spNewIdentity = std::make_shared<Architecture::Identity>()->setField(spNewIdField);

        // CREATE
        auto spNewSequence = sequenceStore.Create(spNewIdentity);
        spNewSequence->operator[]("UniqueName")->setCString("vinamilk");

        // SAVE
        sequenceStore.Save(spNewSequence);
        cout << spNewSequence->operator[]("Id")->getInt64() << " - " <<
        spNewSequence->operator[]("UniqueName")->getCString() << endl;

        // DELETE
        sequenceStore.Delete(spNewSequence);

    } catch (Infrastructure::Exception::MySqlSourceDriverException &mySqlDriverException) {
        cerr << mySqlDriverException.what() << endl;
    }

    mySqlDriver.Disconnect();

    return EXIT_SUCCESS;
};