//
// Created by LE, Duc Anh on 6/1/15.
//

#ifndef CLOUD_E_CPLUS_POSTGRESOURCEDRIVEREXCEPTION_H
#define CLOUD_E_CPLUS_POSTGRESOURCEDRIVEREXCEPTION_H


class PostgreSourceDriverException {
public:
    PostgreSourceDriverException() = default;
    virtual ~PostgreSourceDriverException() = default;
    PostgreSourceDriverException(const PostgreSourceDriverException &srcPostgreSourceDriverException) = default;
    PostgreSourceDriverException
            &operator=(const PostgreSourceDriverException &srcPostgreSourceDriverException) = default;

};


#endif //CLOUD_E_CPLUS_POSTGRESOURCEDRIVEREXCEPTION_H
