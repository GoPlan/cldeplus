//
// Created by LE, Duc Anh on 7/1/15.
//

#ifndef CLOUD_E_PLUS_APPTEST_APPLICATION_PRODUCTMAP_H
#define CLOUD_E_PLUS_APPTEST_APPLICATION_PRODUCTMAP_H

#include "../../Source/Foundation/EntityMap.h"

namespace Cloude {
    namespace Test {
        namespace Application {

            class ProductMap : public Foundation::EntityMap {

                static std::string TableName;
                static Foundation::SPtrColumn Id;
                static Foundation::SPtrColumn Name;
                static Foundation::SPtrColumn Code;
                static Foundation::SPtrColumn Price;

            public:
                ProductMap();
                ProductMap(const ProductMap &) = default;
                ProductMap(ProductMap &&) = default;
                ProductMap &operator=(const ProductMap &) = default;
                ProductMap &operator=(ProductMap &&) = default;
                ~ProductMap() = default;

            protected:
                virtual const std::string &TableNameCore() const override;
            };

            using SPtrProductMap = std::shared_ptr<ProductMap>;
        }
    }
}


#endif //CLOUD_E_PLUS_APPTEST_APPLICATION_PRODUCTMAP_H
