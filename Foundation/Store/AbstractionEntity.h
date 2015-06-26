//
// Created by LE, Duc Anh on 6/16/15.
//

#ifndef CLOUD_E_PLUS_FOUNDATION_CONTRACT_IDATARECORD_H
#define CLOUD_E_PLUS_FOUNDATION_CONTRACT_IDATARECORD_H

#include <Foundation/Cell.h>

namespace Cloude {
    namespace Foundation {
        namespace Store {

            class AbstractionEntity : public Common::IPrintable {

            public:
                AbstractionEntity(const AbstractionEntity &) = default;
                AbstractionEntity(AbstractionEntity &&) = default;
                AbstractionEntity &operator=(const AbstractionEntity &) = default;
                AbstractionEntity &operator=(AbstractionEntity &&) = default;
                virtual ~AbstractionEntity() = default;

                virtual void setCell(const SPtrCell &cell);
                virtual void setCell(Cell *ptrCell);
                virtual void setMultiCells(const SPtrCellVector &cellVector);
                virtual void setMultiCells(const std::vector<Cell *> &cellVector);

                virtual const SPtrCell &getCell(const std::string &columnName) const;
                virtual const SPtrCell &operator[](const std::string &columnName) const;

                virtual bool TryGetCell(const std::string &columnName, SPtrCell &sptrOutCell) const;

                virtual bool hasCell(const std::string &cellName);
                virtual unsigned long Size();

                const SPtrCellMap &getCellsMap() { return _cellMap; };

                SPtrCellVector getCells() const;
                SPtrCellVector getCells(const SPtrColumnVector &selectedColumns) const;

                SPtrColumnVector getColumns() const;

                // IPrintable
                const std::string CopyToString() const override;
                const std::string &ToString() const override;
                const char *ToCString() const override;

            protected:
                AbstractionEntity() = default;
                SPtrCellMap _cellMap;

            };

            using SPtrDataRecord = std::shared_ptr<AbstractionEntity>;
        }
    }
}

#endif //CLOUD_E_PLUS_FOUNDATION_CONTRACT_IDATARECORD_H
