//
// Created by GoPlan on 18/05/2015.
//

#ifndef CLOUD_E_CPLUS_MYSQLDRIVER_H
#define CLOUD_E_CPLUS_MYSQLDRIVER_H

#include <vector>
#include "../Architecture/EntitySourceDriver.h"
#include "mysql.h"

namespace Cloude {
    namespace Infrastructure {

        using Entity = Cloude::Architecture::Entity;
        using Column = Cloude::Architecture::Column;
        using Field = Cloude::Architecture::Field;
        using EntitySourceDriver = Cloude::Architecture::EntitySourceDriver;
        using EntityMap = Cloude::Architecture::EntityMap;
        using ColumnsList = std::vector<std::shared_ptr<Column>>;

        class MySqlDriver : public EntitySourceDriver {

        public:
            virtual ~MySqlDriver();


            explicit MySqlDriver(MYSQL *ptrMySql = nullptr) : _ptrMySql(ptrMySql) { };
            virtual int LoadEntity(std::shared_ptr<Entity> &entity, const EntityMap &entityMap) override;
            virtual int InsertEntity(std::shared_ptr<Entity> &entity, const EntityMap &entityMap) override;


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
            std::string _host;
            std::string _user;
            std::string _pass;
            std::string _dbase;
            std::string _query;

            unsigned int _port = 3306;

            MYSQL *_ptrMySql = nullptr;
            MYSQL_STMT *_ptrMySqlStmt = nullptr;

            MYSQL_BIND *_ptrMySqlParamsBind = nullptr;
            unsigned long *_ptrParamsLength = nullptr;

            MYSQL_BIND *_ptrMySqlResultBind = nullptr;
            my_bool *_ptrResultIsNull = nullptr;
            my_bool *_ptrResultError = nullptr;
            unsigned long *_ptrResultLength = nullptr;

            void assertSqlError();
            void assertSqlStmtError();
            void assignBindParamsBuffer(std::shared_ptr<Entity> &entity, const ColumnsList &columnsList);
            void assignBindresultBuffer(std::shared_ptr<Entity> &entity, const ColumnsList &columnsList);
            void setupBindBufferDataTypeAndLength(std::shared_ptr<Field> &field, MYSQL_BIND *ptrBind);
        };
    }
}


#endif //CLOUD_E_CPLUS_MYSQLDRIVER_H
