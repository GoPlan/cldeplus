//
// Created by LE, Duc Anh on 5/27/15.
//

#ifndef CLOUD_E_CPLUS_SEQUENCEMAP_H
#define CLOUD_E_CPLUS_SEQUENCEMAP_H

#include <Architecture/EntityMap.h>

namespace Cloude {
    namespace Application {
        namespace Mapper {
            class SequenceMap : public Architecture::EntityMap {
            public:
                SequenceMap();
                virtual ~SequenceMap() = default;
                SequenceMap(const SequenceMap &srcSequenceMap) = default;
                SequenceMap &operator=(const SequenceMap &srcSequenceMap) = default;

                static std::shared_ptr<Architecture::Column> Id;
                static std::shared_ptr<Architecture::Column> UniqueName;
                static std::shared_ptr<Architecture::Column> SequenceStart;
                static std::shared_ptr<Architecture::Column> SequenceCurrent;
                static std::shared_ptr<Architecture::Column> SequenceIncrement;

            protected:
                virtual std::string TableNameCore() override;
            };
        }
    }
}

#endif //CLOUD_E_CPLUS_SEQUENCEMAP_H
