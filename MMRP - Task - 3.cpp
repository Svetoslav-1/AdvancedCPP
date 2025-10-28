/*
Write a program that receives a 2-dimensional dynamic array with N rows and M columns and returns the first R
rows and C columns.
You are not allowed to use STL.

Input               Output
3 4                 1 2 3
1 2 3 4             11 22 33
11 22 33 44         111 222 333
111 222 333 444
3 3


Input               Output
4 4                 2 2
2 2 2 2             5 6
5 6 7 8             0 1
0 1 0 2             9 7
9 7 5 3
4 2


Input               Output
4 4                 2 2 2 2 
2 2 2 2             5 6 7 8
5 6 7 8
0 1 0 2
9 7 5 3
2 4
*/

#include <iostream> 
#include <vector>
#include <sstream>
#include <stack>
#include <memory>

using namespace std;

int main() {
    size_t rowNum, colNum;

    cin >> rowNum >> colNum; 

    size_t matrixSize = rowNum * colNum;

    unique_ptr<int[]> matrix(new int[matrixSize]); // Variant A  
    // row Y, column X
    //array[Y*colNum + X]
   for (size_t curRow = 0;curRow < rowNum;curRow++) {

       for (size_t curCol = 0;curCol < colNum;curCol++)
           cin >> matrix[curRow * colNum + curCol];
   }
   size_t rSize, cSize;
   cin >> rSize >> cSize; 
   for (size_t curRow = 0;curRow < rSize;curRow++) {
       for (size_t curCol = 0;curCol < cSize;curCol++)
           cout << matrix[curRow * colNum + curCol] << ' ';
       cout << endl;
   }
    return 0;
}
