//
// Created by LE, Duc Anh on 6/10/15.
//

#ifndef CLOUD_E_CPLUS_CLDECHARACTERVALUE_H
#define CLOUD_E_CPLUS_CLDECHARACTERVALUE_H

#include "cldeValue.h"

namespace Cloude {
    namespace Foundation {
        namespace Type {
            class cldeCharacterValue : public cldeValue {
            public:
                cldeCharacterValue(cldeValueType dataType, size_t length);
                virtual ~cldeCharacterValue() = default;
                cldeCharacterValue(const cldeCharacterValue &rhs) = default;
                cldeCharacterValue &operator=(const cldeCharacterValue &rhs) = default;

                cldeValueCategory getCategory() override;
                bool isNumeric() override;
            };
        }
    }
}


#endif //CLOUD_E_CPLUS_CLDECHARACTERVALUE_H
