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

#include "SQLiteSourceException.h"
#include "SQLiteSourceHelper.h"

namespace CLDEPlus {
    namespace Drivers {
        namespace SQLite {

            const string SQLiteSourceException::_name{"SQLiteSourceException"};

            SQLiteSourceException::SQLiteSourceException(int resultCode)
                    : CLDEException{SQLiteSourceHelper::CopyToString(resultCode)},
                      _resultCode{resultCode} {
                //
            }

            SQLiteSourceException::SQLiteSourceException(int resultCode, const string &comment)
                    : CLDEException{SQLiteSourceHelper::CopyToString(resultCode) + "\n" + comment},
                      _resultCode{resultCode} {
                //
            }
        }
    }
}


