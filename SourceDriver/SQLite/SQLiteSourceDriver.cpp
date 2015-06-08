//
// Created by LE, Duc Anh on 6/7/15.
//

#include "SQLiteSourceDriver.h"
#include "Amalgamation/sqlite3.h"


namespace Cloude {
    namespace SourceDriver {
        namespace SQLite {

            class ResultSet {

            };

            class Command {
            public:
                Command(const std::string &query) : query(query) {
                    //
                };

                ~Command() {
                    if (_ptrStmt != nullptr) {
                        sqlite3_finalize(_ptrStmt);
                    }
                };

                int PrepareStatment(sqlite3 *ptrDb) {

                    if (sqlite3_prepare(ptrDb, query.c_str(), query.length(), &_ptrStmt, 0)) {
                        // TODO: throw an appropriate exception
                    }

                    return 1;
                }

                std::shared_ptr<ResultSet> Execute() {
                    return std::shared_ptr<ResultSet>();
                }

            private:
                sqlite3_stmt *_ptrStmt = nullptr;
                std::string query;

            };

            class SQLiteSourceDriver::SQLiteImpl {
            public:
                SQLiteImpl(std::string &connectionString) : connectionString(connectionString) {
                    //
                };

                ~SQLiteImpl() {
                    if (_ptrSqlite3 != nullptr) {
                        sqlite3_close(_ptrSqlite3);
                    }
                };

                int Connect(const char *connString = 0) {

                    const char *tmpConnString = connString == 0 ? connectionString.c_str() : connString;

                    if (sqlite3_open(tmpConnString, &_ptrSqlite3)) {
                        // TODO: throw an approriate exception
                    }

                    return 1;
                }

                std::string &connectionString;
                sqlite3 *_ptrSqlite3 = nullptr;
            };

            SQLiteSourceDriver::SQLiteSourceDriver(EntityMap &entityMap)
                    : EntitySourceDriver(entityMap),
                      _sqliteImpl(new SQLiteImpl(_optionArgs.ConnectionString)) {
                //
            }

            SQLiteSourceDriver::~SQLiteSourceDriver() {
                Disconnect();
            }

            void SQLiteSourceDriver::Connect() {

                if (!_sqliteImpl) {
                    _sqliteImpl = std::make_shared<SQLiteImpl>(_optionArgs.ConnectionString);
                }

                _sqliteImpl->Connect();
            }

            void SQLiteSourceDriver::Disconnect() {
                _sqliteImpl.reset();
            }

            int SQLiteSourceDriver::LoadEntity(std::shared_ptr<Entity> &entity) const {
                return 0;
            }

            int SQLiteSourceDriver::CreateEntity(std::shared_ptr<Entity> &entity) const {
                return 0;
            }

            int SQLiteSourceDriver::SaveEntity(std::shared_ptr<Entity> &entity) const {
                return 0;
            }

            int SQLiteSourceDriver::DeleteEntity(std::shared_ptr<Entity> &entity) const {
                return 0;
            }
        }
    }
}

