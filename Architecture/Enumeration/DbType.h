//
// Created by GoPlan on 14/05/2015.
//

#ifndef CLOUD_E_CPLUS_DBTYPE_H
#define CLOUD_E_CPLUS_DBTYPE_H

namespace Cloude {
    namespace Architecture {
        namespace Enumeration {

            enum class DbType {
                Boolean,
                Byte,
                Int16,
                Int32,
                Int64,
                UInt16,
                UInt32,
                UInt64,
                Double,
                Float,
                Decimal,
                Numeric,
                String,
                Currency,
                Date,
                Time,
                Timestamp,
                Interval
            };

        }
    }
}

#endif //CLOUD_E_CPLUS_DBTYPE_H
