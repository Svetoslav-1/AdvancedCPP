/*
* Read a list of real numbers and print the largest 3 of them. If less than 3 numbers exit, print all of them.
 Input                 Output
 10 30 15 20 50 5      50 30 20
 
 Input                 Output
 20 30                 30 20

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

    istringstream istr(buffer);

    double dbl; 
    set<double,greater <double>> occurrences;   

    while (istr >> dbl)  
        occurrences.insert(dbl); 

        size_t count = 3;
        for (auto item : occurrences) { 
            cout << item << ' ';
            count--;
            if (!count)
                break;
        }
    
    cout << endl;
    return 0;
}
