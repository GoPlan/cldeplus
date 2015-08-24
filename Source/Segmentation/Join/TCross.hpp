//
// Created by LE, Duc Anh on 6/24/15.
//

#ifndef CLOUD_E_PLUS_SEGMENTATION_JOIN_CROSS_H
#define CLOUD_E_PLUS_SEGMENTATION_JOIN_CROSS_H

#include <Foundation/EntityProxy.h>
#include <Segmentation/Transformation/EntityTransformer.h>

namespace Cloude {
    namespace Segmentation {
        namespace Join {

            template<class TContainer = Foundation::SPtrEntityProxyVector>
            class TCross {

                Transformation::SPtrEntityTransformer _sptrLhsTransformer;
                Transformation::SPtrEntityTransformer _sptrRhsTransformer;

            public:
                TCross() : _sptrRhsTransformer{new Transformation::EntityTransformer{}},
                           _sptrLhsTransformer{new Transformation::EntityTransformer{}} { };

                TCross(const TCross &) = default;
                TCross(TCross &&) = default;
                TCross &operator=(const TCross &) = default;
                TCross &operator=(TCross &&) = default;
                ~TCross() = default;

                // Accessors
                const Segmentation::Transformation::SPtrEntityTransformer &getLhsCTransformer() const { return _sptrLhsTransformer; }
                const Segmentation::Transformation::SPtrEntityTransformer &getRhsCTransformer() const { return _sptrRhsTransformer; }

                // Mutators
                Segmentation::Transformation::SPtrEntityTransformer &LhsTransformer() { return _sptrLhsTransformer; }
                Segmentation::Transformation::SPtrEntityTransformer &RhsTransformer() { return _sptrRhsTransformer; }

                // Locals
                TContainer Join(const TContainer &lhsContainer, const TContainer &rhsContainer) const {

                    TContainer proxiesContainer;

                    auto lhsCurrent = lhsContainer.begin();
                    auto rhsCurrent = rhsContainer.begin();

                    auto lhsEnd = lhsContainer.end();
                    auto rhsEnd = rhsContainer.end();

                    while (lhsCurrent != lhsEnd) {

                        while (rhsCurrent != rhsEnd) {

                            Foundation::SPtrEntityProxy proxy = std::make_shared<Foundation::EntityProxy>();
                            _sptrLhsTransformer->Transform(*lhsCurrent, proxy);
                            _sptrRhsTransformer->Transform(*rhsCurrent, proxy);

                            proxiesContainer.insert(proxiesContainer.cend(), proxy);
                            ++rhsCurrent;
                        }

                        rhsCurrent = rhsContainer.begin();
                        ++lhsCurrent;
                    }

                    return proxiesContainer;
                }
            };

            using Cross = TCross<>;
        }
    }
}


#endif //CLOUD_E_PLUS_SEGMENTATION_JOIN_CROSS_H
