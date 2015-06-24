//
// Created by LE, Duc Anh on 6/23/15.
//

#ifndef CLOUD_E_PLUS_FOUNDATION_SEGMENTATION_JOINPHRASE_H
#define CLOUD_E_PLUS_FOUNDATION_SEGMENTATION_JOINPHRASE_H

#include <Foundation/Column.h>
#include <Foundation/EntityProxy.h>

namespace Cloude {
    namespace Foundation {
        namespace Segmentation {

            using ColumnNamePair = std::pair<std::string, std::string>;
            using ColumnNamePairVector = std::vector<ColumnNamePair>;

            class JoinPhrase {

                const SPtrEntityProxySet &_setProxies;
                ColumnNamePairVector _vectorDisplayColumnPairs;
                SPtrColumnVector _vectorComparingColumns;

            public:
                explicit JoinPhrase(const SPtrEntityProxySet &setProxies, const SPtrColumnVector &comparingColumns);
                JoinPhrase(const JoinPhrase &) = default;
                JoinPhrase(JoinPhrase &&) = default;
                JoinPhrase &operator=(const JoinPhrase &) = default;
                JoinPhrase &operator=(JoinPhrase &&) = default;
                ~JoinPhrase() = default;

                // Locals - Accessors
                const SPtrEntityProxySet &getSetProxies() const { return _setProxies; }
                const SPtrColumnVector &getVectorComparingColumns() const { return _vectorComparingColumns; }
                const ColumnNamePairVector &getVectorDisplayColumnPairs() const { return _vectorDisplayColumnPairs; }

                // Locals - Mutators
                void AddDisplayColumnPair(const ColumnNamePair &pairName);
            };
        }
    }
}


#endif //CLOUD_E_PLUS_FOUNDATION_SEGMENTATION_JOINPHRASE_H
