//
// Created by LE, Duc Anh on 5/27/15.
//

#include <memory>
#include <cstdlib>
#include <libpq-fe.h>
#include "PostgreSourceDriver.h"


using namespace std;

namespace Cloude {
    namespace Infrastructure {

        class Command {

        public:
            Command(const PGconn &conn, const string &query) : PGConn(conn),
                                                               Query(query) {
                //
            };

            virtual ~Command() {

                if (PtrParamTypes != nullptr)
                    free(PtrParamTypes);

                if (PtrParamLengths != nullptr)
                    free(PtrParamLengths);

                if (PtrParamFormats != nullptr)
                    free(PtrParamFormats);

                if (PtrParamValues != nullptr) {

                    for (int i = 0; i < nParam; ++i) {
                        free(PtrParamValues[i]);
                    }

                    free(PtrParamValues);
                }
            };

            int nParam = 0;
            int ResultFormat = 0;

            Oid *PtrParamTypes = nullptr;
            int *PtrParamLengths = nullptr;
            int *PtrParamFormats = nullptr;

            char **PtrParamValues = nullptr;

            const PGconn &PGConn;
            const string &Query;
        };


        class PostgreSourceDriver::PqApiImpl {

        public:
            PGconn *PtrPgConn;

        public:
            shared_ptr<Command> createCommand(const string &query) {
                shared_ptr<Command> command = make_shared<Command>(*PtrPgConn, query);
                return command;
            }

            void bindParamsBuffer(shared_ptr<Entity> &entity,
                                  const ColumnsList &columnsList,
                                  shared_ptr<Command> &command) {

                auto nParam = columnsList.size();

                command->nParam = (int) columnsList.size();
                command->PtrParamTypes = (Oid *) calloc(nParam, sizeof(Oid));
                command->PtrParamLengths = (int *) calloc(nParam, sizeof(int));
                command->PtrParamFormats = (int *) calloc(nParam, sizeof(int));
                command->PtrParamValues = (char **) calloc(nParam, sizeof(char *));

                for_each(columnsList.cbegin(), columnsList.cend(),
                         [&entity, &command](const shared_ptr<Column> &column) {


                         });
            }
        };

        PostgreSourceDriver::PostgreSourceDriver(EntityMap &entityMap) : EntitySourceDriver(entityMap) {
            init();
        }

        PostgreSourceDriver::~PostgreSourceDriver() {

        }

        int PostgreSourceDriver::LoadEntity(std::shared_ptr<Entity> &entity, const EntityMap &entityMap) const {

            // TODO: Establish columns for Load operation
            ColumnsList columnList;

            shared_ptr<Command> command = _pqApiImpl->createCommand(_getStatement);
            _pqApiImpl->bindParamsBuffer(entity, columnList, command);

            const char *const *ptrParamValues = const_cast<const char *const *>(command->PtrParamValues);

            PQexecParams(_pqApiImpl->PtrPgConn,
                         command->Query.c_str(),
                         command->nParam,
                         command->PtrParamTypes,
                         ptrParamValues,
                         command->PtrParamLengths,
                         command->PtrParamFormats,
                         command->ResultFormat);

            return 1;
        }

        int PostgreSourceDriver::CreateEntity(std::shared_ptr<Entity> &entity, const EntityMap &entityMap) const {

            // TODO: Establish columns for Create operation
            ColumnsList columnList;

            shared_ptr<Command> command = _pqApiImpl->createCommand(_insertStatement);
            _pqApiImpl->bindParamsBuffer(entity, columnList, command);

            const char *const *ptrParamValues = const_cast<const char *const *>(command->PtrParamValues);

            PQexecParams(_pqApiImpl->PtrPgConn,
                         command->Query.c_str(),
                         command->nParam,
                         command->PtrParamTypes,
                         ptrParamValues,
                         command->PtrParamLengths,
                         command->PtrParamFormats, 0);

            return 1;
        }

        int PostgreSourceDriver::SaveEntity(std::shared_ptr<Entity> &entity, const EntityMap &entityMap) const {

            // TODO: Establish columns for Save operation
            ColumnsList columnList;

            shared_ptr<Command> command = _pqApiImpl->createCommand(_updateStatement);
            _pqApiImpl->bindParamsBuffer(entity, columnList, command);

            const char *const *ptrParamValues = const_cast<const char *const *>(command->PtrParamValues);

            PQexecParams(_pqApiImpl->PtrPgConn,
                         command->Query.c_str(),
                         command->nParam,
                         command->PtrParamTypes,
                         ptrParamValues,
                         command->PtrParamLengths,
                         command->PtrParamFormats, 0);

            return 1;
        }

        int PostgreSourceDriver::DeleteEntity(std::shared_ptr<Entity> &entity, const EntityMap &entityMap) const {

            // TODO: Establish columns for Delete operation
            ColumnsList columnList;

            shared_ptr<Command> command = _pqApiImpl->createCommand(_deleteStatement);
            _pqApiImpl->bindParamsBuffer(entity, columnList, command);

            const char *const *ptrParamValues = const_cast<const char *const *>(command->PtrParamValues);

            PQexecParams(_pqApiImpl->PtrPgConn,
                         command->Query.c_str(),
                         command->nParam,
                         command->PtrParamTypes,
                         ptrParamValues,
                         command->PtrParamLengths,
                         command->PtrParamFormats, 0);

            return 1;
        }

        void PostgreSourceDriver::Connect() {

            if (_pqApiImpl->PtrPgConn == nullptr) {
                _pqApiImpl->PtrPgConn = PQsetdbLogin(OptionArgs.Host.c_str(),
                                                     std::to_string(OptionArgs.Port).c_str(),
                                                     NULL,
                                                     NULL,
                                                     OptionArgs.Base.c_str(),
                                                     OptionArgs.User.c_str(),
                                                     OptionArgs.Pass.c_str());
                _isConnected = true;
            }
        }

        void PostgreSourceDriver::Disconnect() {

            if (_pqApiImpl->PtrPgConn != nullptr) {
                PQfinish(_pqApiImpl->PtrPgConn);
                _isConnected = false;
            }
        }

        void PostgreSourceDriver::init() {

        }
    }
}

