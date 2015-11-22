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

#include "Comparative.h"

namespace CLDEPlus {
    namespace Foundation {
        namespace Query {

            SPtrCriteria ComparativeFactory::CreateAND(const SPtrCriteria &lhs, const SPtrCriteria &rhs) {
                return cldeplus_make_shared<Comparative::And>(lhs, rhs);
            }

            SPtrCriteria ComparativeFactory::CreateOR(const SPtrCriteria &lhs, const SPtrCriteria &rhs) {
                return cldeplus_make_shared<Comparative::Or>(lhs, rhs);
            }

            SPtrCriteria ComparativeFactory::CreateEQ(const SPtrColumn &column, const Data::SPtrValue &value) {
                return cldeplus_make_shared<Comparative::Equal>(column, value);
            }

            SPtrCriteria ComparativeFactory::CreateNEQ(const SPtrColumn &column, const Data::SPtrValue &value) {
                return cldeplus_make_shared<Comparative::NotEqual>(column, value);
            }

            SPtrCriteria ComparativeFactory::CreateGT(const SPtrColumn &column, const Data::SPtrValue &value) {
                return cldeplus_make_shared<Comparative::Greater>(column, value);
            }

            SPtrCriteria ComparativeFactory::CreateGTE(const SPtrColumn &column, const Data::SPtrValue &value) {
                return cldeplus_make_shared<Comparative::GreaterOrEqual>(column, value);
            }

            SPtrCriteria ComparativeFactory::CreateLT(const SPtrColumn &column, const Data::SPtrValue &value) {
                return cldeplus_make_shared<Comparative::Lesser>(column, value);
            }

            SPtrCriteria ComparativeFactory::CreateLTE(const SPtrColumn &column, const Data::SPtrValue &value) {
                return cldeplus_make_shared<Comparative::LesserOrEqual>(column, value);
            }

            SPtrCriteria ComparativeFactory::CreateLike(const SPtrColumn &column, const Data::SPtrValue &value) {
                return cldeplus_make_shared<Comparative::Like>(column, value);
            }

            SPtrCriteria ComparativeFactory::CreateNotLike(const SPtrColumn &column, const Data::SPtrValue &value) {
                return cldeplus_make_shared<Comparative::NotLike>(column, value);
            }

            SPtrCriteria ComparativeFactory::CreateIsNull(const SPtrColumn &column) {
                return cldeplus_make_shared<Comparative::IsNull>(column);
            }

            SPtrCriteria ComparativeFactory::CreateIsNotNull(const SPtrColumn &column) {
                return cldeplus_make_shared<Comparative::IsNotNull>(column);
            }
        }
    }
}