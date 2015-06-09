//
// Created by LE, Duc Anh on 5/27/15.
//

#ifndef CLOUD_E_CPLUS_ACCOUNTMAP_H
#define CLOUD_E_CPLUS_ACCOUNTMAP_H

#include <string>
#include <Foundation/Column.h>
#include <Foundation/EntityMap.h>

namespace Cloude {
    namespace Application {
        namespace Mapper {
            class AccountMap : public Foundation::EntityMap {
            public:
                AccountMap();
                virtual ~AccountMap();
                AccountMap(const AccountMap &srcAccountMap) = default;
                AccountMap &operator=(const AccountMap &srcAccountMap) = default;

                static std::shared_ptr <Foundation::Column> Id;
                static std::shared_ptr <Foundation::Column> UniqueName;
                static std::shared_ptr <Foundation::Column> Email;
                static std::shared_ptr <Foundation::Column> AccountType;
                static std::shared_ptr <Foundation::Column> FirstName;
                static std::shared_ptr <Foundation::Column> LastName;
                static std::shared_ptr <Foundation::Column> Mobile;
                static std::shared_ptr <Foundation::Column> Address;
                static std::shared_ptr <Foundation::Column> City;

            protected:
                virtual std::string TableNameCore();
            };
        }
    }
}


#endif //CLOUD_E_CPLUS_ACCOUNTMAP_H
