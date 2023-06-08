/*
Read a text, extract its words (separated by spaces) find all short words (less than 5 characters), and print them
alphabetically, in lowercase, separate by a single comma and a single space.
• Use case-insensitive matching.
• Remove duplicated words
 Input                                                  Output
In SoftUni you can study Java C# PHP and JavaScript     2-3, and, c#, can, go, in,
                                                        java, php, you
JAVA and c# developers graduate in 2-3 years Go in      
 
*/

#include <iostream>
#include <string>
#include <utility>
#include <map>
#include <set>
#include <list>
#include <algorithm>
#include <sstream>

using namespace std;

int main() { 
    string buffer;
    getline(cin, buffer);
    //поставяме :: за да се разграничи  се използва, за да разграничи глобалната функция tolower от метода на класа std::locale ( така указваме, че искаме да ползваме глобалната функция)
    transform(buffer.begin(), buffer.end(), buffer.begin(), ::tolower); 

    istringstream istr(buffer);

    string buf; 
    set<string> words;

    while (istr >> buf) 
        words.insert(buf);  


    bool firstWord = true; 
    for (const auto& item : words) { 
        if (item.length() < 5) {
            if (!firstWord)
                cout << ", ";
            else
                firstWord = false;
            cout << item;
        }
    }

    cout << endl;
    return 0;
}
