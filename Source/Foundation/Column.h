//
// Created by LE, Duc Anh on 14/05/2015.
//

#ifndef CLOUD_E_CPLUS_FOUNDATION_COLUMN_H
#define CLOUD_E_CPLUS_FOUNDATION_COLUMN_H

#include <string>
#include <vector>
#include <unordered_map>
#include "Common/IPrintable.h"
#include "Data/TypeEnums.h"

namespace CLDEPlus {
    namespace Foundation {

        class Column : public Common::IPrintable {

            std::string _name;
            std::string _datasourceName;
            Data::ValueType _dataType;
            size_t _length;

        public:
            Column() = default;
            Column(std::string name, Data::ValueType dataType);
            Column(std::string name, Data::ValueType dataType, std::string datasourceName, size_t length);
            Column(const Column &) = default;
            Column(Column &&) = default;
            Column &operator=(const Column &) = default;
            Column &operator=(Column &&) = default;
            ~Column() = default;

            // IPrintable
            std::string ToString() const override;

            // Locals - Mutators
            void setDatasourceName(const std::string &datasourceName) { _datasourceName = datasourceName; }
            void setName(const std::string &name) { _name = name; }
            void setDataType(const Data::ValueType &dataType) { _dataType = dataType; }
            void setLength(size_t length) { _length = length; }

            // Locals - Accessors
            const std::string &getDatasourceName() const { return _datasourceName; }
            const std::string &getName() const { return _name; }
            const Foundation::Data::ValueType &getDataType() const { return _dataType; }
            size_t getLength() const { return _length; }
        };

        using SPtrColumn = std::shared_ptr<Column>;
        using SPtrColumnVector = std::vector<SPtrColumn>;
        using SPtrColumnMap = std::unordered_map<std::string, SPtrColumn>;

        SPtrColumn CreateColumn(const std::string &name, Data::ValueType dataType);
        SPtrColumn CreateColumn(const std::string &name, Data::ValueType dataType, const std::string &datasourceName,
                                size_t length = 0);
    }
}


#endif //CLOUD_E_CPLUS_FOUNDATION_COLUMN_H
