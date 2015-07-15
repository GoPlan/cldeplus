//
// Created by LE, Duc Anh on 7/3/15.
//

#ifndef CLOUD_E_PLUS_APPTEST_APPLICATION_PREORDERITEMSMAP_H
#define CLOUD_E_PLUS_APPTEST_APPLICATION_PREORDERITEMSMAP_H

#include <Foundation/EntityMap.h>

namespace Cloude {
    namespace AppTest {
        namespace Application {

            class PreOrderItemsMap : public Foundation::EntityMap {

            public:
                static std::string TableName;
                static Foundation::SPtrColumn Id;
                static Foundation::SPtrColumn OrderId;
                static Foundation::SPtrColumn ItemId;
                static Foundation::SPtrColumn Qty;
                static Foundation::SPtrColumn Price;
                static Foundation::SPtrColumn Amount;
                static Foundation::SPtrColumn Comment;

            public:
                PreOrderItemsMap();
                PreOrderItemsMap(const PreOrderItemsMap &) = default;
                PreOrderItemsMap(PreOrderItemsMap &&) = default;
                PreOrderItemsMap &operator=(const PreOrderItemsMap &) = default;
                PreOrderItemsMap &operator=(PreOrderItemsMap &&) = default;
                ~PreOrderItemsMap() = default;

            protected:
                virtual const std::string &TableNameCore() const override;

            };
        }
    }
}

#endif //CLOUD_E_PLUS_APPTEST_APPLICATION_PREORDERITEMSMAP_H
