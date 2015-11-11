//
// Created by LE, Duc Anh on 11/9/15.
//

#ifndef CLDEPLUS_FOUNDATION_DATA_HELPER_PRIMITIVEHELPER_H
#define CLDEPLUS_FOUNDATION_DATA_HELPER_PRIMITIVEHELPER_H

namespace CLDEPlus {
    namespace Foundation {
        namespace Data {
            namespace Helper {

                struct PrimitiveHelper {
                    template<typename T>
                    static T ToPrimitive(SPtrValue const &value) {

                        if (!value->isNumeric() || value->getCategory() != ValueCategory::Numeric) {
                            string msg{"Value is not numeric"};
                            throw Exception::CLDENonSupportedDataTypeException{msg};
                        }

                        T const *ptrResult = reinterpret_cast<const T *>(value->PointerToBuffer());

                        return *ptrResult;
                    };
                };
            }
        }
    }
}


#endif //CLDEPLUS_FOUNDATION_DATA_HELPER_PRIMITIVEHELPER_H
