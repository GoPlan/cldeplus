//
// Created by LE, Duc Anh on 7/1/15.
//

#ifndef CLDEPLUS_APPTEST_APPLICATION_PRODUCTMAP_H
#define CLDEPLUS_APPTEST_APPLICATION_PRODUCTMAP_H

#include "../../Source/Foundation/EntityMap.h"

namespace CLDEPlus {
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
            };

            using SPtrProductMap = std::shared_ptr<ProductMap>;
        }
    }
}


#endif //CLDEPLUS_APPTEST_APPLICATION_PRODUCTMAP_H
