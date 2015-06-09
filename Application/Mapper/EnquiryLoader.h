//
// Created by LE, Duc Anh on 6/5/15.
//

#ifndef CLOUD_E_CPLUS_ENQUIRYLOADER_H
#define CLOUD_E_CPLUS_ENQUIRYLOADER_H

#include <memory>
#include <Foundation/EntityLoader.h>

namespace Cloude {
    namespace Application {
        namespace Mapper {

            using EntityLoader = Foundation::EntityLoader;
            using Identity = Foundation::Identity;

            class EnquiryLoader : public EntityLoader {
            public:
                EnquiryLoader() = default;
                virtual ~EnquiryLoader() = default;
                EnquiryLoader(const EnquiryLoader &srcEnquiryLoader) = default;
                EnquiryLoader &operator=(const EnquiryLoader &srcEnquiryLoader) = default;

                virtual std::shared_ptr<Identity> NextPrimaryKey() const override;
            };
        }
    }
}


#endif //CLOUD_E_CPLUS_ENQUIRYLOADER_H
