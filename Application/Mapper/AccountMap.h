//
// Created by LE, Duc Anh on 5/27/15.
//

#ifndef CLOUD_E_CPLUS_ACCOUNTMAP_H
#define CLOUD_E_CPLUS_ACCOUNTMAP_H

#include "Framework/Column.h"
#include "Framework/EntityMap.h"

namespace Cloude {
    namespace Application {
        namespace Mapper {
            class AccountMap : public Framework::EntityMap {
            public:
                AccountMap();
                virtual ~AccountMap();
                AccountMap(const AccountMap &srcAccountMap) = default;
                AccountMap &operator=(const AccountMap &srcAccountMap) = default;

                static std::shared_ptr<Framework::Column> Id;
                static std::shared_ptr<Framework::Column> UniqueName;
                static std::shared_ptr<Framework::Column> Email;
                static std::shared_ptr<Framework::Column> AccountType;
                static std::shared_ptr<Framework::Column> FirstName;
                static std::shared_ptr<Framework::Column> LastName;
                static std::shared_ptr<Framework::Column> Mobile;
                static std::shared_ptr<Framework::Column> Address;
                static std::shared_ptr<Framework::Column> City;

            protected:
                virtual std::string TableNameCore();
            };
        }
    }
}


#endif //CLOUD_E_CPLUS_ACCOUNTMAP_H
