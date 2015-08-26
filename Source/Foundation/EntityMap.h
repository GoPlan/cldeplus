//
// Created by LE, Duc Anh on 14/05/2015.
//

#ifndef CLOUD_E_CPLUS_FOUNDATION_ENTITYMAP_H
#define CLOUD_E_CPLUS_FOUNDATION_ENTITYMAP_H

#include <memory>
#include <vector>
#include <string>
#include "Exception/CLDEEntityMapException.h"
#include "Column.h"

namespace Cloude {
    namespace Foundation {

        class EntityMap {

        public:
            EntityMap(const EntityMap &) = delete;
            EntityMap(EntityMap &&) = delete;
            EntityMap &operator=(const EntityMap &) = delete;
            EntityMap &operator=(EntityMap &&) = delete;
            virtual ~EntityMap() = default;

            std::string const &getTableName() const { return TableNameCore(); }
            SPtrColumnMap const &getColumnsMap() const { return _columnsMap; }
            SPtrColumnVector const &getColumnsForKey() const { return _columnsForKey; }
            SPtrColumnVector const &getColumnsForGet() const { return _columnsForGet; }
            SPtrColumnVector const &getColumnsForUpdate() const { return _columnsForUpdate; }
            SPtrColumnVector const &getColumnsForSelect() const { return _columnsForSelect; }

            bool HasColumn(std::string const &name) const;
            void SetColumn(std::string const &name, SPtrColumn const &sptrColumn);
            SPtrColumn const &GetColumn(std::string const &name) const;

        protected:
            EntityMap() = default;

            SPtrColumnMap _columnsMap;
            SPtrColumnVector _columnsForKey;
            SPtrColumnVector _columnsForGet;
            SPtrColumnVector _columnsForUpdate;
            SPtrColumnVector _columnsForSelect;

            virtual const std::string &TableNameCore() const = 0;
        };

        using SPtrEntityMap = std::shared_ptr<EntityMap>;
    }
}


#endif //CLOUD_E_CPLUS_FOUNDATION_ENTITYMAP_H
