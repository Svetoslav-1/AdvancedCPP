/*
You have an empty sequence, and you will be given N queries. Each query is one of these three types:
1 x – Push the element x into the stack.
2 – Delete the element present at the top of the stack.
3 – Print the maximum element in the stack.
4 – Print the minimum element in the stack.
After you go through all of the queries, print the stack in the following format:
"{n}, {n1}, {n2} …, {nn}"
Input
• The first line of input contains an integer N
• The next N lines each contain an above-mentioned query. (It is guaranteed that each query is valid.)
Output
• For each type 3 or 4 queries, print the maximum/minimum element in the stack on a new line.
Constraints
• 1 ≤ N ≤ 105
• 1 ≤ x ≤ 109
• 1 ≤ type ≤ 4
• If there are no elements in the stack, don't print anything on commands 3 and 4.

Input       Output
9           26
1 97        20
2           91, 20, 26
1 20
2
1 26
1 20
3
1 91
4
*/



#include <iostream>
#include <climits>
#include <stack>

using namespace std;

int minimum(const stack<int>& buffer) {
    int min = INT_MAX;
    stack<int> tempBuffer = buffer; 

    while (!tempBuffer.empty()) {
        int top = tempBuffer.top();
        tempBuffer.pop();
        if (top < min)
            min = top;
    }

    return min;
}

int maximum(const stack<int>& buffer) {
    int max = INT_MIN;
    stack<int> tempBuffer = buffer; 

    while (!tempBuffer.empty()) {
        int top = tempBuffer.top();
        tempBuffer.pop();
        if (top > max)
            max = top;
    }

    return max;
}

int main() {
    stack<int> buffer;
    int commands;
    cin >> commands;

    while (commands--) {
        int command, number;
        cin >> command;

        switch (command) {
            case 1:
                cin >> number;
                buffer.push(number);
                break;
            case 2:
                if (!buffer.empty())
                    buffer.pop();
                break;
            case 3:
                if (!buffer.empty())
                    cout << maximum(buffer) << endl;
                break;
            case 4:
                if (!buffer.empty())
                    cout << minimum(buffer) << endl;
                break;
        }
    }

    while (!buffer.empty()) {
        cout << buffer.top();
        buffer.pop();
        if (!buffer.empty())
            cout << ", ";
    }

    cout << endl;
    return 0;
}
