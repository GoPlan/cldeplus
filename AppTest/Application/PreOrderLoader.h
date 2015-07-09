//
// Created by LE, Duc Anh on 7/6/15.
//

#ifndef CLOUD_E_PLUS_APPTEST_APPLICATION_ORDERLOADER_H
#define CLOUD_E_PLUS_APPTEST_APPLICATION_ORDERLOADER_H

#include <Foundation/EntityLoader.h>

namespace Cloude {
    namespace AppTest {
        namespace Application {

            class PreOrderLoader : public Foundation::EntityLoader {

            public:
                PreOrderLoader() = default;
                PreOrderLoader(const PreOrderLoader &) = default;
                PreOrderLoader(PreOrderLoader &&) = default;
                PreOrderLoader &operator=(const PreOrderLoader &) = default;
                PreOrderLoader &operator=(PreOrderLoader &&) = default;
                ~PreOrderLoader() = default;

                virtual Foundation::SPtrIdentity NextPrimaryKey() const override;
            };
        }
    }
}


#endif //CLOUD_E_PLUS_APPTEST_APPLICATION_ORDERLOADER_H
