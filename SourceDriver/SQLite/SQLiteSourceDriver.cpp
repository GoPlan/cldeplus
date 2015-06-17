//
// Created by LE, Duc Anh on 6/7/15.
//

#include <cstdlib>
#include <Foundation/Type/cldeValueFactory.h>
#include <Foundation/Exception/cldeNonSupportedDataTypeException.h>
#include <Foundation/Query/CriteriaComposite.h>
#include <Foundation/Query/Comparative.h>
#include <Foundation/Query/Helper/SqlHelper.h>
#include <Foundation/Query/Helper/PredicateHelper.h>
#include <Foundation/Store/EntityStoreHelper.h>
#include "Amalgamation/sqlite3.h"
#include "SQLiteSourceDriver.h"
#include "SQLiteSourceHelper.h"

using namespace Cloude::SourceDriver::SQLite;

namespace Cloude {
    namespace SourceDriver {
        namespace SQLite {

            class Command {

            public:
                Command(const std::string &query) : query(query) { };
                Command(const Command &) = default;
                Command(Command &&) = default;
                Command &operator=(const Command &) = default;
                Command &operator=(Command &&) = default;
                ~Command() { if (_ptrStmt != nullptr) { sqlite3_finalize(_ptrStmt); }};

                int prepareStatment(sqlite3 *ptrDb) {

                    if (ptrDb == NULL) {
                        fprintf(stderr, "Database is not open\n");
                    }

                    int resultCode = sqlite3_prepare_v2(ptrDb, query.c_str(), -1, &_ptrStmt, NULL);

                    if (resultCode != SQLITE_OK) {
                        throw SQLiteSourceException{resultCode};
                    }

                    return 1;
                }

                sqlite3_stmt *_ptrStmt = nullptr;

                const std::string &query;
            };

            using cldeSqlHelper = Foundation::Query::Helper::SqlHelper;
            using cldeValueFactory = Foundation::Type::cldeValueFactory;
            using cldeValueType = Foundation::Type::cldeValueType;
            using SPtrColumnVector = std::vector<Foundation::SPtrColumn>;
            using UPtrCommand = std::unique_ptr<Command>;

            class SQLiteSourceDriver::SQLiteApiImpl {

            public:
                SQLiteApiImpl(std::string &connectionString) : connectionString(connectionString) {
                    //
                };

                ~SQLiteApiImpl() {
                    if (_ptrSqlite3 != nullptr) {
                        sqlite3_close(_ptrSqlite3);
                    }
                };

                int Connect(const char *connString = 0) {

                    const char *tmpConnString = connString == 0 ? connectionString.c_str() : connString;

                    int resultCode = sqlite3_open_v2(tmpConnString, &_ptrSqlite3, SQLITE_OPEN_READWRITE, NULL);

                    if (resultCode != SQLITE_OK) {
                        throw SQLiteSourceException{resultCode};
                    }

                    return 1;
                }

                UPtrCommand createCommand(const std::string &query) {
                    UPtrCommand command(new Command(query));
                    command->prepareStatment(_ptrSqlite3);
                    return command;
                }

                int initializeParamBindBuffers(const SPtrColumnVector &columnsList,
                                               const UPtrCommand &sptrCommand,
                                               Foundation::SPtrEntity &entity) {

                    int index = 1;

                    std::for_each(columnsList.cbegin(),
                                  columnsList.cend(),
                                  [&sptrCommand, &entity, &index](const Foundation::SPtrColumn &column) {

                                      auto &field = entity->getField(column->getName());
                                      auto &value = field->getValue();

                                      if (!value) {
                                          sqlite3_bind_null(sptrCommand->_ptrStmt, index++);
                                          return;
                                      }

                                      auto const ptrValueBuffer = field->getValue()->RawPointerToValueBuffer();

                                      switch (column->getDataType()) {
                                          case cldeValueType::Int64: {
                                              auto tmp = reinterpret_cast<const sqlite3_int64 *>(ptrValueBuffer);
                                              sqlite3_bind_int64(sptrCommand->_ptrStmt,
                                                                 index++,
                                                                 *tmp);
                                              break;
                                          };

                                          case cldeValueType::Varchar: {
                                              auto tmp = static_cast<const char *>(ptrValueBuffer);
                                              sqlite3_bind_text(sptrCommand->_ptrStmt,
                                                                index++,
                                                                tmp,
                                                                -1,
                                                                SQLITE_STATIC);
                                              break;
                                          };

                                          default:
                                              break;
                                      }
                                  });
                    return 1;
                }

