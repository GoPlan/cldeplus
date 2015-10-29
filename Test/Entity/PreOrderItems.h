//
// Created by LE, Duc Anh on 7/15/15.
//

#ifndef CLDEPLUS_APPTEST_ENTITY_PREORDERITEMS_H
#define CLDEPLUS_APPTEST_ENTITY_PREORDERITEMS_H

#include <string>

namespace CLDEPlus {
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

#endif //CLDEPLUS_APPTEST_ENTITY_PREORDERITEMS_H
