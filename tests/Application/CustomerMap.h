//
// Created by LE, Duc Anh on 7/1/15.
//

#ifndef CLDEPLUS_APPTEST_APPLICATION_CUSTOMERMAP_H
#define CLDEPLUS_APPTEST_APPLICATION_CUSTOMERMAP_H

#include <cldeplus/Foundation/EntityMap.h>

namespace CLDEPlus {
    namespace Test {
        namespace Application {

            class CustomerMap : public Foundation::EntityMap {

                static string TableName;
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
            };
        }
    }
}


#endif //CLDEPLUS_APPTEST_APPLICATION_CUSTOMERMAP_H
