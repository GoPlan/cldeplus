//
// Created by LE, Duc Anh on 7/10/15.
//

#include "Comparative.h"

namespace CLDEPlus {
    namespace Foundation {
        namespace Query {

            SPtrCriteria ComparativeFactory::CreateAND(const SPtrCriteria &lhs, const SPtrCriteria &rhs) {
                return std::make_shared<Comparative::And>(lhs, rhs);
            }

            SPtrCriteria ComparativeFactory::CreateOR(const SPtrCriteria &lhs, const SPtrCriteria &rhs) {
                return std::make_shared<Comparative::Or>(lhs, rhs);
            }

            SPtrCriteria ComparativeFactory::CreateEQ(const SPtrColumn &column, const Data::SPtrValue &value) {
                return std::make_shared<Comparative::Equal>(column, value);
            }

            SPtrCriteria ComparativeFactory::CreateNEQ(const SPtrColumn &column, const Data::SPtrValue &value) {
                return std::make_shared<Comparative::NotEqual>(column, value);
            }

            SPtrCriteria ComparativeFactory::CreateGT(const SPtrColumn &column, const Data::SPtrValue &value) {
                return std::make_shared<Comparative::Greater>(column, value);
            }

            SPtrCriteria ComparativeFactory::CreateGTE(const SPtrColumn &column, const Data::SPtrValue &value) {
                return std::make_shared<Comparative::GreaterOrEqual>(column, value);
            }

            SPtrCriteria ComparativeFactory::CreateLT(const SPtrColumn &column, const Data::SPtrValue &value) {
                return std::make_shared<Comparative::Lesser>(column, value);
            }

            SPtrCriteria ComparativeFactory::CreateLTE(const SPtrColumn &column, const Data::SPtrValue &value) {
                return std::make_shared<Comparative::LesserOrEqual>(column, value);
            }

            SPtrCriteria ComparativeFactory::CreateLike(const SPtrColumn &column, const Data::SPtrValue &value) {
                return std::make_shared<Comparative::Like>(column, value);
            }

            SPtrCriteria ComparativeFactory::CreateNotLike(const SPtrColumn &column, const Data::SPtrValue &value) {
                return std::make_shared<Comparative::NotLike>(column, value);
            }

            SPtrCriteria ComparativeFactory::CreateIsNull(const SPtrColumn &column) {
                return std::make_shared<Comparative::IsNull>(column);
            }

            SPtrCriteria ComparativeFactory::CreateIsNotNull(const SPtrColumn &column) {
                return std::make_shared<Comparative::IsNotNull>(column);
            }
        }
    }
}