//
// Created by LE, Duc Anh on 7/8/15.
//

#ifndef CLOUD_E_PLUS_APPTEST_ENTITY_PREORDER_H
#define CLOUD_E_PLUS_APPTEST_ENTITY_PREORDER_H

#include <string>
#include <Relation/Relation.h>

namespace Cloude {
    namespace AppTest {
        namespace Entity {

            class PreOrder {

                int64_t id;
                int64_t customerId;
                std::string name;
                double total;

                Relation::LinkToOne _customer;

            public:
                PreOrder() = default;
                PreOrder(const PreOrder &) = default;
                PreOrder(PreOrder &&) = default;
                PreOrder &operator=(const PreOrder &) = default;
                PreOrder &operator=(PreOrder &&) = default;
                ~PreOrder() = default;

                // Accessors
                int64_t getId() const { return id; }
                int64_t getCustomerId() const { return customerId; }
                const std::string &getName() const { return name; }
                double getTotal() const { return total; }

                // Mutators
                void setId(int64_t id) { PreOrder::id = id; }
                void setCustomerId(int64_t customerId) { PreOrder::customerId = customerId; }
                void setName(const std::string &name) { PreOrder::name = name; }
                void setTotal(double total) { PreOrder::total = total; }
            };
        }
    }
}


#endif //CLOUD_E_PLUS_APPTEST_ENTITY_PREORDER_H
