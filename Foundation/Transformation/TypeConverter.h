//
// Created by LE, Duc Anh on 6/30/15.
//

#ifndef CLOUD_E_PLUS_FOUNDATION_TRANSFORMATION_TYPECONVERTER_H
#define CLOUD_E_PLUS_FOUNDATION_TRANSFORMATION_TYPECONVERTER_H

#include <memory>

namespace Cloude {
    namespace Foundation {
        namespace Transformation {

            class TypeConverter {

            public:
                TypeConverter() = default;
                TypeConverter(const TypeConverter &) = default;
                TypeConverter(TypeConverter &&) = default;
                TypeConverter &operator=(const TypeConverter &) = default;
                TypeConverter &operator=(TypeConverter &&) = default;
                virtual ~TypeConverter() = default;
            };

            using SPtrTypeConverter = std::shared_ptr <TypeConverter>;
        }
    }
}


#endif //CLOUD_E_PLUS_FOUNDATION_TRANSFORMATION_TYPECONVERTER_H
