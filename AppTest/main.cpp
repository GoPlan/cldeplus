//
// Created by LE, Duc-Anh on 5/21/15.
//


#include "Type/CreateValue.hpp"
#include "Type/ValueComparison.hpp"
#include "Store/SQLiteStore.hpp"
#include "Store/MySqlStore00.hpp"
#include "Store/MySqlStore01.hpp"
#include "Segmentation/Segmentation.hpp"
#include "Segmentation/Transformation.hpp"
#include "Relation/Relation.hpp"

//#include "Store/Test/MongoDbStore.hpp"
//#include "Store/Test/PostgreStore.hpp"

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
};