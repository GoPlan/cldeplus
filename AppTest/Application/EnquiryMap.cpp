//
// Created by LE, Duc Anh on 6/5/15.
//

#include "EnquiryMap.h"

namespace Cloude {
    namespace AppTest {
        namespace Application {

            std::string EnquiryMap::TableName = "Enquiry";

            Foundation::SPtrColumn EnquiryMap::Id = Foundation::CreateColumn("Id", "id", Foundation::Data::ValueType::Int64);
            Foundation::SPtrColumn EnquiryMap::CustId = Foundation::CreateColumn("CustId", "custid", Foundation::Data::ValueType::Int64);
            Foundation::SPtrColumn EnquiryMap::SubmittedDate = Foundation::CreateColumn("SubmittedDate", "submitteddate", Foundation::Data::ValueType::Date);
            Foundation::SPtrColumn EnquiryMap::SubmittedHour = Foundation::CreateColumn("SubmittedHour", "submittedhour", Foundation::Data::ValueType::Time);
            Foundation::SPtrColumn EnquiryMap::Subject = Foundation::CreateColumn("Subject", "subject", 255, Foundation::Data::ValueType::VarChar);
            Foundation::SPtrColumn EnquiryMap::Content = Foundation::CreateColumn("Content", "content", Foundation::Data::ValueType::Text);
            Foundation::SPtrColumn EnquiryMap::UpdatedDate = Foundation::CreateColumn("UpdatedDate", "updateddate", Foundation::Data::ValueType::DateTime);

            const std::string &EnquiryMap::TableNameCore() const {
                return TableName;
            }

            EnquiryMap::EnquiryMap() {
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
