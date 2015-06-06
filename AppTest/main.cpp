//
// Created by LE, Duc-Anh on 5/21/15.
//

#include "Store/Test/MySqlStore.hpp"
#include "Store/Test/PostgreStore.hpp"
#include "Store/Test/MongoDbStore.hpp"

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
};