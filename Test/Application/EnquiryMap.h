//
// Created by LE, Duc Anh on 6/5/15.
//

#ifndef CLDEPLUS_APPTEST_APPLICATION_ENQUIRYMAP_H
#define CLDEPLUS_APPTEST_APPLICATION_ENQUIRYMAP_H

#include "../../Source/Foundation/EntityMap.h"

namespace CLDEPlus {

    namespace Test {
        namespace Application {

            class EnquiryMap : public Foundation::EntityMap {

                static std::string TableName;
                static Foundation::SPtrColumn Id;
                static Foundation::SPtrColumn CustId;
                static Foundation::SPtrColumn SubmittedDate;
                static Foundation::SPtrColumn SubmittedHour;
                static Foundation::SPtrColumn Subject;
                static Foundation::SPtrColumn Content;
                static Foundation::SPtrColumn UpdatedDate;

            public:
                EnquiryMap();
                EnquiryMap(const EnquiryMap &) = default;
                EnquiryMap(EnquiryMap &&) = default;
                EnquiryMap &operator=(const EnquiryMap &) = default;
                EnquiryMap &operator=(EnquiryMap &&) = default;
                virtual ~EnquiryMap() = default;
            };

            using SPtrEnquiryMap = std::shared_ptr<EnquiryMap>;
        }
    }
}


#endif //CLDEPLUS_APPTEST_APPLICATION_ENQUIRYMAP_H
