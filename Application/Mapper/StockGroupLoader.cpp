//
// Created by GoPlan on 15/05/2015.
//

#include "StockGroupLoader.h"

using namespace std;
using namespace Cloude::Architecture;

namespace Cloude {
    namespace Application {
        namespace Mapper {

            StockGroupLoader::~StockGroupLoader() {

                if (ptrMySqlStmt != nullptr) {
                    mysql_stmt_close(ptrMySqlStmt);
                }

                if (ptrMySql != nullptr) {
                    mysql_close(ptrMySql);
                }

            }

            std::unique_ptr<Identity> StockGroupLoader::NextPrimaryKey() {
                unique_ptr<Identity> identity;
                return identity;
            }

            void StockGroupLoader::LoadEntity(std::shared_ptr<Identity> &identity) {

                auto spEntity = identity->getEntity();

                if (ptrMySql == nullptr) {
                    // TODO: Validate MySQL initialization errors
                    mysql_library_init;
                    mysql_init(ptrMySql);
                    mysql_real_connect(ptrMySql,
                                       host.c_str(), user.c_str(), pass.c_str(), dbase.c_str(), port,
                                       NULL, NULL);
                }

                if (ptrMySqlStmt == nullptr) {
                    ptrMySqlStmt = mysql_stmt_init(ptrMySql);
                }

                if (mysql_stmt_prepare(ptrMySqlStmt, query.c_str(), query.length())) {
                    // TODO: Validate MYSQL_STMT preparation errors
                }

                // Bind Params

                // Bind Result

                // Execute

                // Load Entity
            }
        }
    }
}
