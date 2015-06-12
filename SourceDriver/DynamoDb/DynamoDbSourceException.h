//
// Created by LE, Duc Anh on 6/11/15.
//

#ifndef CLOUD_E_CPLUS_SOURCEDRIVER_DYNAMODB_DYNAMODBSOURCEEXCEPTION_H
#define CLOUD_E_CPLUS_SOURCEDRIVER_DYNAMODB_DYNAMODBSOURCEEXCEPTION_H

namespace Cloude {
    namespace SourceDriver {
        namespace DynamoDb {

            class DynamoDbSourceException {
            
            public:
                DynamoDbSourceException() = default;
                virtual ~DynamoDbSourceException() = default;
                DynamoDbSourceException(const DynamoDbSourceException &rhs) = default;
                DynamoDbSourceException &operator=(const DynamoDbSourceException &rhs) = default;

            };
        }
    }
}



#endif //CLOUD_E_CPLUS_SOURCEDRIVER_DYNAMODB_DYNAMODBSOURCEEXCEPTION_H
