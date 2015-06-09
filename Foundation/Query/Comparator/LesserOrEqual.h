//
// Created by LE, Duc Anh on 6/9/15.
//

#ifndef CLOUD_E_CPLUS_LESSEROREQUAL_H
#define CLOUD_E_CPLUS_LESSEROREQUAL_H

namespace Cloude {
    namespace Foundation {
        namespace Query {
            namespace Comparator {
                class LesserOrEqual {
                public:
                    LesserOrEqual() = default;
                    virtual ~LesserOrEqual() = default;
                    LesserOrEqual(const LesserOrEqual &rhs) = default;
                    LesserOrEqual &operator=(const LesserOrEqual &rhs) = default;
                };
            }
        }
    }
}


#endif //CLOUD_E_CPLUS_LESSEROREQUAL_H
