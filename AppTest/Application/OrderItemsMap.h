//
// Created by LE, Duc Anh on 7/3/15.
//

#ifndef CLOUD_E_PLUS_APPTEST_APPLICATION_ORDERITEMSMAP_H
#define CLOUD_E_PLUS_APPTEST_APPLICATION_ORDERITEMSMAP_H

#include <Foundation/EntityMap.h>

namespace Cloude {
    namespace AppTest {
        namespace Application {

            class OrderItemsMap : public Foundation::EntityMap {

            public:
                static std::string TableName;
                static Foundation::SPtrColumn Id;
                static Foundation::SPtrColumn OrderId;
                static Foundation::SPtrColumn ItemId;
                static Foundation::SPtrColumn Qty;
                static Foundation::SPtrColumn Price;
                static Foundation::SPtrColumn Ammount;

            public:
                OrderItemsMap();
                OrderItemsMap(const OrderItemsMap &) = default;
                OrderItemsMap(OrderItemsMap &&) = default;
                OrderItemsMap &operator=(const OrderItemsMap &) = default;
                OrderItemsMap &operator=(OrderItemsMap &&) = default;
                ~OrderItemsMap() = default;

            protected:
                virtual const std::string &TableNameCore() const override;

            };
        }
    }
}

#endif //CLOUD_E_PLUS_APPTEST_APPLICATION_ORDERITEMSMAP_H
