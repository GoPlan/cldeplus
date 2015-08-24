//
// Created by LE, Duc Anh on 7/8/15.
//

#ifndef CLOUD_E_PLUS_APPTEST_ENTITY_PREORDER_H
#define CLOUD_E_PLUS_APPTEST_ENTITY_PREORDER_H

#include <string>
#include "../../Source/Relation/Relation.h"

namespace Cloude {
    namespace Test {
        namespace Entity {

            class PreOrder {

                int64_t _id;
                int64_t _custId;
                std::string _name;
                double _total;

                Relation::SPtrLinkToOne _linkToCustomer;

            public:
                PreOrder() = default;
                PreOrder(const PreOrder &) = default;
                PreOrder(PreOrder &&) = default;
                PreOrder &operator=(const PreOrder &) = default;
                PreOrder &operator=(PreOrder &&) = default;
                ~PreOrder() = default;

                // Accessors
                int64_t getId() const { return _id; }
                int64_t getCustomerId() const { return _custId; }
                double getTotal() const { return _total; }
                const std::string &getName() const { return _name; }
                const Relation::SPtrLinkToOne &LinkToCustomer() const { return _linkToCustomer; }

                // Mutators
                void setId(int64_t id) { _id = id; }
                void setCustomerId(int64_t customerId) { _custId = customerId; }
                void setName(const std::string &name) { _name = name; }
                void setTotal(double total) { _total = total; }
                void setLinkToCustomer(const Relation::SPtrLinkToOne &customer) { _linkToCustomer = customer; }
            };
        }
    }
}


#endif //CLOUD_E_PLUS_APPTEST_ENTITY_PREORDER_H
