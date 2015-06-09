//
// Created by LE, Duc Anh on 5/27/15.
//

#ifndef CLOUD_E_CPLUS_SEQUENCELOADER_H
#define CLOUD_E_CPLUS_SEQUENCELOADER_H

#include <Foundation/EntityLoader.h>

namespace Cloude {
    namespace Application {
        namespace Mapper {
            class SequenceLoader : public Foundation::EntityLoader {
            public:
                SequenceLoader() = default;
                virtual ~SequenceLoader() = default;
                SequenceLoader(const SequenceLoader &srcSequenceLoader) = default;
                SequenceLoader &operator=(const SequenceLoader &srcSequenceLoader) = default;

                virtual std::shared_ptr<Foundation::Identity> NextPrimaryKey() const override;
            };

        }
    }
}


#endif //CLOUD_E_CPLUS_SEQUENCELOADER_H
