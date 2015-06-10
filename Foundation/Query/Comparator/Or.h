//
// Created by LE, Duc Anh on 6/9/15.
//

#ifndef CLOUD_E_CPLUS_OR_H
#define CLOUD_E_CPLUS_OR_H

#include <Foundation/Query/Predication.h>

namespace Cloude {
    namespace Foundation {
        namespace Query {
            namespace Comparator {
                class Or : public Query::Predication {
                public:
                    Or() = default;
                    virtual ~Or() = default;
                    Or(const Or &rhs) = default;
                    Or &operator=(const Or &rhs) = default;


                    virtual const std::string CopyToString() const override;
                    virtual Enumeration::ComparatorType getType() override;
                private:
                    static std::string _type;
                };
            }
        }
    }
}


#endif //CLOUD_E_CPLUS_OR_H
