//
// Created by GoPlan on 15/05/2015.
//

#include "StockGroupLoader.h"

using namespace std;
using namespace Cloude::Architecture;

unique_ptr<Entity> Cloude::Application::Mapper::StockGroupLoader::CreateEntityInstance(shared_ptr<Identity> ident) {
    unique_ptr<Entity> entity;
    return entity;
}

unique_ptr<Identity> Cloude::Application::Mapper::StockGroupLoader::NextPrimaryKey() {
    unique_ptr<Identity> ident;
    return ident;
}

void Cloude::Application::Mapper::StockGroupLoader::LoadEntity(Entity &entity) {
    return;
}

Cloude::Application::Mapper::StockGroupLoader::~StockGroupLoader() {

}
