//
// Created by LE, Duc Anh on 14/05/2015.
//

#ifndef CLOUD_E_CPLUS_FOUNDATION_COLUMN_H
#define CLOUD_E_CPLUS_FOUNDATION_COLUMN_H

#include <string>
#include <vector>
#include <Foundation/Common/IPrintable.h>
#include "Type/cldeValueType.h"

namespace Cloude {
    namespace Foundation {

        class Column : public Common::IPrintable {

            std::string _name;
            std::string _datasourceName;
            Foundation::Type::cldeValueType _dataType;
            size_t _length;

        public:
            Column() = default;
            Column(std::string name, std::string datasourceName, Type::cldeValueType dataType);
            Column(std::string name, std::string datasourceName, size_t length, Type::cldeValueType dataType);
            Column(const Column &) = default;
            Column(Column &&) = default;
            Column &operator=(const Column &) = default;
            Column &operator=(Column &&) = default;
            ~Column() = default;

            // IPrintable
            const std::string CopyToString() const override;
            const std::string &ToString() const override;
            const char *ToCString() const override;

            // Locals - Mutators
            void setDatasourceName(const std::string &datasourceName) { _datasourceName = datasourceName; }
            void setName(const std::string &name) { _name = name; }
            void setDataType(const Type::cldeValueType &dataType) { _dataType = dataType; }
            void setLength(size_t length) { _length = length; }

            // Locals - Accessors
            const std::string &getDatasourceName() const { return _datasourceName; }
            const std::string &getName() const { return _name; }
            const Foundation::Type::cldeValueType &getDataType() const { return _dataType; }
            size_t getLength() const { return _length; }
        };

        using SPtrColumn = std::shared_ptr<Column>;
        using SPtrColumnVector = std::vector<SPtrColumn>;
    }
}


#endif //CLOUD_E_CPLUS_FOUNDATION_COLUMN_H
