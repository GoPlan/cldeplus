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
            class JoinPhrase {
                const SPtrEntityProxySet &_setProxies;
                SPtrColumnVector _vectorComparingColumns;
                SPtrColumnVector _vectorDisplayColumns;

            public:
                JoinPhrase(const SPtrEntityProxySet &setProxies) : _setProxies{setProxies} { };
                JoinPhrase(const JoinPhrase &) = default;
                JoinPhrase(JoinPhrase &&) = default;
                JoinPhrase &operator=(const JoinPhrase &) = default;
                JoinPhrase &operator=(JoinPhrase &&) = default;
                virtual ~JoinPhrase() = default;

                // Locals - Accessors
                const SPtrEntityProxySet &getSetProxies() const { return _setProxies; }
                const SPtrColumnVector &getVectorComparingColumns() const { return _vectorComparingColumns; }
                const SPtrColumnVector &getVectorDisplayColumns() const { return _vectorDisplayColumns; }

                // Locals - Mutators
                void AddComparingColumn(const SPtrColumn &column);
                void AddDisplayColumn(const SPtrColumn &column);
            };
        }
    }
}


#endif //CLOUD_E_PLUS_FOUNDATION_SEGMENTATION_JOINPHRASE_H
