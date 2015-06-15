//
// Created by LE, Duc Anh on 5/26/15.
//

#ifndef CLOUD_E_CPLUS_FOUNDATION_QUERY_SQLGENERATOR_H
#define CLOUD_E_CPLUS_FOUNDATION_QUERY_SQLGENERATOR_H

#include <memory>
#include <vector>
#include <functional>

namespace Cloude {
    namespace Foundation {

        class Column;
        class EntityMap;

        namespace Type {
            class cldeValue;
        }

        namespace Query {

            class Predicate;

            using EntityMap = Foundation::EntityMap;
            using Predicate = Foundation::Query::Predicate;
            using SPtrColumn = std::shared_ptr<Foundation::Column>;
            using SPtrValue = std::shared_ptr<Foundation::Type::cldeValue>;
            using FPtrParamProcessor = std::function<std::string(const SPtrColumn &column, int index)>;

            using SelectCompound = struct {
                std::string statement;
                std::vector<SPtrValue> params;
            };

            std::string CreateGetPreparedQuery(const EntityMap &entityMap, FPtrParamProcessor fptr);
            std::string CreateInsertPreparedQuery(const EntityMap &entityMap, FPtrParamProcessor fptr);
            std::string CreateUpdatePreparedQuery(const EntityMap &entityMap, FPtrParamProcessor fptrParamProc);
            std::string CreateDeletePreparedQuery(const EntityMap &entityMap, FPtrParamProcessor fptrP);

            SelectCompound CreateSelectPreparedQuery(const EntityMap &entityMap,
                                                     const Predicate &predicate,
                                                     FPtrParamProcessor fptr);
        }
    }
}


#endif //CLOUD_E_CPLUS_FOUNDATION_QUERY_SQLGENERATOR_H
