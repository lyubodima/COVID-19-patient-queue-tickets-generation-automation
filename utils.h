/*
Final Project Milestone 1
Module: utils.h
Filename: rebuild/MS2-0.1
Version 0.2
Author	Dmitri Lyubomudrov
Revision History
-----------------------------------------------------------
Date       16
2020/3/16  Preliminary release
2020/3/18  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/
#ifndef SDDS_UTILS_H_
#define SDDS_UTILS_H_
#include <iostream>

namespace sdds {

    extern bool debug;

    int getTime();

    int getInt();

    int getInt(const char* prompt);

    int getInt(int min, int max, const char* prompt = nullptr, const char* errorMessage = nullptr, bool showRangeAtError = true);

    char* getcstr(const char* prompt = nullptr, std::istream& istr = std::cin, char delimiter = '\n');

    void strCpy(char* des, const char* src);

    void strnCpy(char* des, const char* src, int len);

    int strCmp(const char* s1, const char* s2);

    int strnCmp(const char* s1, const char* s2, int len);

    int strLen(const char* s);

    const char* strStr(const char* str1, const char* str2);

    void strCat(char* des, const char* src);

    template <typename type>
    void removeDynamicElement(type* array[], int index, int& size) {
        delete array[index];
        for (int j = index; j < size; j++) {
            array[j] = array[j + 1];
        }
        size--;
    }
}
#endif // !SDDS_UTILS_H_



