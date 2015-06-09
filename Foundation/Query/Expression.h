//
// Created by LE, Duc Anh on 6/9/15.
//

#ifndef CLOUD_E_CPLUS_EXPRESSION_H
#define CLOUD_E_CPLUS_EXPRESSION_H

namespace Cloude {
    namespace Foundation {
        namespace Query {
            class Expression {
            public:
                Expression() = default;
                virtual ~Expression() = default;
                Expression(const Expression &srcExpression) = default;
                Expression &operator=(const Expression &srcExpression) = default;

            };
        }
    }
}


#endif //CLOUD_E_CPLUS_EXPRESSION_H
