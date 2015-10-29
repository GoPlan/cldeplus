//
// Created by LE, Duc Anh on 7/1/15.
//

#ifndef CLDEPLUS_APPTEST_APPLICATION_ORDER_H
#define CLDEPLUS_APPTEST_APPLICATION_ORDER_H

#include "../../Source/Foundation/EntityMap.h"

namespace CLDEPlus {
    namespace Test {
        namespace Application {

            class PreOrderMap : public Foundation::EntityMap {

                static std::string TableName;
                static Foundation::SPtrColumn Id;
                static Foundation::SPtrColumn Name;
                static Foundation::SPtrColumn CustId;
                static Foundation::SPtrColumn Total;

            public:
                PreOrderMap();
                PreOrderMap(const PreOrderMap &) = default;
                PreOrderMap(PreOrderMap &&) = default;
                PreOrderMap &operator=(const PreOrderMap &) = default;
                PreOrderMap &operator=(PreOrderMap &&) = default;
                ~PreOrderMap() = default;
            };

            using SPtrPreOrderMap = std::shared_ptr<PreOrderMap>;
        }
    }
}


#endif //CLDEPLUS_APPTEST_APPLICATION_ORDER_H
