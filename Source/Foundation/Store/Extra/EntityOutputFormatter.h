//
// Created by LE, Duc Anh on 7/8/15.
//

#ifndef CLOUD_E_PLUS_FOUNDATION_STORE_EXTRA_ENTITYOUTPUTFORMATTER_H
#define CLOUD_E_PLUS_FOUNDATION_STORE_EXTRA_ENTITYOUTPUTFORMATTER_H

#include <Foundation/Common/IFormatter.h>
#include <Foundation/Column.h>

namespace Cloude {
    namespace Foundation {
        namespace Store {
            namespace Extra {

                class EntityOutputFormatter : public Foundation::Common::IFormatter,
                                              public Foundation::Common::IPrintable {

                    SPtrColumnVector _displayColumns{};
                    std::string _delimiter{"|"};

                public:
                    EntityOutputFormatter() = default;
                    EntityOutputFormatter(const EntityOutputFormatter &) = default;
                    EntityOutputFormatter(EntityOutputFormatter &&) = default;
                    EntityOutputFormatter &operator=(const EntityOutputFormatter &) = default;
                    EntityOutputFormatter &operator=(EntityOutputFormatter &&) = default;
                    virtual ~EntityOutputFormatter() = default;

                    // Mutators
                    SPtrColumnVector &DisplayColumns() { return _displayColumns; }

                    // Accessors
                    void setDelimiter(const std::string &delimiter) { _delimiter = delimiter; }

                    // IFormatter
                    virtual std::string Format(const Common::IPrintable &printable) const override;

                    // IPrintable

                    virtual std::string ToString() const override;
                };
            }
        }
    }
}


#endif //CLOUD_E_PLUS_FOUNDATION_STORE_EXTRA_ENTITYOUTPUTFORMATTER_H
