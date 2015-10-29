//
// Created by LE, Duc Anh on 7/8/15.
//

#include "EntityOutputFormatter.h"
#include "../AbstractEntity.h"

namespace CLDEPlus {
    namespace Foundation {
        namespace Store {
            namespace Extra {

                std::string EntityOutputFormatter::Format(
                        const CLDEPlus::Foundation::Common::IPrintable &printable) const {

                    auto &entity = dynamic_cast<const Store::AbstractEntity &>(printable);

                    std::string result;

                    for (auto &sptrColumn : _displayColumns) {

                        if(!result.empty()){
                            result += _delimiter;
                        }

                        if(entity.hasCell(sptrColumn->getName())){
                            auto &sptrCell = entity.getCell(sptrColumn->getName());
                            result += sptrCell->ToString();
                        }else{
                            result += "(empty)";
                        }
                    }

                    return result;
                }

                std::string EntityOutputFormatter::ToString() const {

                    std::string result;

                    for (auto &sptrColumn : _displayColumns) {

                        if(!result.empty()){
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

