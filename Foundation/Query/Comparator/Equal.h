//
// Created by LE, Duc Anh on 6/9/15.
//

#ifndef CLOUD_E_CPLUS_EQUAL_H
#define CLOUD_E_CPLUS_EQUAL_H

#include <Foundation/Query/Predication.h>

namespace Cloude {
    namespace Foundation {
        namespace Query {
            namespace Comparator {
                class Equal : public Query::Predication {
                public:
                    Equal() = default;
                    virtual ~Equal() = default;
                    Equal(const Equal &rhs) = default;
                    Equal &operator=(const Equal &rhs) = default;

                    virtual const std::string CopyToString() const override;
                    virtual Enumeration::ComparatorType getType() override;

                private:
                    static std::string _type;
                };
            }
        }
    }
}


#endif //CLOUD_E_CPLUS_EQUAL_H
