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
            using Column = Cloude::Architecture::Column;
            using Field = Cloude::Architecture::Field;

            class StockGroupLoader : public EntityLoader {
            public:
                StockGroupLoader(const StockGroupLoader &srcStockGroupLoader) = default;
                StockGroupLoader &operator=(const StockGroupLoader &srcStockGroupLoader) = default;
                virtual ~StockGroupLoader();

                explicit StockGroupLoader(const std::unordered_map<std::string, std::shared_ptr<Column>> &columnsMap);

                std::unique_ptr<Identity> NextPrimaryKey() override;
                void LoadEntity(std::shared_ptr<Identity> &identity) override;


                const std::string &getHost() const {
                    return _host;
                }

                void setHost(const std::string &host) {
                    _host = host;
                }

                const std::string &getUser() const {
                    return _user;
                }

                void setUser(const std::string &user) {
                    _user = user;
                }

                const std::string &getPass() const {
                    return _pass;
                }

                void setPass(const std::string &pass) {
                    _pass = pass;
                }

                const std::string &getDbase() const {
                    return _dbase;
                }

                void setDbase(const std::string &dbase) {
                    _dbase = dbase;
                }

                const std::string &getQuery() const {
                    return _query;
                }

                void setQuery(const std::string &query) {
                    _query = query;
                }

                unsigned int getPort() const {
                    return _port;
                }

                void setPort(unsigned int port) {
                    _port = port;
                }

            private:
                MYSQL *_ptrMySql = nullptr;
                MYSQL_STMT *_ptrMySqlStmt = nullptr;
                MYSQL_BIND *_ptrMySqlBind = nullptr;

                my_bool *_ptrIsNull = nullptr;
                my_bool *_ptrError = nullptr;
                unsigned long *_ptrLength = nullptr;

                const std::unordered_map<std::string, std::shared_ptr<Column>> &_columnsMap;

                std::string _host;
                std::string _user;
                std::string _pass;
                std::string _dbase;
                std::string _query;

                unsigned int _port = 3306;

                void assert_sql_error();
                void assert_sql_stmt_error();
                void setup_bind(std::shared_ptr<Entity> &entity);
                void setup_field(std::shared_ptr<Field> &field, MYSQL_BIND *ptrBind);
                void setup_query();
            };
        }
    }
}


#endif //CLOUD_E_CPLUS_STOCKGROUPLOADER_H
