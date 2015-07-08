//
// Created by LE, Duc Anh on 14/05/2015.
//

#ifndef CLOUD_E_CPLUS_FOUNDATION_CELL_H
#define CLOUD_E_CPLUS_FOUNDATION_CELL_H

#include <string>
#include <memory>
#include <unordered_map>
#include "Data/Value.h"
#include "Column.h"


namespace Cloude {
    namespace Foundation {

        class Cell : public Common::IPrintable {

            SPtrColumn _column;
            Data::SPtrValue _value;

        public:
            explicit Cell(const SPtrColumn &column);
            explicit Cell(const SPtrColumn &column, const Data::SPtrValue &value);
            Cell(const Cell &) = default;
            Cell(Cell &&) = default;
            Cell &operator=(const Cell &) = default;
            Cell &operator=(Cell &&) = default;
            ~Cell() = default;

            // IPrintable
            std::string ToString() const override;

            // Locals
            bool isNull() const { return _value.get() == nullptr; };

            const SPtrColumn &getColumn() const { return _column; }
            const Data::SPtrValue &getValue() const { return _value; }

            void setValue(const Data::SPtrValue &value);
        };

        using SPtrCell = std::shared_ptr<Cell>;
        using SPtrCellMap = std::unordered_map<std::string, SPtrCell>;
        using SPtrCellVector = std::vector<SPtrCell>;
    }
}


#endif //CLOUD_E_CPLUS_FOUNDATION_CELL_H
