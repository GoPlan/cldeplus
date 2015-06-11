//
// Created by LE, Duc Anh on 6/9/15.
//

#ifndef CLOUD_E_CPLUS_PREDICATION_H
#define CLOUD_E_CPLUS_PREDICATION_H

#include <Foundation/Common/IPrintable.h>
#include <Foundation/Query/Enumeration/ComparatorType.h>
#include <Foundation/Type/cldeValue.h>

namespace Cloude {
    namespace Foundation {
        namespace Query {
            class Predication : public Common::IPrintable {
            public:
                Predication() = delete;
                virtual ~Predication() = 0;
                Predication(const Predication &srcExpression) = default;
                Predication &operator=(const Predication &srcExpression) = default;

                virtual Enumeration::ComparatorType getType() = 0;
                virtual Type::cldeValue getValue() = 0;
            };
        }
    }
}


#endif //CLOUD_E_CPLUS_PREDICATION_H
