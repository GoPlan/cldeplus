//
// Created by LE, Duc Anh on 7/1/15.
//

#ifndef CLOUD_E_PLUS_APPTEST_APPLICATION_ORDER_H
#define CLOUD_E_PLUS_APPTEST_APPLICATION_ORDER_H

#include <Foundation/EntityMap.h>

namespace Cloude {
    namespace AppTest {
        namespace Application {

            class OrderMap : public Foundation::EntityMap {

            public:
                static std::string TableName;
                static Foundation::SPtrColumn Id;
                static Foundation::SPtrColumn Name;
                static Foundation::SPtrColumn CustId;
                static Foundation::SPtrColumn Total;

            public:
                OrderMap();
                OrderMap(const OrderMap &) = default;
                OrderMap(OrderMap &&) = default;
                OrderMap &operator=(const OrderMap &) = default;
                OrderMap &operator=(OrderMap &&) = default;
                virtual ~OrderMap() = default;

            protected:
                virtual const std::string &TableNameCore() const override;
            };
        }
    }
}


#endif //CLOUD_E_PLUS_APPTEST_APPLICATION_ORDER_H
