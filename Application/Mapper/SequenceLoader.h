//
// Created by LE, Duc Anh on 5/27/15.
//

#ifndef CLOUD_E_CPLUS_SEQUENCELOADER_H
#define CLOUD_E_CPLUS_SEQUENCELOADER_H

#include <Architecture/EntityLoader.h>

namespace Cloude {
    namespace Application {
        namespace Mapper {
            class SequenceLoader : public Architecture::EntityLoader {
            public:
                SequenceLoader() = default;
                virtual ~SequenceLoader() = default;
                SequenceLoader(const SequenceLoader &srcSequenceLoader) = default;
                SequenceLoader &operator=(const SequenceLoader &srcSequenceLoader) = default;

                virtual std::shared_ptr<Architecture::Identity> NextPrimaryKey() override;
                virtual void LoadEntity(std::shared_ptr<Architecture::Identity> &identity) override;
            };

        }
    }
}


#endif //CLOUD_E_CPLUS_SEQUENCELOADER_H
