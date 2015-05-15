#include <iostream>
#include "Application/Mapper/StockGroupMap.h"
#include "Application/Entity/StockGroup.h"
#include "Application/Mapper/StockGroupLoader.h"
#include "Infrastructure/MongoDbEntityStore.h"

using namespace std;
using namespace Cloude::Architecture::Foundation;
using namespace Cloude::Infrastructure;
using namespace Cloude::Application;

int main() {

    StockGroupMap stockGroupMap;
    StockGroupLoader stockGroupGenerator;
    MongoDbEntityStore<StockGroup> stockGroupStore((EntityMap &) stockGroupMap,
                                                   (EntityLoader &) stockGroupGenerator);

    EntityStore<StockGroup> &store = (EntityStore<StockGroup> &) stockGroupStore;

    Field fldId(stockGroupMap.Code, (void *) "VNM");
    Identity ident{&fldId};

    auto stock_group_ptr = store.Create(ident);
    auto entity_ref = dynamic_cast<const Entity &>((Entity &) *stock_group_ptr);
    auto field_ref = entity_ref.getIdentity().GetField("Code");

    cout << (char *) field_ref.getValue() << endl;
    cout << (char *) stock_group_ptr->getCode().c_str() << endl;

    return 0;
};