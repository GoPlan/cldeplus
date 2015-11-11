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

#ifndef CLDEPLUS_FOUNDATION_CONTRACT_IDATARECORD_H
#define CLDEPLUS_FOUNDATION_CONTRACT_IDATARECORD_H

#include "../Cell.h"

namespace CLDEPlus {
    namespace Foundation {
        namespace Store {

            class AbstractEntity : public Common::IPrintable {

            public:
                AbstractEntity(AbstractEntity const &);
                AbstractEntity(AbstractEntity &&) = default;
                AbstractEntity &operator=(AbstractEntity const &);
                AbstractEntity &operator=(AbstractEntity &&) = default;
                virtual ~AbstractEntity() = default;

                virtual void setCell(SPtrCell const &cell);
                virtual void setCell(Cell *ptrCell);
                virtual void setMultiCells(SPtrCellVector const &cellVector);
                virtual void setMultiCells(vector<Cell *> const &cellVector);

                virtual const SPtrCell &getCell(string const &columnName) const;
                virtual const SPtrCell &operator[](string const &columnName) const;
                virtual bool TryGetCell(string const &columnName, SPtrCell &sptrOutCell) const;
                virtual bool hasCell(string const &cellName) const;
                virtual unsigned long Size() const;

                const SPtrCellMap &getCellsMap() const { return _cellMap; };

                SPtrCellVector getCells() const;
                SPtrCellVector getCells(SPtrColumnVector const &selectedColumns) const;
                SPtrColumnVector getColumns() const;

                // IPrintable
                virtual string ToString() const override;
                virtual string ToString(Foundation::Common::IFormatter const &formatter) const override;

            protected:
                AbstractEntity() = default;
                SPtrCellMap _cellMap;

            };

            using SPtrDataRecord = shared_ptr<AbstractEntity>;
        }
    }
}

#endif //CLDEPLUS_FOUNDATION_CONTRACT_IDATARECORD_H
