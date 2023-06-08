/*
 Read a list of decimal numbers and sort them in increasing order. Print the output as shown in the examples below.
 
 Input            Output
 8 2 7 3          2 <= 3 <= 7 <= 8

 Input            Output
 2 4 -9           -9 <= 2 <= 4
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

	int dbl;
	map<int, size_t> occurrences;
	while (istr >> dbl)
		occurrences[dbl]++;
	bool isFirst = true;
	for (auto item : occurrences) { 
		if (isFirst)
			isFirst = false;
		else
			cout << " <= ";
		cout << item.first;   
	}
	cout << endl; 

	return 0;
}
