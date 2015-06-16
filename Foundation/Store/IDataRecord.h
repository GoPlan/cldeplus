//
// Created by LE, Duc Anh on 6/16/15.
//

#ifndef CLOUD_E_PLUS_FOUNDATION_CONTRACT_IRECORD_H
#define CLOUD_E_PLUS_FOUNDATION_CONTRACT_IRECORD_H

#include <Foundation/Field.h>

namespace Cloude {
    namespace Foundation {
        namespace Store {

            class IDataRecord {

            public:
                virtual ~IDataRecord() = default;
                IDataRecord(const IDataRecord &) = default;
                IDataRecord(IDataRecord &&) = default;
                IDataRecord &operator=(const IDataRecord &) = default;
                IDataRecord &operator=(IDataRecord &&) = default;

                virtual void setField(const SPtrField &field);
                virtual void setField(Field *ptrField);
                virtual void setMultiFields(const SPtrFieldVector &fieldVector);
                virtual void setMultiFields(const std::vector<Field *> &fieldVector);

                virtual const SPtrField &operator[](const std::string &columnName) const;
                virtual const SPtrField &operator[](const char *columnName) const;
                virtual const SPtrField &getField(const std::string &columnName) const;
                virtual const SPtrField &getField(const char *columnName) const;

                virtual bool HasField(const std::string &fieldName);
                virtual unsigned long Size();

                const SPtrFieldMap &getFieldsMap() { return _fieldMap; };

            protected:
                IDataRecord() = default;
                SPtrFieldMap _fieldMap;
            };
        }
    }
}

#endif //CLOUD_E_PLUS_FOUNDATION_CONTRACT_IRECORD_H
