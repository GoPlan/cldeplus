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

                Column &column() const {
                    return _column;
                }
                void setColumn(Column &column) {
                    _column = column;
                }
                void *value() const {
                    return _value;
                }
                void setValue(void *value) {
                    _value = value;
                }
                
            private:
                Column &_column;
                void *_value;
            };

        }
    }
}


#endif //CLOUD_E_CPLUS_FIELD_H
