/*
Read a list of integers, remove all negative numbers from it and print the remaining elements in reversed order. In
case there are no elements left in the list, print "empty".

Input               Output
10 -5 7 9 -33 50    50 9 7 10

Input               Output
7 -2 -10 1          1 7

Input               Output
-1 -2 -3            empty

*/

#include <iostream> 
#include <vector>
#include <sstream>
#include <stack>
#include <memory>

using namespace std;
const size_t MAX_ARR = 1000;

int main() {
    string buf;

    getline(cin, buf);

    istringstream istr(buf);

    unique_ptr<int[]> array(new int[MAX_ARR]);
    size_t arrSize = 0; 

    {
        int cur;

        while (istr >> cur) {


            if (arrSize >= MAX_ARR) {
                cout << "too big data." << endl;
                return 0;

            }
            array[arrSize] = cur;
            arrSize++;
        }
    }

    unique_ptr<int[]> result = make_unique<int[]>(arrSize); 
    size_t filteredSize = 0;
    for (size_t cur = arrSize - 1;;) {
        if (array[cur] >= 0) 
            result[filteredSize++] = array[cur];
        
        if (cur == 0) 
            break;

        cur--; 
    }
    if (filteredSize)
        for (int cur = 0;cur < filteredSize;cur++) {
            cout << result[cur] << ' ';
        }
    else
        cout << "empty";
    cout << endl; 

    return 0;
}
