//
// Created by LE, Duc Anh on 6/1/15.
//

#ifndef CLOUD_E_CPLUS_POSTGRESOURCEEXCEPTION_H
#define CLOUD_E_CPLUS_POSTGRESOURCEEXCEPTION_H

namespace Cloude {
    namespace SourceDriver {
        namespace PostgreSql {
            class PostgreSourceException {
            public:
                PostgreSourceException() = default;
                virtual ~PostgreSourceException() = default;
                PostgreSourceException(const PostgreSourceException &srcPostgreSourceDriverException) =
                default;
                PostgreSourceException
                        &operator=(const PostgreSourceException &srcPostgreSourceDriverException) = default;

            };
        }
    }
}

#endif //CLOUD_E_CPLUS_POSTGRESOURCEEXCEPTION_H
