//
// Created by LE, Duc Anh on 6/11/15.
//

#ifndef CLOUD_E_CPLUS_DYNAMODBSOURCEDRIVER_H
#define CLOUD_E_CPLUS_DYNAMODBSOURCEDRIVER_H

namespace Cloude {
    namespace SourceDriver {
        namespace DynamoDb {
            class DynamoDbSourceDriver {
            public:
                DynamoDbSourceDriver() = default;
                virtual ~DynamoDbSourceDriver() = default;
                DynamoDbSourceDriver(const DynamoDbSourceDriver &rhs) = default;
                DynamoDbSourceDriver &operator=(const DynamoDbSourceDriver &rhs) = default;

            };
        }
    }
}


#endif //CLOUD_E_CPLUS_DYNAMODBSOURCEDRIVER_H
