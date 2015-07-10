//
// Created by LE, Duc Anh on 7/10/15.
//

#ifndef CLOUD_E_PLUS_BOOTING_REGISTRY_H
#define CLOUD_E_PLUS_BOOTING_REGISTRY_H

namespace Cloude {
    namespace Booting {

        class Registry {
        public:
            Registry() = default;
            Registry(const Registry &) = default;
            Registry(Registry &&) = default;
            Registry &operator=(const Registry &) = default;
            Registry &operator=(Registry &&) = default;
            virtual ~Registry() = default;
        };
    }
}

#endif //CLOUD_E_PLUS_BOOTING_REGISTRY_H
