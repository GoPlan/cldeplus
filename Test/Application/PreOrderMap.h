//
// Created by LE, Duc Anh on 7/1/15.
//

#ifndef CLOUD_E_PLUS_APPTEST_APPLICATION_ORDER_H
#define CLOUD_E_PLUS_APPTEST_APPLICATION_ORDER_H

#include "../../Source/Foundation/EntityMap.h"

namespace Cloude {
    namespace Test {
        namespace Application {

            class PreOrderMap : public Foundation::EntityMap {

            public:
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

            protected:
                virtual const std::string &TableNameCore() const override;
            };
        }
    }
}


#endif //CLOUD_E_PLUS_APPTEST_APPLICATION_ORDER_H
