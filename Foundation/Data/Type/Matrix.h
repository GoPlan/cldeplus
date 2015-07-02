//
// Created by LE, Duc Anh on 6/10/15.
//

#ifndef CLOUD_E_CPLUS_FOUNDATION_DATA_TYPE_MATRIX_H
#define CLOUD_E_CPLUS_FOUNDATION_DATA_TYPE_MATRIX_H

#include <Foundation/Data/Value.h>

namespace Cloude {
    namespace Foundation {
        namespace Data {
            namespace Type {

                class Matrix : public Value {

                public:
                    Matrix() = default;
                    Matrix(const Matrix &) = default;
                    Matrix(Matrix &&) = default;
                    Matrix &operator=(const Matrix &) = default;
                    Matrix &operator=(Matrix &&) = default;
                    ~Matrix() = default;
                };
            }
        }
    }
}

#endif //CLOUD_E_CPLUS_FOUNDATION_DATA_TYPE_MATRIX_H
