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

                virtual void setField(const SPtrCell &cell);
                virtual void setField(Cell *ptrCell);
                virtual void setMultiFields(const SPtrCellVector &cellVector);
                virtual void setMultiFields(const std::vector<Cell *> &cellVector);

                virtual const SPtrCell &operator[](const std::string &columnName) const;
                virtual const SPtrCell &operator[](const char *columnName) const;
                virtual const SPtrCell &getField(const std::string &columnName) const;
                virtual const SPtrCell &getField(const char *columnName) const;

                virtual bool HasCell(const std::string &cellName);
                virtual unsigned long Size();

                const SPtrCellMap &getCellsMap() { return _cellMap; };

                SPtrCellVector getFields() const;
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
