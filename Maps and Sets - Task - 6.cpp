/*
Read a list of integers and extract all square numbers from it and print them in descending order. A square number
is an integer that is the square of any integer. For example, 1, 4, 9, and 16 are square numbers.

Input                    Output
3 16 4 5 6 8 9           16 9 4

Input                    Output
1 9 4 16 8 25 49 16      49 25 16 16 9 4 1
*/

#include <iostream>
#include <string>
#include <utility>
#include <list>
#include <algorithm>
#include <sstream>
#include <vector>
#include <cmath>

using namespace std;

bool compare(int& first, int& second) {
    return first > second;
}

int main() { 
    string buffer; 
    getline(cin, buffer); 

    istringstream istr(buffer); 

    int number; 
    list<int> occurrences;
    while (istr >> number)
        if (sqrt(number) == trunc(sqrt(number)))
            occurrences.push_back(number);

    occurrences.sort(compare);

    bool isFirst = true;
    for (auto it = occurrences.begin(); it != occurrences.end(); ++it) {
        if (isFirst)
            isFirst = false;
        else
            cout << " ";
        cout << *it;
    }
    cout << endl;

    return 0;
}
