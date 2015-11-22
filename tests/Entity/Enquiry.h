//
// Created by LE, Duc Anh on 7/8/15.
//

#ifndef CLDEPLUS_APPTEST_ENTITY_ENQUIRY_H
#define CLDEPLUS_APPTEST_ENTITY_ENQUIRY_H

#include <memory>
#include <string>

namespace CLDEPlus {
    namespace Test {
        namespace Entity {

            class Enquiry {

                int64_t _id;
                std::string _email;
                std::string _subject;

            public:
                Enquiry() = default;
                Enquiry(const Enquiry &) = default;
                Enquiry(Enquiry &&) = default;
                Enquiry &operator=(const Enquiry &) = default;
                Enquiry &operator=(Enquiry &&) = default;
                ~Enquiry() = default;

                // Mutators
                void setId(int64_t id) { _id = id; }
                void setEmail(const std::string &email) { _email = email; }
                void setSubject(const std::string &subject) { _subject = subject; }

                // Accessors
                int64_t getId() const { return _id; }
                const std::string &getEmail() const { return _email; }
                const std::string &getSubject() const { return _subject; }
            };

            using SPtrEnquiry = std::shared_ptr<Enquiry>;
        }
    }
}


#endif //CLDEPLUS_APPTEST_ENTITY_ENQUIRY_H
