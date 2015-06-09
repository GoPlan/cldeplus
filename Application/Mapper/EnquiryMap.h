//
// Created by LE, Duc Anh on 6/5/15.
//

#ifndef CLOUD_E_CPLUS_ENQUIRYMAP_H
#define CLOUD_E_CPLUS_ENQUIRYMAP_H

#include <memory>
#include <Foundation/EntityMap.h>
#include <Foundation/Column.h>

namespace Cloude {
    namespace Application {
        namespace Mapper {

            using EntityMap = Foundation::EntityMap;
            using Column = Foundation::Column;

            class EnquiryMap : public EntityMap {
            public:
                static std::string TableName;
                static std::shared_ptr<Column> EnquiryId;
                static std::shared_ptr<Column> ObjectId;
                static std::shared_ptr<Column> Email;
                static std::shared_ptr<Column> Subject;

            public:
                virtual ~EnquiryMap() = default;
                EnquiryMap(const EnquiryMap &srcEnquiryMap) = default;
                EnquiryMap &operator=(const EnquiryMap &srcEnquiryMap) = default;

                EnquiryMap();

            protected:
                virtual const std::string &TableNameCore() const;
            };
        }
    }
}


#endif //CLOUD_E_CPLUS_ENQUIRYMAP_H
