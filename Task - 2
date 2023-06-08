/*
Play around with a queue. You will be given an integer N representing the number of elements to add, an integer S
representing the number of elements to remove from the queue, and finally an integer X, an element that you
should look for in the queue. If it is, print true on the console. If it's not printed the smallest element is currently
present in the queue. If there are no elements in the sequence, print 0 on the console

Example input: 
5 2 32
1 13 45 32 4


Example output:
true

Example input:
4 1 666
666 69 13 420

Example output:
13

*/

#include <iostream>
#include <string>
#include <climits>
#include <vector>
#include <sstream>  
#include <stack>
#include <cstdlib>
#include <queue> 
#include <cstdio>
#include <utility>

using namespace std;
int main() {

    int totalNumbers, removableElements, searchElement;
    cin >> totalNumbers >> removableElements >> searchElement;

    queue<int> q;

    for (int i = 0; i < totalNumbers; i++) {
        int element;
        cin >> element;
        q.push(element);
    }

    for (int i = 0; i < removableElements; i++) {
        q.pop();
    }

    bool found_x = false;
    int smallest_element = INT_MAX;
    while (!q.empty()) {
        int element = q.front();
        q.pop();
        if (element == searchElement) {
            found_x = true;
            break;
        }
        else {
            smallest_element = min(smallest_element, element);
        }
    }

    if (found_x) {
        cout << "true" << endl;
    }
    else if (smallest_element == INT_MAX) {
        cout << "0" << endl;
    }
    else {
        cout << smallest_element << endl;
    }

    return 0;
}