                int initializeParamBindBuffers(const Foundation::Query::SPtrCriteriaVector &params,
                                               const UPtrCommand &uptrCommand) {

                    int index = 1;

                    std::for_each(params.cbegin(), params.cend(),
                                  [&uptrCommand, &index](const Foundation::Query::SPtrCriteria &sptrCriteria) {

                                      auto &column = sptrCriteria->getColumn();
                                      auto &value = sptrCriteria->getValue();

                                      if (!value) {
                                          sqlite3_bind_null(uptrCommand->_ptrStmt, index++);
                                          return;
                                      }

                                      const auto ptrValueBuffer = sptrCriteria->getValue()->RawPointerToValueBuffer();

                                      switch (column->getDataType()) {
                                          case cldeValueType::Int64: {
                                              auto tmp = reinterpret_cast<const sqlite3_int64 *>(ptrValueBuffer);
                                              sqlite3_bind_int64(uptrCommand->_ptrStmt,
                                                                 index++,
                                                                 *tmp);
                                              break;
                                          };

                                          case cldeValueType::Varchar: {
                                              auto tmp = static_cast<const char *>( ptrValueBuffer);
                                              sqlite3_bind_text(uptrCommand->_ptrStmt,
                                                                index++,
                                                                tmp,
                                                                -1,
                                                                SQLITE_STATIC);
                                              break;
                                          };

                                          default:
                                              break;
                                      }

                                  });

                    return 1;
                }

                int bindResultToFields(const Foundation::SPtrEntity &entity,
                                       const Foundation::SPtrColumnVector &columnsVector,
                                       const UPtrCommand &uptrCommand) const {

                    int index = 0;

                    for_each(columnsVector.cbegin(), columnsVector.cend(),
                             [&entity, &uptrCommand, &index](const Cloude::Foundation::SPtrColumn &column) {

                                 if (sqlite3_column_type(uptrCommand->_ptrStmt, index) == SQLITE_NULL) {
                                     ++index;
                                     return;
                                 }

                                 auto &sptrField = entity->getField(column->getName());

                                 switch (column->getDataType()) {
                                     case Cloude::Foundation::Type::cldeValueType::Int64: {
                                         auto value = sqlite3_column_int64(uptrCommand->_ptrStmt, index++);
                                         sptrField->setValue(cldeValueFactory::CreateInt64(value));
                                         break;
                                     };

                                     case Cloude::Foundation::Type::cldeValueType::Varchar: {
                                         auto value = sqlite3_column_text(uptrCommand->_ptrStmt, index++);
                                         auto cstr = reinterpret_cast<const char *>(value);
                                         sptrField->setValue(cldeValueFactory::CreateVarchar(cstr));
                                         break;
                                     };

                                     default:
                                         ++index;
                                         std::string msg{"This type is not yet supported"};
                                         throw Foundation::Exception::cldeNonSupportedDataTypeException{msg};
                                 }
                             });

                    return 1;
                }

                std::string &connectionString;
                sqlite3 *_ptrSqlite3 = nullptr;
            };
        }
    }
}

Cloude::SourceDriver::SQLite::SQLiteSourceDriver::SQLiteSourceDriver(const Foundation::EntityMap &entityMap)
        : EntitySourceDriver(entityMap),
          _sqliteApiImpl(new SQLiteApiImpl(_optionArgs.ConnectionString)) {
    Init();
}

Cloude::SourceDriver::SQLite::SQLiteSourceDriver::~SQLiteSourceDriver() {
    Disconnect();
}

void Cloude::SourceDriver::SQLite::SQLiteSourceDriver::Init() {

    auto fpValue = [](const Foundation::SPtrColumn &column, const int &index) -> std::string {
        return std::string("?");
    };

    auto fpCondition = [](const Foundation::SPtrColumn &column, const int &index) -> std::string {
        return std::string(column->getDatasourceName() + " = " + "?");
    };

    _getStatement = cldeSqlHelper::CreateGetPreparedQuery(getEntityMap(), fpCondition);
    _insertStatement = cldeSqlHelper::CreateInsertPreparedQuery(getEntityMap(), fpValue);
    _updateStatement = cldeSqlHelper::CreateUpdatePreparedQuery(getEntityMap(), fpCondition);
    _deleteStatement = cldeSqlHelper::CreateDeletePreparedQuery(getEntityMap(), fpCondition);
}

void Cloude::SourceDriver::SQLite::SQLiteSourceDriver::Connect() {

    if (!_sqliteApiImpl) {
        _sqliteApiImpl = std::make_shared<SQLiteApiImpl>(_optionArgs.ConnectionString);
    }

    _sqliteApiImpl->Connect();
}

void Cloude::SourceDriver::SQLite::SQLiteSourceDriver::Disconnect() {
    _sqliteApiImpl.reset();
}

