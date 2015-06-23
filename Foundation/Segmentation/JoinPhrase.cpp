//
// Created by LE, Duc Anh on 6/23/15.
//

#include "JoinPhrase.h"

namespace Cloude {
    namespace Foundation {

        void Segmentation::JoinPhrase::AddComparingColumn(const SPtrColumn &column) {
            _vectorComparingColumns.push_back(column);
        }
        void Segmentation::JoinPhrase::AddDisplayColumn(const SPtrColumn &column) {
            _vectorDisplayColumns.push_back(column);
        }
    }
}


