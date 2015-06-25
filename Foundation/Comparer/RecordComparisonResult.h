//
// Created by LE, Duc Anh on 6/25/15.
//

#ifndef CLOUD_E_PLUS_RECORDCOMPARISONRESULT_H
#define CLOUD_E_PLUS_RECORDCOMPARISONRESULT_H

namespace Cloude {
    namespace Foundation {
        namespace Comparer {

            using RecCmpRes = struct RecordComparisonResult {

                int result = 0;
                int column = 0;
                int gap = 0;

                bool isEqual() { return result == 0; }
                bool isPositive() { return result > 0; }
                bool isNegative() { return result < 0; }
            };
        }
    }
}

#endif //CLOUD_E_PLUS_RECORDCOMPARISONRESULT_H
