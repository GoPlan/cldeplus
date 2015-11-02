//
// Created by LE, Duc Anh on 7/8/15.
//

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
