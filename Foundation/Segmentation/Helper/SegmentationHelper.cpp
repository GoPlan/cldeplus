//
// Created by LE, Duc Anh on 6/22/15.
//

#include "SegmentationHelper.h"


Cloude::Foundation::SPtrEntityProxySet Cloude::Foundation::Segmentation::Helper::SegmentationHelper::InnerJoin(
        const SPtrEntityProxySet &lhs, const SPtrEntityProxySet &rhs, const SPtrColumnVector &columnsForKey) {
    SPtrEntityProxySet proxies;
    return proxies;
}

Cloude::Foundation::SPtrEntityProxySet Cloude::Foundation::Segmentation::Helper::SegmentationHelper::CrossJoin(
        const SPtrEntityProxySet &lhs, const SPtrEntityProxySet &rhs, const SPtrColumnVector &columnsForKey) {
    SPtrEntityProxySet proxies;
    return proxies;
}

Cloude::Foundation::SPtrEntityProxySet Cloude::Foundation::Segmentation::Helper::SegmentationHelper::LeftOuterJoin(
        const SPtrEntityProxySet &lhs, const SPtrEntityProxySet &rhs, const SPtrColumnVector &columnsForKey) {
    SPtrEntityProxySet proxies;
    return proxies;
}

Cloude::Foundation::SPtrEntityProxySet Cloude::Foundation::Segmentation::Helper::SegmentationHelper::RightOuterJoin(
        const SPtrEntityProxySet &lhs, const SPtrEntityProxySet &rhs, const SPtrColumnVector &columnsForKey) {
    return LeftOuterJoin(rhs, lhs, columnsForKey);
}
