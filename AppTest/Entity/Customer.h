//
// Created by LE, Duc Anh on 7/8/15.
//

#ifndef CLOUD_E_PLUS_APPTEST_ENTITY_CUSTOMER_H
#define CLOUD_E_PLUS_APPTEST_ENTITY_CUSTOMER_H

#include <string>
#include <Relation/Relation.h>

namespace Cloude {
    namespace AppTest {
        namespace Entity {

            class Customer {

                int64_t id;
                std::string firstName;
                std::string lastName;
                std::string email;

                Relation::LinkToMany _preOrders;

            public:
                Customer() = default;
                Customer(const Customer &) = default;
                Customer(Customer &&) = default;
                Customer &operator=(const Customer &) = default;
                Customer &operator=(Customer &&) = default;
                virtual ~Customer() = default;

                // Accessors
                int64_t getId() const { return id; }
                const std::string &getFirstName() const { return firstName; }
                const std::string &getLastName() const { return lastName; }
                const std::string &getEmail() const { return email; }

                // Mutators
                void setId(int64_t Id) { Customer::id = Id; }
                void setFirstName(const std::string &firstName) { Customer::firstName = firstName; }
                void setLastName(const std::string &lastName) { Customer::lastName = lastName; }
                void setEmail(const std::string &email) { Customer::email = email; }
            };
        }
    }
}


#endif //CLOUD_E_PLUS_APPTEST_ENTITY_CUSTOMER_H
