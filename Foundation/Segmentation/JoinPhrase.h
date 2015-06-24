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
                ColumnNamePairVector _vectorDisplayColumns;
                ColumnNamePairVector _vectorComparingColumns;

            public:
                explicit JoinPhrase(const SPtrEntityProxySet &setProxies) : _setProxies{setProxies} { };
                JoinPhrase(const JoinPhrase &) = default;
                JoinPhrase(JoinPhrase &&) = default;
                JoinPhrase &operator=(const JoinPhrase &) = default;
                JoinPhrase &operator=(JoinPhrase &&) = default;
                ~JoinPhrase() = default;

                // Locals - Accessors
                const SPtrEntityProxySet &getSetProxies() const { return _setProxies; }
                const ColumnNamePairVector &getVectorComparingColumns() const { return _vectorComparingColumns; }
                const ColumnNamePairVector &getVectorDisplayColumns() const { return _vectorDisplayColumns; }

                // Locals - Mutators
                void AddDisplayColumnPair(const ColumnNamePair &pairName);
                void AddComparingColumnPair(const ColumnNamePair &pairName);
            };
        }
    }
}


#endif //CLOUD_E_PLUS_FOUNDATION_SEGMENTATION_JOINPHRASE_H
