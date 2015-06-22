//
// Created by LE, Duc Anh on 14/05/2015.
//

#ifndef CLOUD_E_CPLUS_FOUNDATION_COLUMN_H
#define CLOUD_E_CPLUS_FOUNDATION_COLUMN_H

#include <string>
#include <vector>
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
            Column(const Column &) = default;
            Column(Column &&) = default;
            Column &operator=(const Column &) = default;
            Column &operator=(Column &&) = default;
            ~Column() = default;

            // IPrintable
            const std::string CopyToString() const override;
            const std::string &ToString() const override;
            const char *ToCString() const override;

            // Locals
            Column(std::string name,
                   std::string datasourceName,
                   Foundation::Type::cldeValueType dataType);

            Column(std::string name,
                   std::string datasourceName,
                   size_t length,
                   Foundation::Type::cldeValueType dataType);

            const std::string &getDatasourceName() const { return _datasourceName; }
            const std::string &getName() const { return _name; }
            const Foundation::Type::cldeValueType &getDataType() const { return _dataType; }
            size_t getLength() const { return _length; }
            void setLength(size_t length) { _length = length; }
        };

        using SPtrColumn = std::shared_ptr<Column>;
        using SPtrColumnVector = std::vector<SPtrColumn>;
    }
}


#endif //CLOUD_E_CPLUS_FOUNDATION_COLUMN_H
