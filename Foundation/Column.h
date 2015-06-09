//
// Created by GoPlan on 14/05/2015.
//

#ifndef CLOUD_E_CPLUS_COLUMN_H
#define CLOUD_E_CPLUS_COLUMN_H

#include <string>
#include <Foundation/Enumeration/DbType.h>

namespace Cloude {
    namespace Foundation {

        class Column {
        public:
            Column() = default;
            Column(const Column &srcColumn) = default;
            Column &operator=(const Column &srcColumn) = default;
            virtual ~Column() = default;

            Column(std::string name,
                   std::string datasourceName,
                   Foundation::Enumeration::DbType dbtype);

            Column(std::string name,
                   std::string datasourceName,
                   size_t length,
                   Foundation::Enumeration::DbType dbtype);

            size_t *PointerToLengthVariable() {
                return &_length;
            }

            const std::string &getDatasourceName() const {
                return _datasourceName;
            }

            const std::string &getName() const {
                return _name;
            }

            const Foundation::Enumeration::DbType &getDbType() const {
                return _dbType;
            }

            size_t getLength() const {
                return _length;
            }

            void setLength(size_t length) {
                _length = length;
            }

        private:
            std::string _name;
            std::string _datasourceName;
            Foundation::Enumeration::DbType _dbType;
            size_t _length;
        };
    }
}


#endif //CLOUD_E_CPLUS_COLUMN_H
