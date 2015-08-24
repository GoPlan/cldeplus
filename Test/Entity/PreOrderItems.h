//
// Created by LE, Duc Anh on 7/15/15.
//

#ifndef CLOUD_E_PLUS_APPTEST_ENTITY_PREORDERITEMS_H
#define CLOUD_E_PLUS_APPTEST_ENTITY_PREORDERITEMS_H

#include <string>

namespace Cloude {
    namespace Test {
        namespace Entity {

            class PreOrderItems {

                int64_t id;
                int64_t orderId;
                int64_t itemId;
                double qty;
                double price;
                double amount;
                std::string comment;

            public:
                PreOrderItems() = default;
                PreOrderItems(const PreOrderItems &) = default;
                PreOrderItems(PreOrderItems &&) = default;
                PreOrderItems &operator=(const PreOrderItems &) = default;
                PreOrderItems &operator=(PreOrderItems &&) = default;
                ~PreOrderItems() = default;
            };
        }
    }
}

#endif //CLOUD_E_PLUS_APPTEST_ENTITY_PREORDERITEMS_H
