//
// Created by LE, Duc Anh on 6/10/15.
//

#ifndef CLOUD_E_CPLUS_FOUNDATION_DATA_TYPE_POINT_H
#define CLOUD_E_CPLUS_FOUNDATION_DATA_TYPE_POINT_H

#include <Foundation/Data/Value.h>

namespace Cloude {
    namespace Foundation {
        namespace Data {
            namespace Type {

                class Point : public Value {

                public:
                    Point() = default;
                    Point(const Point &) = default;
                    Point(Point &&) = default;
                    Point &operator=(const Point &) = default;
                    Point &operator=(Point &&) = default;
                    ~Point() = default;
                };
            }
        }
    }
}

#endif //CLOUD_E_CPLUS_FOUNDATION_DATA_TYPE_POINT_H
