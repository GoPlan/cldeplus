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

#ifndef CLDEPLUS_PORTABLE_COMMONTYPES_H
#define CLDEPLUS_PORTABLE_COMMONTYPES_H

/*
 * The idea of of using clde_default is to encapsulate uses of STL components.
 * These components usually include string, vector, memory, exception, unordered_map, list, set.
 * All STL uses are declared & defined here so that they can be easily cross-platform maintained.
 *
 */

#include <cassert>
#include <memory>
#include <cstdlib>
#include <exception>
#include <string>
#include <vector>
#include <unordered_map>
#include <set>
#include <list>
#include <iterator>
#include <functional>

namespace CLDEPlus {
    namespace Foundation {
        namespace Data {
            template<typename T>
            class Primitive;
        }
    }

    namespace Primitives {

        using int16 = int16_t;
        using int32 = int32_t;
        using int64 = int64_t;

        using uint16 = uint16_t;
        using uint32 = uint32_t;
        using uint64 = uint64_t;

        using exception = std::exception;
        using string = std::string;

        template<typename T>
        using primitive = Foundation::Data::Primitive<T>;
    }

    using namespace Primitives;

    template<typename T>
    using shared_ptr = std::shared_ptr<T>;

    template<typename T>
    using unique_ptr = std::unique_ptr<T>;

    template<typename T>
    using vector = std::vector<T>;

    template<typename T>
    using set = std::set<T>;

    template<typename T>
    using list = std::list<T>;

    template<typename TKey, typename TElem>
    using unordered_map = std::unordered_map<TKey, TElem>;

    template<typename TKey, typename TElem>
    using pair = std::pair<TKey, TElem>;

    template<typename T, typename... Args>
    auto cldeplus_make_shared(Args &&... args) -> decltype(std::make_shared<T>(std::forward<Args>(args)...)) {
        return std::make_shared<T>(std::forward<Args>(args)...);
    }

    template<typename T, typename... Args>
    auto cldeplus_make_unique(Args &&... args) -> decltype(std::unique_ptr<T>(new T(std::forward<Args>(args)...))) {
        return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
    }
}

#endif //CLDEPLUS_PORTABLE_COMMONTYPES_H
