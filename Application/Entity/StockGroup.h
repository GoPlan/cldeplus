//
// Created by GoPlan on 15/05/2015.
//

#ifndef CLOUD_E_CPLUS_STOCKGROUP_H
#define CLOUD_E_CPLUS_STOCKGROUP_H

#include "../../Architecture/Foundation/Entity.h"

using namespace Cloude::Architecture::Foundation;

namespace Cloude {
    namespace Application {

        class StockGroup : public Entity {

        public:
            StockGroup(Identity &ident) : Entity(ident) {
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
            const string &code() const {
                return _code;
            }
            void setCode(const string &code) {
                _code = code;
            }
            const string &name() const {
                return _name;
            }
            void setName(const string &name) {
                _name = name;
            }
            const string &defaultStockCode() const {
                return _defaultStockCode;
            }
            void setDefaultStockCode(const string &defaultStockCode) {
                _defaultStockCode = defaultStockCode;
            }
        private:
            long _id;
            string _code;
            string _name;
            string _defaultStockCode;
        };
    }
}


#endif //CLOUD_E_CPLUS_STOCKGROUP_H
