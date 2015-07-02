//
// Created by LE, Duc Anh on 6/5/15.
//

#include "EnquiryMap.h"

namespace Cloude {
    namespace AppTest {
        namespace Application {

            std::string EnquiryMap::TableName = "Enquiry";

            Foundation::SPtrColumn EnquiryMap::EnquiryId = std::make_shared<Foundation::Column>("EnquiryId", "EnquiryId", Foundation::Data::ValueType::Int64);
            Foundation::SPtrColumn EnquiryMap::ObjectId = std::make_shared<Foundation::Column>("ObjectId", "_id", Foundation::Data::ValueType::VarChar);
            Foundation::SPtrColumn EnquiryMap::Email = std::make_shared<Foundation::Column>("Email", "Email", Foundation::Data::ValueType::VarChar);
            Foundation::SPtrColumn EnquiryMap::Subject = std::make_shared<Foundation::Column>("Subject", "Subject", Foundation::Data::ValueType::VarChar);

            const std::string &EnquiryMap::TableNameCore() const {
                return TableName;
            }

            EnquiryMap::EnquiryMap() {
                this->_columnsForKey.push_back(EnquiryId);
                this->_columnsForGet.push_back(Email);
                this->_columnsForGet.push_back(Subject);
                this->_columnsForUpdate.push_back(Email);
                this->_columnsForUpdate.push_back(Subject);
                this->_columnsForSelect.push_back(Email);
                this->_columnsForSelect.push_back(Subject);
            }
        }
    }
}
