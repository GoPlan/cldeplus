//
// Created by LE, Duc Anh on 7/9/15.
//

#ifndef CLOUD_E_PLUS_RELATION_EXCEPTION_NAMEDENTITYSTOREEXCEPTION_H
#define CLOUD_E_PLUS_RELATION_EXCEPTION_NAMEDENTITYSTOREEXCEPTION_H

#include "../../Foundation/Exception/cldeException.h"

namespace Cloude {
    namespace Relation {
        namespace Exception {

            class NamedEntityStoreException : Foundation::Exception::cldeException {

                static std::string _name;

            public:
                NamedEntityStoreException(const std::string &message) : Foundation::Exception::cldeException{message} { };
                NamedEntityStoreException(const NamedEntityStoreException &) = default;
                NamedEntityStoreException(NamedEntityStoreException &&) = default;
                NamedEntityStoreException &operator=(const NamedEntityStoreException &) = default;
                NamedEntityStoreException &operator=(NamedEntityStoreException &&) = default;
                virtual ~NamedEntityStoreException() = default;


            private:
                virtual const std::string &Name() const noexcept override;
            };
        }
    }
}


#endif //CLOUD_E_PLUS_RELATION_EXCEPTION_NAMEDENTITYSTOREEXCEPTION_H
