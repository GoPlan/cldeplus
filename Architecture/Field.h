//
// Created by GoPlan on 14/05/2015.
//

#ifndef CLOUD_E_CPLUS_FIELD_H
#define CLOUD_E_CPLUS_FIELD_H

#include <string>
#include <memory>

#include "Column.h"

namespace Cloude {
    namespace Architecture {

        // TODO: Field class may needs a dedicated/inheritable data subclass

        class Field {
        public:
            Field(const Field &srcField) = default;
            Field &operator=(const Field &srcField) = default;

            virtual ~Field() { };

            explicit Field(const std::shared_ptr<Column> &column);
            explicit Field(const std::shared_ptr<Column> &column, long value);
            explicit Field(const std::shared_ptr<Column> &column, unsigned long value);
            explicit Field(const std::shared_ptr<Column> &column, double value);
            explicit Field(const std::shared_ptr<Column> &column, const std::string &value);

            void *PointerToFieldValue();

            const std::shared_ptr<Column> &getColumn() const {
                return _column;
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

            char getAChar() const {
                return _char;
            }

            void setAChar(char aChar) {
                _char = aChar;
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

            char *getCString() {
                return &_cstr[0];
            }

        private:
            const std::shared_ptr<Column> &_column;

            std::string _string;

            int8_t _int8;
            int16_t _int16;
            int32_t _int32;
            int64_t _int64;

            uint8_t _uint8;
            uint16_t _uint16;
            uint32_t _uint32;
            uint64_t _uint64;

            char _char;
            char _cstr[255];
            double _double;
            float _float;

            bool _bool;
            void *_voidPtr;

            void ResetField();
        };
    }
}


#endif //CLOUD_E_CPLUS_FIELD_H
