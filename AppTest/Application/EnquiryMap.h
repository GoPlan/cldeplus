//
// Created by LE, Duc Anh on 6/5/15.
//

#ifndef CLOUD_E_PLUS_APPTEST_APPLICATION_ENQUIRYMAP_H
#define CLOUD_E_PLUS_APPTEST_APPLICATION_ENQUIRYMAP_H

#include <memory>
#include <Foundation/EntityMap.h>
#include <Foundation/Column.h>

namespace Cloude {
    namespace AppTest{
        namespace Application {

            class EnquiryMap : public Foundation::EntityMap {

            public:
                static std::string TableName;
                static Foundation::SPtrColumn Id;
                static Foundation::SPtrColumn CustId;
                static Foundation::SPtrColumn SubmittedDate;
                static Foundation::SPtrColumn Subject;
                static Foundation::SPtrColumn Content;

            public:
                EnquiryMap();
                EnquiryMap(const EnquiryMap &) = default;
                EnquiryMap(EnquiryMap &&) = default;
                EnquiryMap &operator=(const EnquiryMap &) = default;
                EnquiryMap &operator=(EnquiryMap &&) = default;
                virtual ~EnquiryMap() = default;

            protected:
                const std::string &TableNameCore() const override;
            };
        }
    }
}


#endif //CLOUD_E_PLUS_APPTEST_APPLICATION_ENQUIRYMAP_H
