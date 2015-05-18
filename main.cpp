#include <iostream>
#include "Application/Mapper/StockGroupMap.h"
#include "Application/Entity/StockGroup.h"
#include "Application/Mapper/StockGroupLoader.h"

using namespace std;
using namespace Cloude::Architecture::Foundation;
using namespace Cloude::Application;

int main() {

    StockGroupMap stockGroupMap;
    StockGroupLoader stockGroupGenerator;
    EntityStore<StockGroup> stockGroupStore((EntityMap &) stockGroupMap,
                                            (EntityLoader &) stockGroupGenerator);

    EntityStore<StockGroup> &store = (EntityStore<StockGroup> &) stockGroupStore;

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
};