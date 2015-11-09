//
// Created by LE, Duc Anh on 14/05/2015.
//

#ifndef CLOUD_E_CPLUS_FOUNDATION_CELL_H
#define CLOUD_E_CPLUS_FOUNDATION_CELL_H

#include "../Port/Definitions.h"
#include "Data/Value.h"
#include "Column.h"


namespace CLDEPlus {
    namespace Foundation {

        class Cell : public Common::IPrintable {

            SPtrColumn _column;
            Data::SPtrValue _value;

        public:
            explicit Cell(SPtrColumn const &column);
            explicit Cell(SPtrColumn const &column, Data::SPtrValue const &value);
            Cell(Cell const &) = default;
            Cell(Cell &&) = default;
            Cell &operator=(Cell const &) = default;
            Cell &operator=(Cell &&) = default;
            ~Cell() = default;

            // IPrintable
            string ToString() const override;

            // Locals
            bool isNull() const { return _value.get() == nullptr; };
            SPtrColumn const &getColumn() const { return _column; }
            Data::SPtrValue const &getValue() const { return _value; }

            void setValue(Data::SPtrValue const &value);
            void setValue(int16 value);
            void setValue(int32 value);
            void setValue(int64 value);
            void setValue(uint16 value);
            void setValue(uint32 value);
            void setValue(uint64 value);
            void setValue(float value);
            void setValue(double value);
            void setValue(bool value);

            // Factory methods
            static unique_ptr<Cell> CreateUnique(SPtrColumn column) { return cldeplus_make_unique<Cell>(column); }
            static unique_ptr<Cell> CreateUnique(SPtrColumn column, Data::SPtrValue &value) { return cldeplus_make_unique<Cell>(column, value); }
            static shared_ptr<Cell> CreateShared(SPtrColumn column) { return cldeplus_make_shared<Cell>(column); }
            static shared_ptr<Cell> CreateShared(SPtrColumn column, Data::SPtrValue &value) { return cldeplus_make_shared<Cell>(column, value); }
        };

        using SPtrCell = shared_ptr<Cell>;
        using SPtrCellMap = unordered_map<string, SPtrCell>;
        using SPtrCellVector = vector<SPtrCell>;
    }
}


#endif //CLOUD_E_CPLUS_FOUNDATION_CELL_H
