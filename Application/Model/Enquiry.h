//
// Created by LE, Duc Anh on 6/5/15.
//

#ifndef CLOUD_E_CPLUS_ENQUIRY_H
#define CLOUD_E_CPLUS_ENQUIRY_H

namespace Cloude {
    namespace Application {
        namespace Model {
            class Enquiry {
            public:
                Enquiry() = default;
                virtual ~Enquiry() = default;
                Enquiry(const Enquiry &srcEnquiry) = default;
                Enquiry &operator=(const Enquiry &srcEnquiry) = default;
            };
        }
    }
}


#endif //CLOUD_E_CPLUS_ENQUIRY_H
