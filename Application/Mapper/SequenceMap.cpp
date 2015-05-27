//
// Created by LE, Duc Anh on 5/27/15.
//

#include "memory"
#include "SequenceMap.h"


using namespace std;
using namespace Cloude::Architecture;

namespace Cloude {
    namespace Application {
        namespace Mapper {

            std::shared_ptr<Column> SequenceMap::Id = std::make_shared<Column>("Id", "id", Enumeration::DbType::Int64);
            std::shared_ptr<Column> SequenceMap::UniqueName = std::make_shared<Column>("UniqueName", "uniquename", Enumeration::DbType::String);
            std::shared_ptr<Column> SequenceMap::SequenceStart = std::make_shared<Column>("SequenceStart", "sequencestart", Enumeration::DbType::Int64);
            std::shared_ptr<Column> SequenceMap::SequenceCurrent = std::make_shared<Column>("SequenceCurrent", "sequencecurrent", Enumeration::DbType::Int64);
            std::shared_ptr<Column> SequenceMap::SequenceIncrement = std::make_shared<Column>("SequenceIncrement", "sequenceincrement", Enumeration::DbType::Int64);

            std::string SequenceMap::TableNameCore() {
                return "Sequence";
            }

            SequenceMap::SequenceMap() {
                this->_columnsMap[Id->getName()] = Id;
                this->_columnsMap[UniqueName->getName()] = UniqueName;
                this->_columnsMap[SequenceStart->getName()] = SequenceStart;
                this->_columnsMap[SequenceCurrent->getName()] = SequenceCurrent;
                this->_columnsMap[SequenceIncrement->getName()] = SequenceIncrement;

                this->_columnsForKey.push_back(Id);
                this->_columnsForSelect.push_back(Id);
                this->_columnsForSelect.push_back(UniqueName);
                this->_columnsForUpdate.push_back(UniqueName);
                this->_columnsForUpdate.push_back(SequenceStart);
                this->_columnsForUpdate.push_back(SequenceCurrent);
                this->_columnsForUpdate.push_back(SequenceIncrement);
            }
        }
    }
}

