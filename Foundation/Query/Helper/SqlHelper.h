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

            namespace Helper {

                class SqlHelper {

                public:
                    using EntityMap = Foundation::EntityMap;
                    using Predicate = Foundation::Query::Predicate;
                    using SPtrPredicate = std::shared_ptr<Predicate>;
                    using SPtrColumn = std::shared_ptr<Foundation::Column>;
                    using SPtrValue = std::shared_ptr<Foundation::Type::cldeValue>;
                    using FPtrParamProcessor = std::function<std::string(const SPtrColumn &column, const int &index)>;

                public:
                    static std::string CreateGetPreparedQuery(const EntityMap &entityMap, FPtrParamProcessor fptr);
                    static std::string CreateInsertPreparedQuery(const EntityMap &entityMap, FPtrParamProcessor fptr);
                    static std::string CreateUpdatePreparedQuery(const EntityMap &entityMap, FPtrParamProcessor fptr);
                    static std::string CreateDeletePreparedQuery(const EntityMap &entityMap, FPtrParamProcessor fptr);

                    static std::pair<std::string, std::vector<SPtrPredicate>>
                            CreateSelectPreparedQuery(const EntityMap &entityMap,
                                                      const SPtrPredicate &sptrPredicate,
                                                      const FPtrParamProcessor fptr);
                };
            }
        }
    }
}


#endif //CLOUD_E_CPLUS_FOUNDATION_QUERY_SQLGENERATOR_H
