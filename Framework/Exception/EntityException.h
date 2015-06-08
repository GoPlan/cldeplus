//
// Created by LE, Duc Anh on 5/27/15.
//

#ifndef CLOUD_E_CPLUS_ENTITYEXCEPTION_H
#define CLOUD_E_CPLUS_ENTITYEXCEPTION_H


#include <exception>
#include <string>

namespace Cloude {
    namespace Framework {
        namespace Exception {
            class EntityException : public std::exception {
            public:
                virtual ~EntityException() = default;
                EntityException(const EntityException &srcEntityException) = default;
                EntityException &operator=(const EntityException &srcEntityException) = default;

                explicit EntityException(const std::string &message);
                virtual const char *what() const noexcept override;

            private:
                std::string _message;
            };
        }
    }
}


#endif //CLOUD_E_CPLUS_ENTITYEXCEPTION_H
