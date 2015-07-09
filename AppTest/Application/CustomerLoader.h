//
// Created by LE, Duc Anh on 7/6/15.
//

#ifndef CLOUD_E_PLUS_APPTEST_APPLICATION_CUSTOMERLOADER_H
#define CLOUD_E_PLUS_APPTEST_APPLICATION_CUSTOMERLOADER_H

#include <Foundation/EntityLoader.h>

namespace Cloude {
    namespace AppTest {
        namespace Application {

            class CustomerLoader : public Foundation::EntityLoader {

            public:
                CustomerLoader() = default;
                CustomerLoader(const CustomerLoader &) = default;
                CustomerLoader(CustomerLoader &&) = default;
                CustomerLoader &operator=(const CustomerLoader &) = default;
                CustomerLoader &operator=(CustomerLoader &&) = default;
                virtual ~CustomerLoader() = default;


                virtual Foundation::SPtrIdentity NextPrimaryKey() const override;
            };
        }
    }
}


#endif //CLOUD_E_PLUS_APPTEST_APPLICATION_CUSTOMERLOADER_H
