//
// Created by LE, Duc Anh on 6/7/15.
//

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


