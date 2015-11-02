//
// Created by LE, Duc Anh on 6/16/15.
//

#ifndef CLDEPLUS_FOUNDATION_CONTRACT_IDATARECORD_H
#define CLDEPLUS_FOUNDATION_CONTRACT_IDATARECORD_H

#include "../Cell.h"

namespace CLDEPlus {
    namespace Foundation {
        namespace Store {

            class AbstractEntity : public Common::IPrintable {

            public:
                AbstractEntity(const AbstractEntity &);
                AbstractEntity(AbstractEntity &&) = default;
                AbstractEntity &operator=(const AbstractEntity &);
                AbstractEntity &operator=(AbstractEntity &&) = default;
                virtual ~AbstractEntity() = default;

                virtual void setCell(const SPtrCell &cell);
                virtual void setCell(Cell *ptrCell);
                virtual void setMultiCells(const SPtrCellVector &cellVector);
                virtual void setMultiCells(const vector<Cell *> &cellVector);

                virtual const SPtrCell &getCell(const string &columnName) const;
                virtual const SPtrCell &operator[](const string &columnName) const;
                virtual bool TryGetCell(const string &columnName, SPtrCell &sptrOutCell) const;
                virtual bool hasCell(const string &cellName) const;
                virtual unsigned long Size() const;

                const SPtrCellMap &getCellsMap() const{ return _cellMap; };

                SPtrCellVector getCells() const;
                SPtrCellVector getCells(const SPtrColumnVector &selectedColumns) const;
                SPtrColumnVector getColumns() const;

                // IPrintable
                virtual string ToString() const override;
                virtual string ToString(const Foundation::Common::IFormatter &formatter) const override;

            protected:
                AbstractEntity() = default;
                SPtrCellMap _cellMap;

            };

            using SPtrDataRecord = shared_ptr<AbstractEntity>;
        }
    }
}

#endif //CLDEPLUS_FOUNDATION_CONTRACT_IDATARECORD_H
