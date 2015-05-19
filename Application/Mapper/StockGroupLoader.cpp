//
// Created by GoPlan on 15/05/2015.
//

#include "StockGroupLoader.h"

Entity *Cloude::Application::Mapper::StockGroupLoader::CreateEntityInstance(Identity &ident) {

    auto fldCodePtr = ident.GetFieldPtr("Code");

    StockGroup *entity = new StockGroup(ident);
    entity->setCode(fldCodePtr->string());

    return (Entity *) entity;
}
Identity *Cloude::Application::Mapper::StockGroupLoader::NextPrimaryKey() {
    return nullptr;
}
void Cloude::Application::Mapper::StockGroupLoader::EstablishEntityRelationship(Entity &entity) {
    return;
}
void Cloude::Application::Mapper::StockGroupLoader::LoadEntity(Entity &entity) {
    return;
}
int Cloude::Application::Mapper::StockGroupLoader::InsertEntity(Entity &entity) {
    return 1;
}
int Cloude::Application::Mapper::StockGroupLoader::SaveEntity(Entity &entity) {
    return 1;
}
int Cloude::Application::Mapper::StockGroupLoader::DeleteEntity(Entity &entity) {
    return 1;
}

void Application::Mapper::StockGroupLoader::LoadEntityPrimaryKeyFields() {

}
