//
// Created by LE, Duc Anh on 6/7/15.
//

#include "SQLiteSourceException.h"
#include "SQLiteSourceHelper.h"


namespace Cloude {
    namespace Drivers {
        namespace SQLite {

            const std::string SQLiteSourceException::_name{"SQLiteSourceException"};

            SQLiteSourceException::SQLiteSourceException(int resultCode)
                    : cldeException{SQLiteSourceHelper::CopyToString(resultCode)},
                      _resultCode{resultCode} {
                //
            }

            SQLiteSourceException::SQLiteSourceException(int resultCode, const std::string &comment)
                    : cldeException{SQLiteSourceHelper::CopyToString(resultCode) + "\n" + comment},
                      _resultCode{resultCode} {
                //
            }
        }
    }
}


