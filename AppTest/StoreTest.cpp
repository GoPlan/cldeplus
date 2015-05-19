//
// Created by LE, Duc-Anh on 5/19/15.
//

#include <iostream>
#include "StoreTest.h"
#include "../Application/Model/StockGroup.h"
#include "../Application/Mapper/StockGroupLoader.h"
#include "../Application/Mapper/StockGroupMap.h"

using namespace std;
using namespace Cloude::Application::Model;
using namespace Cloude::Application::Mapper;

int StoreTest() {
    {
        StockGroupMap stockGroupMap;
        StockGroupLoader stockGroupGenerator;
        EntityStore <StockGroup> stockGroupStore((EntityMap &) stockGroupMap,
                                                 (EntityLoader &) stockGroupGenerator);

        EntityStore <StockGroup> &store = (EntityStore <StockGroup> &) stockGroupStore;

        string code("VNM");

        Field fldId(stockGroupMap.Code);
        fldId.setString(code);

        Identity ident{&fldId};

        auto stockGroupPtr = store.Create(ident);
        auto fieldPtr = stockGroupPtr->identity().GetFieldPtr("Code");
        auto fieldsMap = ident.FieldsMap();

        cout << &ident << endl;
        cout << &(stockGroupPtr->identity()) << endl;
        cout << fieldPtr << endl;
        cout << fieldsMap["Code"] << endl;
        cout << &fldId << endl;
        cout << fieldPtr->string() << endl;
        cout << stockGroupPtr->code() << endl;

        return 0;
    }

}
