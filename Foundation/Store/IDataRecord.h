//
// Created by LE, Duc Anh on 6/16/15.
//

#ifndef CLOUD_E_PLUS_FOUNDATION_CONTRACT_IRECORD_H
#define CLOUD_E_PLUS_FOUNDATION_CONTRACT_IRECORD_H

#include <Foundation/Cell.h>

namespace Cloude {
    namespace Foundation {
        namespace Store {

            class IDataRecord : public Common::IPrintable {

            public:
                IDataRecord(const IDataRecord &) = default;
                IDataRecord(IDataRecord &&) = default;
                IDataRecord &operator=(const IDataRecord &) = default;
                IDataRecord &operator=(IDataRecord &&) = default;
                virtual ~IDataRecord() = default;

                virtual void setCell(const SPtrCell &cell);
                virtual void setCell(Cell *ptrCell);
                virtual void setMultiCells(const SPtrCellVector &cellVector);
                virtual void setMultiCells(const std::vector<Cell *> &cellVector);

                virtual const SPtrCell &operator[](const std::string &columnName) const;
                virtual const SPtrCell &operator[](const char *columnName) const;
                virtual const SPtrCell &getCell(const std::string &columnName) const;
                virtual const SPtrCell &getCell(const char *columnName) const;

                virtual bool hasCell(const std::string &cellName);
                virtual unsigned long Size();

                const SPtrCellMap &getCellsMap() { return _cellMap; };

                SPtrCellVector getCells() const;
                SPtrColumnVector getColumns() const;

                // IPrintable
                const std::string CopyToString() const override;
                const std::string &ToString() const override;
                const char *ToCString() const override;

            protected:
                IDataRecord() = default;
                SPtrCellMap _cellMap;

            };

            using SPtrDataRecord = std::shared_ptr<IDataRecord>;
        }
    }
}

#endif //CLOUD_E_PLUS_FOUNDATION_CONTRACT_IRECORD_H
