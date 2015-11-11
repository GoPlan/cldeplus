/*

Copyright 2015 LE, Duc-Anh

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.

*/

#ifndef CLOUD_E_CPLUS_FOUNDATION_CELL_H
#define CLOUD_E_CPLUS_FOUNDATION_CELL_H

#include "../Port/Definitions.h"
#include "Column.h"
#include "Data/Value.h"
#include "Data/Primitive.h"

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
            void setValue(Data::IPrimitive const &value);

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
