/*
You are given a sequence of strings, each on a new line. Every odd line on the console is representing a resource (e.g.
Gold, Silver, Copper, and so on), and every even – quantity. Your task is to collect the resources and print them
each on a new line.
Print the resources and their quantities in the format:
{resource} –> {quantity}
The quantities of inputs will be in the range [1-2 000]

Input       Output            
 
Gold        Gold -> 155
155         Silver -> 10
Silver      Copper -> 17
10
Copper
17
stop


Input      Output

gold       gold -> 170
155        silver -> 10
silver     copper -> 17
10
copper
17
gold
15
stop
*/

#include <iostream>
#include <string>
#include <utility>
#include <list>
#include <algorithm>
#include <sstream>
#include <vector>
#include <map>


using namespace std;



int main() { 
    string buf;
    cin >> buf;
    list<string> order;
    map<string, size_t>quantities;

    while (buf != "stop") {
        int quantity;
        cin >> quantity;  
        auto it = quantities.find(buf);
        if (it == quantities.end()) {
            order.push_back(buf);
        }
        quantities[buf] += quantity;
        cin >> buf;
    }

    for (string res : order) {
        cout << res << " -> " << quantities[res] << endl;
    }

    return 0;
}
