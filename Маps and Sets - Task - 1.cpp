/*
Read a list of real numbers and print them in ascending order along with their number of occurrences.
Input                Output
8 2.5 2.5 8 2.5      2.5 -> 3
                     8 -> 2
                     
Input                Output
-2 0.33 0.33 2       -2 -> 1
                     0.33 -> 2
                     2 -> 1

*/

#include <iostream>
#include <string>
#include <utility>
#include <map>
#include <set>
#include <sstream>
using namespace std;

int main() {
	string buffer;
	getline(cin, buffer);

	istringstream istr(buffer);

	double dbl;
	map<double, size_t> occurences;
	while (istr >> dbl) 
		occurences[dbl]++;
		for (auto item : occurences) { 
			cout << item.first << " -> " << item.second << endl;   
		}
	

	return 0;
}
