//
// Created by LE, Duc Anh on 7/10/15.
//

#ifndef CLOUD_E_PLUS_BOOTING_EXCEPTION_REGISTRYEXCEPTION_H
#define CLOUD_E_PLUS_BOOTING_EXCEPTION_REGISTRYEXCEPTION_H

namespace Cloude {
    namespace Booting {
        namespace Exception {

            class RegistryException {

            public:
                RegistryException() = default;
                RegistryException(const RegistryException &) = default;
                RegistryException(RegistryException &&) = default;
                RegistryException &operator=(const RegistryException &) = default;
                RegistryException &operator=(RegistryException &&) = default;
                virtual ~RegistryException() = default;
            };
        }
    }
}


#endif //CLOUD_E_PLUS_BOOTING_EXCEPTION_REGISTRYEXCEPTION_H
