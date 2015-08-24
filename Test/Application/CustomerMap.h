//
// Created by LE, Duc Anh on 7/1/15.
//

#ifndef CLOUD_E_PLUS_APPTEST_APPLICATION_CUSTOMERMAP_H
#define CLOUD_E_PLUS_APPTEST_APPLICATION_CUSTOMERMAP_H

#include <Foundation/Column.h>
#include <Foundation/EntityMap.h>

namespace Cloude {
    namespace Test {
        namespace Application {

            class CustomerMap : public Foundation::EntityMap {

            public:
                static std::string TableName;
                static Foundation::SPtrColumn Id;
                static Foundation::SPtrColumn FirstName;
                static Foundation::SPtrColumn LastName;
                static Foundation::SPtrColumn Email;
                static Foundation::SPtrColumn AddrStreet;
                static Foundation::SPtrColumn AddrZipCode;
                static Foundation::SPtrColumn AddrCity;
                static Foundation::SPtrColumn AddrCountry;

            public:
                CustomerMap();
                CustomerMap(const CustomerMap &) = default;
                CustomerMap(CustomerMap &&) = default;
                CustomerMap &operator=(const CustomerMap &) = default;
                CustomerMap &operator=(CustomerMap &&) = default;
                virtual ~CustomerMap() = default;

            protected:
                virtual const std::string &TableNameCore() const override;
            };
        }
    }
}


#endif //CLOUD_E_PLUS_APPTEST_APPLICATION_CUSTOMERMAP_H
