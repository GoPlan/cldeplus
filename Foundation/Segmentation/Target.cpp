//
// Created by LE, Duc Anh on 6/18/15.
//

#include "Target.h"

namespace Cloude {
    namespace Foundation {

        const SPtrEntityProxyVector &Segmentation::Target::ResultSet() const {
            return _resultStorage;
        }

        void Segmentation::Target::Evaluate() {

            SPtrColumnVector columns;
            columns.reserve(_displayColumns.size());

            std::for_each(_displayColumns.cbegin(), _displayColumns.cend(),
                          [&columns](const SPtrDisplayColumnPair &displayColumnPair) {
                              columns.push_back(displayColumnPair.second);
                          });

            _resultStorage = _entityQuery->Compose(columns, _criteria);
        }

        void Segmentation::Target::AddDisplayColumn(const std::pair<std::string, Foundation::SPtrColumn> &column) {
            _displayColumns.push_back(column);
        }

        void Segmentation::Target::ClearDisplayColumns() {
            _displayColumns.clear();
        }
    }
}


