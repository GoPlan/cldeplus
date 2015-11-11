/*

Copyright 2015 LE, Duc-Anh

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.

*/

#include "EntityOutputFormatter.h"
#include "../AbstractEntity.h"

namespace CLDEPlus {
    namespace Foundation {
        namespace Store {
            namespace Helper {

                string EntityOutputFormatter::Format(CLDEPlus::Foundation::Common::IPrintable const &printable) const {

                    auto &entity = dynamic_cast<const Store::AbstractEntity &>(printable);

                    string result;

                    for (auto &sptrColumn : _displayColumns) {

                        if (!result.empty()) {
                            result += _delimiter;
                        }

                        if (entity.hasCell(sptrColumn->getName())) {
                            auto &sptrCell = entity.getCell(sptrColumn->getName());
                            result += sptrCell->ToString();
                        }
                        else {
                            result += "(empty)";
                        }
                    }

                    return result;
                }

                string EntityOutputFormatter::ToString() const {

                    string result;

                    for (auto &sptrColumn : _displayColumns) {

                        if (!result.empty()) {
                            result += _delimiter;
                        }

                        result += sptrColumn->getName();
                    }

                    return result;
                }
            }
        }
    }
}

