//
// Created by LE, Duc Anh on 6/23/15.
//

#include "JoinPhrase.h"

namespace Cloude {
    namespace Foundation {


        Segmentation::JoinPhrase::JoinPhrase(const SPtrEntityProxySet &setProxies,
                                             const SPtrColumnVector &comparingColumns)
                : _setProxies{setProxies}, _vectorComparingColumns{comparingColumns} {
            //
        }

        void Segmentation::JoinPhrase::AddDisplayColumnPair(const ColumnNamePair &pairName) {
            _vectorDisplayColumnPairs.push_back(pairName);
        }
    }
}


