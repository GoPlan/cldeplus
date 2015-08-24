//
// Created by LE, Duc Anh on 7/8/15.
//

#ifndef CLOUD_E_PLUS_APPTEST_ENTITY_CUSTOMER_H
#define CLOUD_E_PLUS_APPTEST_ENTITY_CUSTOMER_H

#include <string>
#include "../../Source/Relation/Relation.h"

namespace Cloude {
    namespace Test {
        namespace Entity {

            class Customer {

                int64_t _id;
                std::string _firstName;
                std::string _lastName;
                std::string _email;

                Relation::SPtrLinkToMany _linkToPreOrders;
                Relation::SPtrMultiCellsObj _objAddress;

            public:
                Customer() = default;
                Customer(const Customer &) = default;
                Customer(Customer &&) = default;
                Customer &operator=(const Customer &) = default;
                Customer &operator=(Customer &&) = default;
                ~Customer() = default;

                // Accessors
                int64_t getId() const { return _id; }
                const std::string &getFirstName() const { return _firstName; }
                const std::string &getLastName() const { return _lastName; }
                const std::string &getEmail() const { return _email; }
                const Relation::SPtrLinkToMany &LinkToPreOrders() const { return _linkToPreOrders; }
                const Relation::SPtrMultiCellsObj &objAddress() const { return _objAddress; }

                // Mutators
                void setId(int64_t Id) { _id = Id; }
                void setFirstName(const std::string &firstName) { _firstName = firstName; }
                void setLastName(const std::string &lastName) { _lastName = lastName; }
                void setEmail(const std::string &email) { _email = email; }
                void setLinkToPreOrders(const Relation::SPtrLinkToMany &sptrPreOrders) { _linkToPreOrders = sptrPreOrders; }
                void setObjAddress(const Relation::SPtrMultiCellsObj &objAddress) { _objAddress = objAddress; }
            };
        }
    }
}


#endif //CLOUD_E_PLUS_APPTEST_ENTITY_CUSTOMER_H
