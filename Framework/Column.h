//
// Created by GoPlan on 14/05/2015.
//

#ifndef CLOUD_E_CPLUS_COLUMN_H
#define CLOUD_E_CPLUS_COLUMN_H

#include "string"

#include "Enumeration/DbType.h"

namespace Cloude {
    namespace Framework {

        class Column {
        public:
            Column() = default;
            Column(const Column &srcColumn) = default;
            Column &operator=(const Column &srcColumn) = default;
            virtual ~Column() = default;

            Column(std::string name,
                   std::string datasourceName,
                   Cloude::Framework::Enumeration::DbType dbtype);

            Column(std::string name,
                   std::string datasourceName,
                   size_t length,
                   Cloude::Framework::Enumeration::DbType dbtype);

            void *PointerToLengthVariable();

            const std::string &getDatasourceName() const {
                return _datasourceName;
            }

            const std::string &getName() const {
                return _name;
            }

            const Cloude::Framework::Enumeration::DbType &getDbType() const {
                return _dbType;
            }

            size_t getLength() const {
                return _length;
            }

            void setLength(size_t length) {
                _length = length;
            }

        private:
            std::string _datasourceName;
            std::string _name;
            Cloude::Framework::Enumeration::DbType _dbType;
            size_t _length;
        };
    }
}


#endif //CLOUD_E_CPLUS_COLUMN_H
