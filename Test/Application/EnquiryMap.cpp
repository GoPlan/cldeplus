//
// Created by LE, Duc Anh on 6/5/15.
//

#include "EnquiryMap.h"

namespace CLDEPlus {
    namespace Test {
        namespace Application {

            std::string EnquiryMap::TableName = "Enquiry";

            Foundation::SPtrColumn EnquiryMap::Id = Foundation::CreateColumn("Id",
                                                                             Foundation::Data::ValueType::Int64,
                                                                             "id");
            Foundation::SPtrColumn EnquiryMap::CustId = Foundation::CreateColumn("CustId",
                                                                                 Foundation::Data::ValueType::Int64,
                                                                                 "custid");
            Foundation::SPtrColumn EnquiryMap::SubmittedDate = Foundation::CreateColumn("SubmittedDate",
                                                                                        Foundation::Data::ValueType::Date,
                                                                                        "submitteddate");
            Foundation::SPtrColumn EnquiryMap::SubmittedHour = Foundation::CreateColumn("SubmittedHour",
                                                                                        Foundation::Data::ValueType::Time,
                                                                                        "submittedhour");
            Foundation::SPtrColumn EnquiryMap::Subject = Foundation::CreateColumn("Subject",
                                                                                  Foundation::Data::ValueType::VarChar,
                                                                                  "subject",
                                                                                  255);
            Foundation::SPtrColumn EnquiryMap::Content = Foundation::CreateColumn("Content",
                                                                                  Foundation::Data::ValueType::Text,
                                                                                  "content");
            Foundation::SPtrColumn EnquiryMap::UpdatedDate = Foundation::CreateColumn("UpdatedDate",
                                                                                      Foundation::Data::ValueType::DateTime,
                                                                                      "updateddate");

            EnquiryMap::EnquiryMap() : EntityMap(TableName) {

                SetColumn("Id", Id);
                SetColumn("CustId", CustId);
                SetColumn("SubmittedDate", SubmittedDate);
                SetColumn("SubmittedHour", SubmittedHour);
                SetColumn("Subject", Subject);
                SetColumn("Content", Content);
                SetColumn("UpdatedDate", UpdatedDate);

                this->_columnsForKey.push_back(Id);
                this->_columnsForGet.push_back(CustId);
                this->_columnsForGet.push_back(SubmittedDate);
                this->_columnsForGet.push_back(SubmittedHour);
                this->_columnsForGet.push_back(Subject);
                this->_columnsForGet.push_back(Content);
                this->_columnsForGet.push_back(UpdatedDate);
                this->_columnsForUpdate.push_back(CustId);
                this->_columnsForUpdate.push_back(SubmittedDate);
                this->_columnsForUpdate.push_back(SubmittedHour);
                this->_columnsForUpdate.push_back(Subject);
                this->_columnsForUpdate.push_back(Content);
                this->_columnsForUpdate.push_back(UpdatedDate);
                this->_columnsForSelect.push_back(CustId);
                this->_columnsForSelect.push_back(Subject);
            }
        }
    }
}
