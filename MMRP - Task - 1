/*
Write a program that sums all of the numbers in a list in the following order:
first + last, first + 1 + last - 1, first + 2 + last - 2, … first + n, last - n.

Input         Output
1 2 3 4 5     6 6 3

Input         Output
1 2 3 4       5 5
*/

#include <iostream> 
#include <vector>
#include <sstream>

using namespace std;
const size_t MAX_ARR = 1000;

int main() { 
    string buf;

    getline(cin, buf);

    istringstream istr(buf);

    int* array = new int[MAX_ARR]; 

    int arrSize = 0; 

    {
        int cur;

        while (istr >> cur) {


            if (arrSize >= MAX_ARR) {
                cout << "too big data." << endl;
                delete[] array;
                return 0;

            }
            array[arrSize] = cur;
            arrSize++;
        }
    }

    
        int cur = 0;
        for (; cur < arrSize / 2;cur++) {
            cout << array[cur] + array[arrSize - 1 - cur] << ' ';
        }
        if (arrSize % 2) {
            cout << array[cur];
        }
        cout << endl; 

    
    delete [] array;
    return 0;
}
