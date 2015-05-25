//
// Created by GoPlan on 15/05/2015.
//

#ifndef CLOUD_E_CPLUS_STOCKGROUPLOADER_H
#define CLOUD_E_CPLUS_STOCKGROUPLOADER_H

#include <memory>
#include <string>

#include "mysql.h"

#include "../../Architecture/EntityLoader.h"
#include "../Model/StockGroup.h"

namespace Cloude {
    namespace Application {
        namespace Mapper {

            using EntityLoader = Cloude::Architecture::EntityLoader;
            using Entity = Cloude::Architecture::Entity;
            using Identity = Cloude::Architecture::Identity;

            class StockGroupLoader : public EntityLoader {
            public:
                StockGroupLoader() = default;
                StockGroupLoader(const StockGroupLoader &srcStockGroupLoader) = default;
                StockGroupLoader &operator=(const StockGroupLoader &srcStockGroupLoader) = default;
                virtual ~StockGroupLoader();

                std::unique_ptr<Identity> NextPrimaryKey() override;
                void LoadEntity(std::shared_ptr<Identity> &identity) override;

            private:
                MYSQL *ptrMySql = nullptr;
                MYSQL_STMT *ptrMySqlStmt = nullptr;

                std::string host;
                std::string user;
                std::string pass;
                std::string dbase;
                std::string query;

                unsigned int port = 3306;
            };
        }
    }
}


#endif //CLOUD_E_CPLUS_STOCKGROUPLOADER_H
