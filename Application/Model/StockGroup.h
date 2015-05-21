//
// Created by GoPlan on 15/05/2015.
//

#ifndef CLOUD_E_CPLUS_STOCKGROUP_H
#define CLOUD_E_CPLUS_STOCKGROUP_H

#include "../../Architecture/Foundation/Entity.h"

using namespace Cloude;

namespace Cloude {
    namespace Application {
        namespace Model {

            class StockGroup : public Architecture::Foundation::Entity {

            public:
                StockGroup(Architecture::Foundation::Identity &ident) : Entity(ident) {
                    _id = 0;
                    _code.clear();
                    _name.clear();
                    _defaultStockCode.clear();
                };

                virtual ~StockGroup() { };

                long id() const {
                    return _id;
                }

                void setId(long id) {
                    _id = id;
                }

                const std::string &code() const {
                    return _code;
                }

                void setCode(const std::string &code) {
                    _code = code;
                }

                const std::string &name() const {
                    return _name;
                }

                void setName(const std::string &name) {
                    _name = name;
                }

                const std::string &defaultStockCode() const {
                    return _defaultStockCode;
                }

                void setDefaultStockCode(const std::string &defaultStockCode) {
                    _defaultStockCode = defaultStockCode;
                }

            private:
                long _id;
                std::string _code;
                std::string _name;
                std::string _defaultStockCode;
            };
        }
    }
}


#endif //CLOUD_E_CPLUS_STOCKGROUP_H