int Cloude::SourceDriver::SQLite::SQLiteSourceDriver::Load(Foundation::SPtrEntity &entity) const {

    auto const &columnsForGet = getEntityMap().getColumnsForGet();
    auto const &columnsForKey = getEntityMap().getColumnsForKey();
    auto uptrCommand = _sqliteApiImpl->createCommand(_getStatement);

    _sqliteApiImpl->initializeParamBindBuffers(columnsForKey, uptrCommand, entity);

    int resultCode = sqlite3_step(uptrCommand->_ptrStmt);

    switch (resultCode) {
        case SQLITE_DONE:
            return 0;
        case SQLITE_ROW:
            _sqliteApiImpl->bindResultToFields(entity, columnsForGet, uptrCommand);
            return 1;
        default:
            throw SQLiteSourceException(resultCode);
    }
}

int Cloude::SourceDriver::SQLite::SQLiteSourceDriver::Insert(Foundation::SPtrEntity &entity) const {

    auto &columnsForKey = getEntityMap().getColumnsForKey();
    auto uptrCommand = _sqliteApiImpl->createCommand(_insertStatement);

    _sqliteApiImpl->initializeParamBindBuffers(columnsForKey, uptrCommand, entity);

    int resultCode = sqlite3_step(uptrCommand->_ptrStmt);

    if (resultCode != SQLITE_DONE) {
        throw SQLiteSourceException(resultCode);
    }

    return 1;
}

int Cloude::SourceDriver::SQLite::SQLiteSourceDriver::Save(Foundation::SPtrEntity &entity) const {

    auto &columnsForUpdate = getEntityMap().getColumnsForUpdate();
    auto &columnsForKey = getEntityMap().getColumnsForKey();

    SPtrColumnVector columnsList;
    columnsList.insert(columnsList.end(), columnsForUpdate.begin(), columnsForUpdate.end());
    columnsList.insert(columnsList.end(), columnsForKey.begin(), columnsForKey.end());

    auto uptrCommand = _sqliteApiImpl->createCommand(_updateStatement);

    _sqliteApiImpl->initializeParamBindBuffers(columnsList, uptrCommand, entity);

    int resultCode = sqlite3_step(uptrCommand->_ptrStmt);

    if (resultCode != SQLITE_DONE) {
        throw SQLiteSourceException(resultCode);
    }

    return 1;
}

int Cloude::SourceDriver::SQLite::SQLiteSourceDriver::Delete(Foundation::SPtrEntity &entity) const {

    auto const &columnsForKey = getEntityMap().getColumnsForKey();
    auto uptrCommand = _sqliteApiImpl->createCommand(_deleteStatement);

    _sqliteApiImpl->initializeParamBindBuffers(columnsForKey, uptrCommand, entity);

    int resultCode = sqlite3_step(uptrCommand->_ptrStmt);

    if (resultCode != SQLITE_DONE) {
        throw SQLiteSourceException(resultCode);
    }

    return 1;
}

Cloude::Foundation::SPtrProxyVector Cloude::SourceDriver::SQLite::SQLiteSourceDriver::Select(
        const Foundation::Query::SPtrCriteria &sptrCriteria,
        Foundation::EntityStore &entityStore) const {

    auto fpCondition = [](const Foundation::SPtrColumn &column, const int &index) -> std::string {
        return std::string{"?"};
    };

    auto &columnsForKey = getEntityMap().getColumnsForKey();
    auto &columnsForSelect = getEntityMap().getColumnsForSelect();

    auto size = columnsForKey.size() + columnsForSelect.size();

    SPtrColumnVector columnsVector;
    columnsVector.reserve(size);
    columnsVector.insert(columnsVector.end(), columnsForKey.begin(), columnsForKey.end());
    columnsVector.insert(columnsVector.cend(), columnsForSelect.begin(), columnsForSelect.end());

    auto tuplQuery = cldeSqlHelper::CreateSelectPreparedQuery(getEntityMap(), sptrCriteria, fpCondition);
    auto uptrCommand = _sqliteApiImpl->createCommand(tuplQuery.first);

    _sqliteApiImpl->initializeParamBindBuffers(tuplQuery.second, uptrCommand);

    Foundation::SPtrProxyVector proxies;

    int resultCode;

    while ((resultCode = sqlite3_step(uptrCommand->_ptrStmt)) == SQLITE_ROW) {

        Foundation::SPtrIdentity sptrIdentity{new Foundation::Identity{}};

        std::for_each(columnsForKey.begin(), columnsForKey.cend(),
                      [&sptrIdentity](const Foundation::SPtrColumn &sptrColumn) {
                          sptrIdentity->setField(new Foundation::Field{sptrColumn});
                      });

        Foundation::SPtrProxy sptrProxy{new Foundation::EntityProxy{sptrIdentity, entityStore}};
        Foundation::Store::EntityStoreHelper::GenerateFieldsFromColumns(columnsForSelect, sptrProxy);

        _sqliteApiImpl->bindResultToFields(sptrProxy, columnsVector, uptrCommand);

        proxies.push_back(sptrProxy);
    }

    if (resultCode != SQLITE_DONE) {
        throw SQLiteSourceException{resultCode};
    }

    return proxies;
}

