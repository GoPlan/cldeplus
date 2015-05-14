//
// Created by GoPlan on 14/05/2015.
//

#ifndef CLOUD_E_CPLUS_FIELD_H
#define CLOUD_E_CPLUS_FIELD_H

#include "Column.h"

namespace Cloude {
    namespace Architecture {
        namespace Foundation {

            class Field {

            public:
                Field(Column &column, void *value);

                virtual ~Field();

                Column &getColumn() const {
                    return column;
                }

                void *getValue() const {
                    return value;
                }

            private:
                Column &column;
                void *value;
            };

        }
    }
}


#endif //CLOUD_E_CPLUS_FIELD_H
