//
// Created by LE, Duc Anh on 6/9/15.
//

#ifndef CLOUD_E_CPLUS_PREDICATION_H
#define CLOUD_E_CPLUS_PREDICATION_H

namespace Cloude {
    namespace Foundation {
        namespace Query{
            class Predication {
            public:
                Predication() = default;
                virtual ~Predication() = default;
                Predication(const Predication &srcExpression) = default;
                Predication &operator=(const Predication &srcExpression) = default;

            };
        }
    }
}


#endif //CLOUD_E_CPLUS_PREDICATION_H
