//
// Created by GoPlan on 14/05/2015.
//

#ifndef CLOUD_E_CPLUS_FIELD_H
#define CLOUD_E_CPLUS_FIELD_H

#include "Column.h"
#include <string>

namespace Cloude {
    namespace Architecture {

        class Field {
        public:
            Field(const Field &srcField) = delete;
            Field &operator=(const Field &srcField) = delete;

            virtual ~Field() { };

            explicit Field(std::shared_ptr<Column>);
            Field(std::shared_ptr<Column>, const std::string &value);

            const std::shared_ptr<Column> &getSpColumn() const {
                return _spColumn;
            }

            int8_t getInt8() const {
                return _int8;
            }

            void setInt8(int8_t int8) {
                _int8 = int8;
            }

            int16_t getInt16() const {
                return _int16;
            }

            void setInt16(int16_t int16) {
                _int16 = int16;
            }

            int32_t getInt32() const {
                return _int32;
            }

            void setInt32(int32_t int32) {
                _int32 = int32;
            }

            int64_t getInt64() const {
                return _int64;
            }

            void setInt64(int64_t int64) {
                _int64 = int64;
            }

            uint8_t getUint8() const {
                return _uint8;
            }

            void setUint8(uint8_t uint8) {
                _uint8 = uint8;
            }

            uint16_t getUint16() const {
                return _uint16;
            }

            void setUint16(uint16_t uint16) {
                _uint16 = uint16;
            }

            uint32_t getUint32() const {
                return _uint32;
            }

            void setUint32(uint32_t uint32) {
                _uint32 = uint32;
            }

            uint64_t getUint64() const {
                return _uint64;
            }

            void setUint64(uint64_t uint64) {
                _uint64 = uint64;
            }

            double getADouble() const {
                return _double;
            }

            void setADouble(double aDouble) {
                _double = aDouble;
            }

            float getAFloat() const {
                return _float;
            }

            void setAFloat(float aFloat) {
                _float = aFloat;
            }

            bool isABool() const {
                return _bool;
            }

            void setABool(bool aBool) {
                _bool = aBool;
            }

            const std::string &getString() const {
                return _string;
            }

            void setString(const std::string &string) {
                _string = string;
            }

            void *getVoidPtr() const {
                return _voidPtr;
            }

            void setVoidPtr(void *voidPtr) {
                _voidPtr = voidPtr;
            }

        private:
            std::shared_ptr<Column> _spColumn;

            int8_t _int8;
            int16_t _int16;
            int32_t _int32;
            int64_t _int64;

            uint8_t _uint8;
            uint16_t _uint16;
            uint32_t _uint32;
            uint64_t _uint64;

            double _double;
            float _float;

            bool _bool;
            std::string _string;
            void *_voidPtr;

            void ResetField();
        };
    }
}


#endif //CLOUD_E_CPLUS_FIELD_H
