/*
 * Copyright (C) 2022 Liu Baihao. All rights reserved.
 *
 * This software is licensed under Enhanced License.
 * You may not use this file except in compliance with the License.
 * You should see a copy of Enhanced License in this software, if not, visit
 * <https://sharedwonder.github.io/enhanced-website/ENHANCED-LICENSE.txt>
 *
 * The Software is always provided "AS IS",
 * WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY.
 */

#pragma once

#include "enhanced/core/defines.h"
#include "enhanced/core/types.h"
#include "enhanced/core/annotations.h"

#include "enhanced/basic/export.h"
#include "IntegerWrapper.h"
#include "enhanced/basic/collection/List.h"

#if defined(C_LANGUAGE) || defined(ENHANCED_BASIC_C_MODE)

EXTERN_C_START

typedef struct String {
    /*!
     * This variable is used to hold the original string.
     */
    char* value;

    /*!
     * This variable is used to record the count of a string.
     */
    Size length;

    Size (*getLength)(const struct String* self);

    /*!
     * To concatenate the current string with another string.
     *
     * @param self
     * @param str
     * @return String
     */
    struct String (*const add)(struct String* self, struct String str);
} String;

ENHANCED_BASIC_API String newEmptyString();

ENHANCED_BASIC_API String toString(char* value);

ENHANCED_BASIC_API String newString(Size length);

ENHANCED_BASIC_API String newStringExt(const char* value, Size length);

EXTERN_C_END

#else

namespace enhanced::basic {
    class ENHANCED_BASIC_API String {
    private:
        /*!
         * This variable is used to hold the original string.
         */
        char* value;

        /*!
         * This variable is used to record the count of a string.
         */
        Size length;

        bool staticString;

        bool referString;

        class ENHANCED_BASIC_API SafeCharRef : IntegerWrapper<char> {
            friend class String;

        private:
            bool canModify;

            SafeCharRef(char& value, bool canModify);

            void check() const;

        public:
            IntegerWrapper<char>& operator++() override;

            IntegerWrapper<char>& operator--() override;

            const IntegerWrapper<char> operator++(int) override;

            const IntegerWrapper<char> operator--(int) override;

            IntegerWrapper<char>& operator=(const IntegerWrapper<char>& other) override;

            IntegerWrapper<char>& operator+=(const IntegerWrapper<char>& other) override;

            IntegerWrapper<char>& operator-=(const IntegerWrapper<char>& other) override;

            IntegerWrapper<char>& operator*=(const IntegerWrapper<char>& other) override;

            IntegerWrapper<char>& operator/=(const IntegerWrapper<char>& other) override;

            IntegerWrapper<char>& operator%=(const IntegerWrapper<char>& other) override;

            IntegerWrapper<char>& operator<<=(const IntegerWrapper<char>& other) override;

            IntegerWrapper<char>& operator>>=(const IntegerWrapper<char>& other) override;

            IntegerWrapper<char>& operator&=(const IntegerWrapper<char>& other) override;

            IntegerWrapper<char>& operator^=(const IntegerWrapper<char>& other) override;

            IntegerWrapper<char>& operator|=(const IntegerWrapper<char>& other) override;

            IntegerWrapper<char>& operator=(const char& other) override;

            IntegerWrapper<char>& operator+=(const char& other) override;

            IntegerWrapper<char>& operator-=(const char& other) override;

            IntegerWrapper<char>& operator*=(const char& other) override;

            IntegerWrapper<char>& operator/=(const char& other) override;

            IntegerWrapper<char>& operator%=(const char& other) override;

            IntegerWrapper<char>& operator<<=(const char& other) override;

            IntegerWrapper<char>& operator>>=(const char& other) override;

            IntegerWrapper<char>& operator&=(const char& other) override;

            IntegerWrapper<char>& operator^=(const char& other) override;

            IntegerWrapper<char>& operator|=(const char& other) override;
        };

        String(const char* value, byte) noexcept;

    public:
        static String from(const char* value);

        String(const char* value = "");

        String(char* value);

        explicit String(Size length);

        String(const String& other);

        String(String&& other) noexcept;

        ~String();

        RetCannotIgnored
        Size getLength() const;

        RetCannotIgnored
        bool isEmpty() const;

        RetCannotIgnored
        Size indexOf(char ch) const;

        RetCannotIgnored
        Size indexOf(const String& string) const;

        RetCannotIgnored
        Size indexOf(char ch, Size getN) const;

        RetCannotIgnored
        Size indexOf(const String& string, Size getN) const;

        RetCannotIgnored
        Size lastIndexOf(char ch) const;

        RetCannotIgnored
        Size lastIndexOf(const String& string) const;

        RetCannotIgnored
        Size lastIndexOf(char ch, Size getN) const;

        RetCannotIgnored
        Size lastIndexOf(const String& string, Size getN) const;

        RetRequiresRelease
        collection::List<Size>* indexOfAll(char ch) const;

        RetRequiresRelease
        collection::List<Size>* indexOfAll(const String& string) const;

        RetCannotIgnored
        char* getCharacters() const;

        RetCannotIgnored
        SafeCharRef at(Size index) const;

        RetCannotIgnored
        SafeCharRef operator[](Size index) const;

        RetCannotIgnored
        bool operator==(const String& string) const;

        RetCannotIgnored
        String operator+(const String& string) const;

        RetCannotIgnored
        operator char*() const;

        String& append(const String& string);

        String& replace(char oldChar, char newChar);

        String& replace(const String& oldSubstring, const String& newSubstring);

        String& replace(char oldChar, const String& newSubstring);

        String& replace(const String& oldSubstring, char newChar);

        char& set(Size index, char ch);

        String& toUpperCase();

        String& toLowerCase();

        String& operator=(const String& other);

        String& operator=(String&& other) noexcept;

        String& operator+=(const String& string);
    };
}

#endif // defined(C_LANGUAGE) || defined(ENHANCED_BASIC_C_MODE)
