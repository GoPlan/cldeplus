//
// Created by LE, Duc Anh on 5/27/15.
//

#ifndef CLOUD_E_CPLUS_ACCOUNTMAP_H
#define CLOUD_E_CPLUS_ACCOUNTMAP_H

#include "Architecture/Column.h"
#include "Architecture/EntityMap.h"

namespace Cloude {
    namespace Application {
        namespace Mapper {
            class AccountMap : public Architecture::EntityMap {
            public:
                AccountMap();
                virtual ~AccountMap();
                AccountMap(const AccountMap &srcAccountMap) = default;
                AccountMap &operator=(const AccountMap &srcAccountMap) = default;

                static std::shared_ptr<Architecture::Column> Id;
                static std::shared_ptr<Architecture::Column> UniqueName;
                static std::shared_ptr<Architecture::Column> Email;
                static std::shared_ptr<Architecture::Column> AccountType;
                static std::shared_ptr<Architecture::Column> FirstName;
                static std::shared_ptr<Architecture::Column> LastName;
                static std::shared_ptr<Architecture::Column> Mobile;
                static std::shared_ptr<Architecture::Column> Address;
                static std::shared_ptr<Architecture::Column> City;

            protected:
                virtual std::string TableNameCore();
            };
        }
    }
}


#endif //CLOUD_E_CPLUS_ACCOUNTMAP_H
