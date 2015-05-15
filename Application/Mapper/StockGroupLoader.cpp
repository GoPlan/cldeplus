//
// Created by GoPlan on 15/05/2015.
//

#include "StockGroupLoader.h"
#include "../Entity/StockGroup.h"

Entity *Cloude::Application::StockGroupLoader::CreateEntityInstance(Identity &ident) {

    auto field_ref = ident.GetField("Code");
    auto value_ptr = (const char*)field_ref.getValue();

    string value_str(value_ptr);

    StockGroup *entity = new StockGroup(ident);
    entity->setCode(value_str);

    return (Entity *) entity;
}
Identity *Cloude::Application::StockGroupLoader::NextPrimaryKey() {
    return nullptr;
}
void Cloude::Application::StockGroupLoader::EstablishEntityRelationship(Entity &entity) {
    return;
}
void Cloude::Application::StockGroupLoader::LoadEntity(Entity &entity) {
    return;
}
