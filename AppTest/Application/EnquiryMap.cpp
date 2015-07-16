//
// Created by LE, Duc Anh on 6/5/15.
//

#include "EnquiryMap.h"

namespace Cloude {
    namespace AppTest {
        namespace Application {

            std::string EnquiryMap::TableName = "Enquiry";

            Foundation::SPtrColumn EnquiryMap::Id = std::make_shared<Foundation::Column>("Id", "id", Foundation::Data::ValueType::Int64);
            Foundation::SPtrColumn EnquiryMap::CustId = std::make_shared<Foundation::Column>("CustId", "custid", Foundation::Data::ValueType::Int64);
            Foundation::SPtrColumn EnquiryMap::SubmittedDate = std::make_shared<Foundation::Column>("SubmittedDate", "submitteddate", Foundation::Data::ValueType::Date);
            Foundation::SPtrColumn EnquiryMap::Subject = std::make_shared<Foundation::Column>("Subject", "subject", Foundation::Data::ValueType::VarChar);
            Foundation::SPtrColumn EnquiryMap::Content = std::make_shared<Foundation::Column>("Subject", "content", Foundation::Data::ValueType::Text);

            const std::string &EnquiryMap::TableNameCore() const {
                return TableName;
            }

            EnquiryMap::EnquiryMap() {
                this->_columnsForKey.push_back(Id);
                this->_columnsForGet.push_back(CustId);
//                this->_columnsForGet.push_back(SubmittedDate);
                this->_columnsForGet.push_back(Subject);
                this->_columnsForGet.push_back(Content);
                this->_columnsForUpdate.push_back(CustId);
//                this->_columnsForUpdate.push_back(SubmittedDate);
                this->_columnsForUpdate.push_back(Subject);
                this->_columnsForUpdate.push_back(Content);
                this->_columnsForSelect.push_back(CustId);
                this->_columnsForSelect.push_back(Subject);
            }
        }
    }
}
