//
// Created by LE, Duc Anh on 7/10/15.
//

#include "Comparative.h"

namespace Cloude {
    namespace Foundation {
        namespace Query {

            SPtrCriteria CreateAND(const SPtrCriteria &lhs, const SPtrCriteria &rhs) {
                return std::make_shared<Comparative::And>(lhs, rhs);
            }

            SPtrCriteria CreateOR(const SPtrCriteria &lhs, const SPtrCriteria &rhs) {
                return std::make_shared<Comparative::Or>(lhs, rhs);
            }

            SPtrCriteria CreateEQ(const SPtrColumn &column, const Data::SPtrValue &value) {
                return std::make_shared<Comparative::Equal>(column, value);
            }

            SPtrCriteria CreateNEQ(const SPtrColumn &column, const Data::SPtrValue &value) {
                return std::make_shared<Comparative::NotEqual>(column, value);
            }

            SPtrCriteria CreateGT(const SPtrColumn &column, const Data::SPtrValue &value) {
                return std::make_shared<Comparative::Greater>(column, value);
            }

            SPtrCriteria CreateGTE(const SPtrColumn &column, const Data::SPtrValue &value) {
                return std::make_shared<Comparative::GreaterOrEqual>(column, value);
            }

            SPtrCriteria CreateLT(const SPtrColumn &column, const Data::SPtrValue &value) {
                return std::make_shared<Comparative::Lesser>(column, value);
            }

            SPtrCriteria CreateLTE(const SPtrColumn &column, const Data::SPtrValue &value) {
                return std::make_shared<Comparative::LesserOrEqual>(column, value);
            }

            SPtrCriteria CreateLike(const SPtrColumn &column, const Data::SPtrValue &value) {
                return std::make_shared<Comparative::Like>(column, value);
            }

            SPtrCriteria CreateNotLike(const SPtrColumn &column, const Data::SPtrValue &value) {
                return std::make_shared<Comparative::NotLike>(column, value);
            }

            SPtrCriteria CreateIsNull(const SPtrColumn &column) {
                return std::make_shared<Comparative::IsNull>(column);
            }

            SPtrCriteria CreateIsNotNull(const SPtrColumn &column) {
                return std::make_shared<Comparative::IsNotNull>(column);
            }
        }
    }
}