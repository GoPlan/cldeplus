//
// Created by LE, Duc Anh on 14/05/2015.
//

#ifndef CLOUD_E_CPLUS_FOUNDATION_ENTITYMAP_H
#define CLOUD_E_CPLUS_FOUNDATION_ENTITYMAP_H

#include "cldeplus_default"
#include "Exception/CLDEEntityMapException.h"
#include "Column.h"

namespace CLDEPlus {
    namespace Foundation {

        class EntityMap {

        public:
            EntityMap(std::string const &tableName) : _tableName{tableName} { };
            EntityMap(const EntityMap &) = default;
            EntityMap(EntityMap &&) = default;
            EntityMap &operator=(const EntityMap &) = default;
            EntityMap &operator=(EntityMap &&) = default;
            virtual ~EntityMap() = default;

            std::string const &getTableName() const { return _tableName; }
            SPtrColumnMap const &getColumnsMap() const { return _columnsMap; }
            SPtrColumnVector const &getColumnsForKey() const { return _columnsForKey; }
            SPtrColumnVector const &getColumnsForGet() const { return _columnsForGet; }
            SPtrColumnVector const &getColumnsForUpdate() const { return _columnsForUpdate; }
            SPtrColumnVector const &getColumnsForSelect() const { return _columnsForSelect; }

            bool HasColumn(std::string const &name) const;
            void SetColumn(std::string const &name, SPtrColumn const &sptrColumn);
            SPtrColumn const &GetColumn(std::string const &name) const;

            void AddGetColumn(SPtrColumn const &sptrColumn) { _columnsForGet.push_back(sptrColumn); }
            void AddKeyColumn(SPtrColumn const &sptrColumn) { _columnsForKey.push_back(sptrColumn); }
            void AddUpdateColumn(SPtrColumn const &sptrColumn) { _columnsForUpdate.push_back(sptrColumn); }
            void AddSelectColumn(SPtrColumn const &sptrColumn) { _columnsForSelect.push_back(sptrColumn); }

        protected:

            SPtrColumnMap _columnsMap;
            SPtrColumnVector _columnsForKey;
            SPtrColumnVector _columnsForGet;
            SPtrColumnVector _columnsForUpdate;
            SPtrColumnVector _columnsForSelect;

            std::string _tableName;
        };

        using UPtrEntityMap = std::unique_ptr<EntityMap>;
        using SPtrEntityMap = std::shared_ptr<EntityMap>;
    }
}


#endif //CLOUD_E_CPLUS_FOUNDATION_ENTITYMAP_H
