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

    Field fldId(stockGroupMap.Code, (void *) "VNM");
    Identity ident{&fldId};

    auto stockGroupPtr = store.Create(ident);
    auto entityRef = dynamic_cast<const Entity &>((Entity &) *stockGroupPtr);
    auto fieldRef = entityRef.identity().GetField("Code");

    cout << (char *) fieldRef.value() << endl;
    cout << (char *) stockGroupPtr->code().c_str() << endl;

    return 0;
};