//
// Created by LE, Duc Anh on 6/24/15.
//

#include "Time.h"
#include "../Helper/TimeBasedHelper.h"
#include "../../Exception/CLDENonSupportedFunctionException.h"
#include "../../Exception/CLDENotImplementedException.h"

namespace CLDEPlus {
    namespace Foundation {
        namespace Data {
            namespace Type {

                Time::Time()
                        : TimeBasedValue{ValueType::Time, sizeof(TimeBasedValue::TSTime)} {
                    //
                }

                Time::Time(int hour, int minute, int second, int millisecond, bool hasOffSet, int offset)
                        : TimeBasedValue{ValueType::Time, sizeof(TimeBasedValue::TSTime)} {
                    _time.hour = hour;
                    _time.minute = minute;
                    _time.second = second;
                    _time.milliSecs = millisecond;
                    _time.offset = offset;
                    _hasOffSet = hasOffSet;
                }

                void *Time::PointerToBuffer() {
                    return &_time;
                }

                string Time::ToString() const {
                    return Data::Helper::TimeBasedHelper::TimeToISO8601String(_time, true, _hasOffSet);
                }

                Value &Time::operator+(Value const &rhs) {
                    throw Exception::CLDENonSupportedFunctionException("operator% can not be applied to Time type");
                }

                Value &Time::operator-(Value const &rhs) {
                    throw Exception::CLDENonSupportedFunctionException("operator% can not be applied to Time type");
                }

                Value &Time::operator*(Value const &rhs) {
                    throw Exception::CLDENonSupportedFunctionException("operator% can not be applied to Time type");
                }

                Value &Time::operator/(Value const &rhs) {
                    throw Exception::CLDENonSupportedFunctionException("operator% can not be applied to Time type");
                }

                Value &Time::operator%(Value const &rhs) {
                    throw Exception::CLDENonSupportedFunctionException("operator% can not be applied to Time type");
                }

                bool Time::LessThan(Common::IComparable const &target) const {
                    string msg{"LessThan"};
                    throw Exception::CLDENotImplementedException{msg};
                }

                bool Time::GreaterThan(Common::IComparable const &target) const {
                    string msg{"GreaterThan"};
                    throw Exception::CLDENotImplementedException{msg};
                }

                bool Time::EquivalentTo(Common::IComparable const &target) const {
                    string msg{"EquivalentTo"};
                    throw Exception::CLDENotImplementedException{msg};
                }
            }
        }
    }
}


