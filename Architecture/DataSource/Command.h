//
// Created by LE, Duc Anh on 5/31/15.
//

#ifndef CLOUD_E_CPLUS_COMMAND_H
#define CLOUD_E_CPLUS_COMMAND_H

namespace Cloude {
    namespace Architecture {
        namespace DataSource {
            class Command {
            public:
                Command() = default;
                virtual ~Command() = default;
                Command(const Command &srcCommand) = default;
                Command &operator=(const Command &srcCommand) = default;

            };
        }
    }
}


#endif //CLOUD_E_CPLUS_COMMAND_H
