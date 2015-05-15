//
// Created by GoPlan on 15/05/2015.
//

#ifndef CLOUD_E_CPLUS_STOCKGROUP_H
#define CLOUD_E_CPLUS_STOCKGROUP_H

#include "../../Architecture/Foundation/Entity.h"
#include "../../Architecture/Foundation/EntityStore.h"

using namespace Cloude::Architecture::Foundation;

namespace Cloude {
    namespace Application {

        class StockGroup : Entity {

        public:
            StockGroup(Identity &ident) : Entity(ident) {
                id = 0;
                code.clear();
                name.clear();
                defaultStockCode.clear();
            };

            virtual ~StockGroup() { };

            long getId() const {
                return id;
            }
            void setId(long id) {
                StockGroup::id = id;
            }
            const string &getCode() const {
                return code;
            }
            void setCode(const string &code) {
                StockGroup::code = code;
            }
            const string &getName() const {
                return name;
            }
            void setName(const string &name) {
                StockGroup::name = name;
            }
            const string &getDefaultStockCode() const {
                return defaultStockCode;
            }
            void setDefaultStockCode(const string &defaultStockCode) {
                StockGroup::defaultStockCode = defaultStockCode;
            }

        private:
            long id;
            string code;
            string name;
            string defaultStockCode;
        };
    }
}


#endif //CLOUD_E_CPLUS_STOCKGROUP_H
