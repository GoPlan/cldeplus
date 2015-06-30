//
// Created by LE, Duc Anh on 6/23/15.
//

#ifndef CLOUD_E_PLUS_FOUNDATION_SEGMENTATION_JOINPHRASE_H
#define CLOUD_E_PLUS_FOUNDATION_SEGMENTATION_JOINPHRASE_H

#include <Foundation/Column.h>
#include <Foundation/EntityProxy.h>
#include <Foundation/Transformation/CellTransformer.h>

namespace Cloude {
    namespace Foundation {
        namespace Segmentation {

            using DisplaySPtrCellTransformMap = std::unordered_map<std::string, Transformation::SPtrCellTransformer>;

            class JoinPhrase {

                SPtrColumnVector _vectorComparingColumns;
                DisplaySPtrCellTransformMap _mapDisplayCellTransformMap;

            public:
                JoinPhrase() = default;
                JoinPhrase(const JoinPhrase &) = default;
                JoinPhrase(JoinPhrase &&) = default;
                JoinPhrase &operator=(const JoinPhrase &) = default;
                JoinPhrase &operator=(JoinPhrase &&) = default;
                ~JoinPhrase() = default;

                // Locals - Accessors
                SPtrColumnVector &ComparingColumns() { return _vectorComparingColumns; }
                DisplaySPtrCellTransformMap &DisplayColumnsMap() { return _mapDisplayCellTransformMap; }

                const SPtrColumnVector &CComparingColumns() const { return _vectorComparingColumns; }
                const DisplaySPtrCellTransformMap &CDisplayColumnsMap() const { return _mapDisplayCellTransformMap; }
            };
        }
    }
}


#endif //CLOUD_E_PLUS_FOUNDATION_SEGMENTATION_JOINPHRASE_H
