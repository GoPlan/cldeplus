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

#include "ValueEnumsHelper.h"

namespace CLDEPlus {
    namespace Data {
        namespace Helper {

            string ValueEnumsHelper::CopyCategoryToString(const ValueCategory &category) {

                string result;

                switch (category) {
                    case ValueCategory::Numeric:
                        result = "Numeric";
                        break;
                    case ValueCategory::CharacterBased:
                        result = "CharacterBased";
                        break;
                    case ValueCategory::UserDefined:
                        result = "UserDefined";
                        break;
                    case ValueCategory::Mathematic:
                        result = "Mathematic";
                        break;
                    case ValueCategory::DateTime:
                        result = "DateTime";
                        break;
                }

                return result;
            }

            string ValueEnumsHelper::CopyValueTypeToString(const ValueType &type) {

                string result;

                switch (type) {
                    case ValueType::Boolean:
                        result = "Boolean";
                        break;
                    case ValueType::Byte:
                        result = "Byte";
                        break;
                    case ValueType::Int16:
                        result = "Int16";
                        break;
                    case ValueType::Int32:
                        result = "Int32";
                        break;
                    case ValueType::Int64:
                        result = "Int64";
                        break;
                    case ValueType::UInt16:
                        result = "UInt16";
                        break;
                    case ValueType::UInt32:
                        result = "UInt32";
                        break;
                    case ValueType::UInt64:
                        result = "UInt64";
                        break;
                    case ValueType::Double:
                        result = "Double";
                        break;
                    case ValueType::Float:
                        result = "Float";
                        break;
                    case ValueType::String:
                        result = "String";
                        break;
                    case ValueType::VarChar:
                        result = "VarChar";
                        break;
                    case ValueType::Text:
                        result = "Text";
                        break;
                    case ValueType::Date:
                        result = "Date";
                        break;
                    case ValueType::Time:
                        result = "Time";
                        break;
                    case ValueType::DateTime:
                        result = "DateTime";
                        break;
                }

                return result;
            }
        }
    }
}


