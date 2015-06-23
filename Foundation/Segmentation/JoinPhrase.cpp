//
// Created by LE, Duc Anh on 6/23/15.
//

#include "JoinPhrase.h"

namespace Cloude {
    namespace Foundation {

        void Segmentation::JoinPhrase::AddComparingColumnPair(const ColumnNamePair &pairName) {
            _vectorComparingColumns.push_back(pairName);
        }
        void Segmentation::JoinPhrase::AddDisplayColumnPair(const ColumnNamePair &pairName) {
            _vectorDisplayColumns.push_back(pairName);
        }
    }
}


