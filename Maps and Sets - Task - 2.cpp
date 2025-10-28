/*Write a program that extracts from a given sequence of words all elements that appear in it an odd number of times
(case-insensitive).
• Words are given in a single line, space-separated.
• Print the result elements in lowercase, in their order of appearance.


Input                                    Output
Java C# PHP PHP JAVA C java              java, c#, c

Input                                    Output
3 5 5 hi pi HO Hi 5 ho 3 hi pi           5, hi

Input                                    Output
a a A SQL xx a xx a A a XX c             a, sql, xx, c
*/

#include <iostream>
#include <string>
#include <utility>
#include <map>
#include <list>
#include <algorithm>
#include <sstream>

using namespace std;

char tolower_char(char c) {
    return tolower(c);
}

int main() {
    string buffer;
    getline(cin, buffer);

    istringstream istr(buffer);

    string word;
    list<pair<string, size_t>> words;

    while (istr >> word) {
        //making lowecase letters
         //s transform  на първите 2 му задаваме рейндж (от къде до къде- от началото до края на думата) 
         // и след това от къде да започне да трансформира думата,
        //затова имаме трето word.begin())
        transform(word.begin(), word.end(), word.begin(), tolower_char);

        bool found = false;
        for (auto& elem : words) {
            if (elem.first == word) {
                elem.second++;
                found = true;
                break;
            }
        }

        if (!found)
            words.push_back(make_pair(word, 1));
    }
    //правим това долу, за да не печатаме запетая при първата дума, а чак при тези, след първата. Затова поставяме и променлива дали думата, която срещнем е първа или не
    bool firstWord = true;
    for (const auto& item : words) {
        if (item.second % 2) {
            if (!firstWord)
                
                cout << ", ";
            else
                firstWord = false;

            cout << item.first;
        }
    }

    cout << endl;

    return 0;
}
