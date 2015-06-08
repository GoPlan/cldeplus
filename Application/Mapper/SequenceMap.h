//
// Created by LE, Duc Anh on 5/27/15.
//

#ifndef CLOUD_E_CPLUS_SEQUENCEMAP_H
#define CLOUD_E_CPLUS_SEQUENCEMAP_H

#include <Framework/EntityMap.h>

namespace Cloude {
    namespace Application {
        namespace Mapper {
            class SequenceMap : public Framework::EntityMap {
            public:
                SequenceMap();
                virtual ~SequenceMap() = default;
                SequenceMap(const SequenceMap &srcSequenceMap) = default;
                SequenceMap &operator=(const SequenceMap &srcSequenceMap) = default;

                static std::string TableName;

                static std::shared_ptr<Framework::Column> Id;
                static std::shared_ptr<Framework::Column> UniqueName;
                static std::shared_ptr<Framework::Column> SequenceStart;
                static std::shared_ptr<Framework::Column> SequenceCurrent;
                static std::shared_ptr<Framework::Column> SequenceIncrement;

            protected:
                virtual const std::string &TableNameCore() const override;
            };
        }
    }
}

#endif //CLOUD_E_CPLUS_SEQUENCEMAP_H
