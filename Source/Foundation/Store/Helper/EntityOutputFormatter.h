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

#ifndef CLDEPLUS_FOUNDATION_STORE_HELPER_ENTITYOUTPUTFORMATTER_H
#define CLDEPLUS_FOUNDATION_STORE_HELPER_ENTITYOUTPUTFORMATTER_H

#include "../../Common/IFormatter.h"
#include "../../Column.h"

namespace CLDEPlus {
    namespace Foundation {
        namespace Store {
            namespace Helper {

                class EntityOutputFormatter : public Foundation::Common::IFormatter,
                                              public Foundation::Common::IPrintable {

                    SPtrColumnVector _displayColumns{};
                    string _delimiter{"|"};

                public:
                    EntityOutputFormatter() = default;
                    EntityOutputFormatter(EntityOutputFormatter const &) = default;
                    EntityOutputFormatter(EntityOutputFormatter &&) = default;
                    EntityOutputFormatter &operator=(EntityOutputFormatter const &) = default;
                    EntityOutputFormatter &operator=(EntityOutputFormatter &&) = default;
                    virtual ~EntityOutputFormatter() = default;

                    // Mutators
                    SPtrColumnVector &DisplayColumns() { return _displayColumns; }

                    // Accessors
                    void setDelimiter(string const &delimiter) { _delimiter = delimiter; }

                    // IFormatter
                    virtual string Format(Common::IPrintable const &printable) const override;

                    // IPrintable
                    virtual string ToString() const override;
                };
            }
        }
    }
}


#endif //CLDEPLUS_FOUNDATION_STORE_HELPER_ENTITYOUTPUTFORMATTER_H
