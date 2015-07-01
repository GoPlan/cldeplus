//
// Created by LE, Duc Anh on 7/1/15.
//

#ifndef CLOUD_E_PLUS_APPTEST_APPLICATION_PRODUCTMAP_H
#define CLOUD_E_PLUS_APPTEST_APPLICATION_PRODUCTMAP_H

#include <Foundation/EntityMap.h>

namespace Cloude {
    namespace AppTest {
        namespace Application {

            class ProductMap : public Foundation::EntityMap {

            public:
                static std::string TableName;
                static Foundation::SPtrColumn Id;
                static Foundation::SPtrColumn Name;

            public:
                ProductMap();
                ProductMap(const ProductMap &) = default;
                ProductMap(ProductMap &&) = default;
                ProductMap &operator=(const ProductMap &) = default;
                ProductMap &operator=(ProductMap &&) = default;
                virtual ~ProductMap() = default;

            protected:
                virtual const std::string &TableNameCore() const override;
            };
        }
    }
}


#endif //CLOUD_E_PLUS_APPTEST_APPLICATION_PRODUCTMAP_H
