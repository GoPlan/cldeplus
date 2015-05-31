//
// Created by LE, Duc Anh on 5/31/15.
//

#ifndef CLOUD_E_CPLUS_ENTITYSOURCEDRIVER_H
#define CLOUD_E_CPLUS_ENTITYSOURCEDRIVER_H


class EntitySourceDriver {
public:
    EntitySourceDriver() = default;
    virtual ~EntitySourceDriver() = default;
    EntitySourceDriver(const EntitySourceDriver &srcEntitySourceDriver) = default;
    EntitySourceDriver &operator=(const EntitySourceDriver &srcEntitySourceDriver) = default;

};


#endif //CLOUD_E_CPLUS_ENTITYSOURCEDRIVER_H
