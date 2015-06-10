//
// Created by LE, Duc Anh on 6/9/15.
//

#ifndef CLOUD_E_CPLUS_AND_H
#define CLOUD_E_CPLUS_AND_H

#include <string>
#include <Foundation/Query/Predication.h>

namespace Cloude {
    namespace Foundation {
        namespace Query {
            namespace Comparator {
                class And : public Query::Predication {
                public:
                    And() = default;
                    virtual ~And() = default;
                    And(const And &rhs) = default;
                    And &operator=(const And &rhs) = default;

                    const std::string ToString() const override;
                    Enumeration::ComparatorType getType() override;

                private:
                    static std::string _type;

                };
            }
        }
    }
}


#endif //CLOUD_E_CPLUS_AND_H
