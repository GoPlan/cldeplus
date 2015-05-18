//
// Created by GoPlan on 15/05/2015.
//

#include "StockGroupLoader.h"

Entity *Cloude::Application::StockGroupLoader::CreateEntityInstance(Identity &ident) {

    auto fldCodePtr = ident.GetFieldPtr("Code");

    StockGroup *entity = new StockGroup(ident);
    entity->setCode(fldCodePtr->string());

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
int Cloude::Application::StockGroupLoader::InsertEntity(Entity &entity) {
    return 1;
}
int Cloude::Application::StockGroupLoader::SaveEntity(Entity &entity) {
    return 1;
}
int Cloude::Application::StockGroupLoader::DeleteEntity(Entity &entity) {
    return 1;
}
