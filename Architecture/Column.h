//
// Created by GoPlan on 14/05/2015.
//

#ifndef CLOUD_E_CPLUS_COLUMN_H
#define CLOUD_E_CPLUS_COLUMN_H

#include <string>
#include "Enumeration/DbType.h"

namespace Cloude {
    namespace Architecture {

        class Column {
        public:
            Column() = default;
            Column(const Column& srcColumn) = default;
            Column& operator=(const Column& srcColumn) = default;
            virtual ~Column() = default;

            Column(const std::string name,
                   const std::string datasourceName,
                   Cloude::Architecture::Enumeration::DbType dbtype);

            const std::string &getDatasourceName() const {
                return _datasourceName;
            }

            const std::string &getName() const {
                return _name;
            }

            const Cloude::Architecture::Enumeration::DbType &getDbType() const {
                return _dbType;
            }

        private:
            std::string _datasourceName;
            std::string _name;
            Cloude::Architecture::Enumeration::DbType _dbType;
        };
    }
}


#endif //CLOUD_E_CPLUS_COLUMN_H
