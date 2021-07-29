/*
Final Project Milestone 1
Module: utils.cpp
Filename: M2 - rebuild/MS2-0.1
Version 0.4
Author	Dmitri Lyubomudrov
Revision History
-----------------------------------------------------------
Date       8 April
2020/3/16  Preliminary release
2020/3/18  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
#include "utils.h"
#include "Time.h"
using namespace std;
namespace sdds {

    bool debug = false;
    int getTime() {
        int mins = -1;
        if (debug) {
            Time t(0);
            cout << "Enter current time: ";
            do {
                cin.clear();
                cin >> t;

                if (!cin) {
                    cout << "Invlid time, try agian (HH:MM): ";
                    cin.clear();
                }
                else {
                    mins = int(t);
                }
                cin.ignore(1000, '\n');
            } while (mins < 0);
        }
        else {
            time_t t = time(NULL);
            tm lt = *localtime(&t);
            mins = lt.tm_hour * 60 + lt.tm_min;
        }
        return mins;
    }

    void clearKeyboard(void) { while (getchar() != '\n') {}; };

    int getInt() {
        char x = '\0'; int Value = 0;
        do {
            int* input_ptr = &Value;
            scanf("%d%c", &Value, &x);
            if (*input_ptr == 0 && x != '\n') { clearKeyboard(); printf("Bad integer value, try again: "); }
            else if (x != '\n') { clearKeyboard(); printf("Enter only an integer, try again: "); }

        } while (x != '\n');

        return Value;
    };

    int getInt(const char* prompt) { if (prompt != nullptr) { cout << prompt; } int result = getInt(); return result; }

    int getInt(int min, int max, const char* prompt, const char* errorMessage, bool showRangeAtError) {
        int input = getInt(prompt);
        while (input < min || input > max) {
            if (errorMessage != nullptr) cout << errorMessage;
            if (showRangeAtError) cout << "[" << min << " <= value <= " << max << "]: ";
            input = getInt();
        }return input;
    };

    char* getcstr(const char* prompt, std::istream& istr, char delimiter) {
        char* input;
        char buffer[2000];
        int size = 0;
        if (prompt != nullptr){ cout << prompt; }

        istr.getline(buffer, 2000, delimiter);
        size = strLen(buffer);
        input = new char[size + 1];

        for (auto i = 0; i < size; ++i) { input[i] = buffer[i]; } input[size] = '\0';
        return input;
    }

    int strLen(const char* s) {
        int counter = 0;
        while (s[counter] != '\0') { counter++; }
        return counter;
    };

    void strCpy(char* des, const char* src) {
        int i;
        for (i = 0; i < strLen(src); i++) { des[i] = src[i]; }
        des[strLen(src)] = '\0';
    };

    void strnCpy(char* des, const char* src, int len) {
        int i;
        for (i = 0; i < len; i++) {
            des[i] = src[i];
        }
        if (strLen(src) < len) {
            des[strLen(src) + 1] = '\0';
        }
    };

    int strCmp(const char* s1, const char* s2) {

        if (strLen(s1) == strLen(s2)) {
            int cmp = 0;
            int i;
            for (i = 0; i < strLen(s1); i++) {
                if (s1[i] == s2[i]) {
                    cmp++;
                }
            }
            if (cmp == strLen(s1) && cmp == strLen(s2)) {
                return 0;
            }
        }
        int i;
        for (i = 0; i < strLen(s1); i++) {
            if (s1[i] > s2[i]) {
                return 1;
            }
        }

        return -1;
    };

    int strnCmp(const char* s1, const char* s2, int len) {
        int i;
        int cmp = 0;
        for (i = 0; i < len; i++) {
            if (s1[i] == s2[i]) {
                cmp++;
            }
            if (cmp == len) { return 0; }
        }
        for (i = 0; i < len; i++) {
            if (s1[i] > s2[i]) {
                return 1;
            }
        }
        return -1;
    };

    const char* strStr(const char* str1, const char* str2) {

        int a = 0;
        int x;
        int counter = 0;
        for (x = 0; x < strLen(str1); x++) {
            if (str1[x] == str2[a]) {
                int x1 = x;

                for (a = 0; a < strLen(str2); a++) {
                    if (str1[x1] == str2[a]) {
                        x1++;
                        counter++;
                    }

                    else {
                        counter = 0;
                    }

                    if (counter == strLen(str2)) {
                        return &str1[x];
                    }
                }
            }
        }

        return nullptr;
    };

    void strCat(char* des, const char* src) {
        int i = 0, a = 0;
        while (des[i] != '\0') {
            i++;

        }
        while ((des[i++] = src[a++]) != '\0');
    };


}
