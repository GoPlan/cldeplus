//
// Created by LE, Duc Anh on 6/5/15.
//

#include "EnquiryMap.h"

using namespace std;
using namespace Cloude::Framework;

namespace Cloude {
    namespace Application {
        namespace Mapper {

            std::string EnquiryMap::TableName = "Enquiry";

            std::shared_ptr<Column> EnquiryMap::EnquiryId = make_shared<Column>("EnquiryId",
                                                                                "EnquiryId",
                                                                                Enumeration::DbType::Int64);

            std::shared_ptr<Column> EnquiryMap::ObjectId = make_shared<Column>("ObjectId",
                                                                               "_id",
                                                                               Enumeration::DbType::String);

            std::shared_ptr<Column> EnquiryMap::Email = make_shared<Column>("Email",
                                                                            "Email",
                                                                            Enumeration::DbType::String);

            std::shared_ptr<Column> EnquiryMap::Subject = make_shared<Column>("Subject",
                                                                              "Subject",
                                                                              Enumeration::DbType::String);

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
