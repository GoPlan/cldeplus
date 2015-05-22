//
// Created by GoPlan on 15/05/2015.
//

#include "StockGroupLoader.h"

Entity *Cloude::Application::Mapper::StockGroupLoader::CreateEntityInstance(Identity &ident) {

    auto stockGroupPtr = new StockGroup(ident);
    auto entityPtr = static_cast<Entity*>(stockGroupPtr);

    LoadEntityPrimaryKeyFields(*entityPtr);

    return entityPtr;
}
Identity *Cloude::Application::Mapper::StockGroupLoader::NextPrimaryKey() {
    return nullptr;
}
void Cloude::Application::Mapper::StockGroupLoader::EstablishEntityRelationship(Entity &entity) {

    auto stockGroup = static_cast<StockGroup&>(entity);
    auto identity = entity.getIdentity();
    auto fldCodePtr = identity.GetFieldPtr("Code");

    stockGroup.setCode(fldCodePtr->getString());
}
void Cloude::Application::Mapper::StockGroupLoader::LoadEntity(Entity &entity) {
    return;
}
void Application::Mapper::StockGroupLoader::LoadEntityPrimaryKeyFields(Entity &entity) {
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