//
// Created by LE, Duc Anh on 6/9/15.
//

#ifndef CLOUD_E_CPLUS_LESSER_H
#define CLOUD_E_CPLUS_LESSER_H

namespace Cloude {
    namespace Foundation {
        namespace Query {
            namespace Comparator {
                class Lesser {
                public:
                    Lesser() = default;
                    virtual ~Lesser() = default;
                    Lesser(const Lesser &rhs) = default;
                    Lesser &operator=(const Lesser &rhs) = default;
                };
            }
        }
    }
}


#endif //CLOUD_E_CPLUS_LESSER_H
