//
// Created by LE, Duc-Anh on 5/21/15.
//


#include "Store/SQLiteStore.hpp"
#include "Query/Criteria.hpp"
#include "Type/CreateValue.hpp"
#include "Type/ValueComparison.hpp"
#include "Segmentation/Segmentation.hpp"
#include "Relation/NamedEntity.hpp"

//#include "Segmentation/Transformation.hpp"
//#include "Store/Test/MongoDbStore.hpp"
//#include "Store/Test/MySqlStore.hpp"
//#include "Store/Test/PostgreStore.hpp"

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
};