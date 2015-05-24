//
// Created by LE, Duc-Anh on 5/24/15.
//

#include <iostream>
#include "Examples/mysql_c_example.h"

int main(int argc, char **argv) {

    string msg = "MySql C Driver Example";

    cout << msg << endl;

    Cloude::Examples::MySqlExample mySqlExample;
    mySqlExample.Run();

    return EXIT_SUCCESS;
};