/*
Write a program that receives a string with N elements and returns two other strings – the first one is the same
string with lower-case letters only, and the second one is the same string with upper-case letters only. Write the
program with the help of pointers!
You are not allowed to use STL

Input                     Output
I love Programming        i love programming.
                          I LOVE PROGRAMMING.

Input                     Output
Let’s go on a Vacation!   let's go on a vacation!
                          LET'S GO ON A VACATION!

*/

#include <iostream>
using namespace std;

void convertToLowercase(char* str) {
    while (*str != '\0') {
        if (*str >= 'A' && *str <= 'Z') {
            *str = *str + 32;
        }
        str++;
    }
}

void convertToUppercase(char* str) {
    while (*str != '\0') {
        if (*str >= 'a' && *str <= 'z') {
            *str = *str - 32;
        }
        str++;
    }
}

int main() {
    const int MAX_SIZE = 100;
    char str[MAX_SIZE];

    cin.getline(str, MAX_SIZE);

    char lowercaseStr[MAX_SIZE];
    char uppercaseStr[MAX_SIZE];

    char* srcPtr = str;
    char* destLowerPtr = lowercaseStr;
    char* destUpperPtr = uppercaseStr;

    while (*srcPtr != '\0') {
        *destLowerPtr = *srcPtr;
        *destUpperPtr = *srcPtr;

        srcPtr++;
        destLowerPtr++;
        destUpperPtr++;
    }

    convertToLowercase(lowercaseStr);
    convertToUppercase(uppercaseStr);

    *destLowerPtr = '\0';
    *destUpperPtr = '\0';

    cout << lowercaseStr << endl;
    cout << uppercaseStr << endl;

    return 0;
}
