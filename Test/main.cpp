//
// Created by LE, Duc-Anh on 5/21/15.
//

#include "Type/CreateValue.hpp"
#include "Type/ValueComparison.hpp"
#include "Segmentation/Segmentation.hpp"
#include "Segmentation/Transformation.hpp"
#include "Relation/Relation.hpp"
#include "Store/SQLiteStore.hpp"
//#include "Store/MySqlStore00.hpp"
//#include "Store/MySqlStore01.hpp"
//#include "Store/MySqlStore02.hpp"

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();;
};