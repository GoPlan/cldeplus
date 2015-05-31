//
// Created by LE, Duc-Anh on 5/24/15.
//

#ifndef CLOUD_E_CPLUS_STOREGETTEST_H
#define CLOUD_E_CPLUS_STOREGETTEST_H

#include <memory>
#include <gtest/gtest.h>
#include <Application/Mapper/SequenceMap.h>
#include <Architecture/Helper/SqlGenerator.h>
#include <Application/Mapper/SequenceLoader.h>

#include "StoreSimple.h"

namespace Cloude {
    namespace AppTest {
        namespace Store {

            TEST_F(StoreSimple, GetEntity){
                std::cout << "Running Debug" << std::endl;

                Application::Mapper::SequenceMap _sequenceMap;
                Application::Mapper::SequenceLoader _sequenceLoader;


                Infrastructure::MySqlConnector _mySqlDriver;
                _mySqlDriver.OptionArgs.Host = "dell-3020";
                _mySqlDriver.OptionArgs.User = "cloud-e";
                _mySqlDriver.OptionArgs.Pass = "cloud-e";
                _mySqlDriver.OptionArgs.Base = "cloud-e";
                _mySqlDriver.OptionArgs.Port = 3306;

                _mySqlDriver.setGetStatement(Architecture::Helper::CreateGetPreparedQuery(_sequenceMap));
                _mySqlDriver.Connect();


                Architecture::EntityStore _sequenceStore(_sequenceMap, _sequenceLoader, _mySqlDriver);


                auto spAccountIdField = std::make_shared<Architecture::Field>(_sequenceMap.Id, (long) 4);
                auto spAccountIdentity = std::make_shared<Architecture::Identity>()->SetField(spAccountIdField);
                auto spAccountSequence = _sequenceStore.Get(spAccountIdentity);

                std::cout << spAccountSequence->GetField("Id")->getInt64()
                << " - " << spAccountSequence->GetField("UniqueName")->getCString()
                << " - " << spAccountSequence->GetField("SequenceStart")->getInt64()
                << " - " << spAccountSequence->GetField("SequenceCurrent")->getInt64()
                << " - " << spAccountSequence->GetField("SequenceIncrement")->getInt64()
                << std::endl;


                auto spEnquiryIdField = std::make_shared<Architecture::Field>(_sequenceMap.Id, (long) 5);
                auto spEnquiryIdentity = std::make_shared<Architecture::Identity>()->SetField(spEnquiryIdField);
                auto spEnquirySequence = _sequenceStore.Get(spEnquiryIdentity);

                std::cout << spEnquirySequence->GetField("Id")->getInt64()
                << " - " << spEnquirySequence->GetField("UniqueName")->getCString()
                << " - " << spEnquirySequence->GetField("SequenceStart")->getInt64()
                << " - " << spEnquirySequence->GetField("SequenceCurrent")->getInt64()
                << " - " << spEnquirySequence->GetField("SequenceIncrement")->getInt64()
                << std::endl;


                auto spVnHoseIdField = std::make_shared<Architecture::Field>(_sequenceMap.Id, (long) 6);
                auto spVnHoseIdentity = std::make_shared<Architecture::Identity>()->SetField(spVnHoseIdField);
                auto spVnHoseSequence = _sequenceStore.Get(spVnHoseIdentity);

                std::cout << spVnHoseSequence->GetField("Id")->getInt64()
                << " - " << spVnHoseSequence->GetField("UniqueName")->getCString()
                << " - " << spVnHoseSequence->GetField("SequenceStart")->getInt64()
                << " - " << spVnHoseSequence->GetField("SequenceCurrent")->getInt64()
                << " - " << spVnHoseSequence->GetField("SequenceIncrement")->getInt64()
                << std::endl;

                _mySqlDriver.Disconnect();
            }
        }
    }
}


#endif //CLOUD_E_CPLUS_STOREGETTEST_H
