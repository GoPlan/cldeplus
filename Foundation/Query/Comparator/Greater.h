//
// Created by LE, Duc Anh on 6/9/15.
//

#ifndef CLOUD_E_CPLUS_GREATER_H
#define CLOUD_E_CPLUS_GREATER_H


#include <Foundation/Query/Predication.h>

namespace Cloude {
    namespace Foundation {
        namespace Query {
            namespace Comparator {
                class Greater : public Query::Predication {
                public:
                    Greater() = default;
                    virtual ~Greater() = default;
                    Greater(const Greater &rhs) = default;
                    Greater &operator=(const Greater &rhs) = default;

                    virtual const std::string CopyToString() const override;
                    virtual Enumeration::ComparatorType getType() override;

                private:
                    static std::string _type;
                };
            }
        }
    }
}


#endif //CLOUD_E_CPLUS_GREATER_H
