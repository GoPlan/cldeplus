//
// Created by LE, Duc Anh on 14/05/2015.
//

#ifndef CLOUD_E_CPLUS_FOUNDATION_COLUMN_H
#define CLOUD_E_CPLUS_FOUNDATION_COLUMN_H

#include "../Port/Definitions.h"
#include "Common/IPrintable.h"
#include "Data/TypeEnums.h"

namespace CLDEPlus {
    namespace Foundation {

        class Column : public Common::IPrintable {

            string _name;
            string _datasourceName;
            Data::ValueType _dataType;
            size_t _length;

        public:
            Column() = default;
            Column(string name, Data::ValueType dataType);
            Column(string name, Data::ValueType dataType, string datasourceName, size_t length);
            Column(const Column &) = default;
            Column(Column &&) = default;
            Column &operator=(const Column &) = default;
            Column &operator=(Column &&) = default;
            ~Column() = default;

            // IPrintable
            string ToString() const override;

            // Locals - Mutators
            void setDatasourceName(const string &datasourceName) { _datasourceName = datasourceName; }
            void setName(const string &name) { _name = name; }
            void setDataType(const Data::ValueType &dataType) { _dataType = dataType; }
            void setLength(size_t length) { _length = length; }

            // Locals - Accessors
            const string &getDatasourceName() const { return _datasourceName; }
            const string &getName() const { return _name; }
            const Foundation::Data::ValueType &getDataType() const { return _dataType; }
            size_t getLength() const { return _length; }
        };

        using SPtrColumn = shared_ptr<Column>;
        using SPtrColumnVector = vector<SPtrColumn>;
        using SPtrColumnMap = unordered_map<string, SPtrColumn>;

        SPtrColumn CreateColumn(const string &name, Data::ValueType dataType);
        SPtrColumn CreateColumn(const string &name, Data::ValueType dataType, const string &datasourceName,
                                size_t length = 0);
    }
}


#endif //CLOUD_E_CPLUS_FOUNDATION_COLUMN_H
