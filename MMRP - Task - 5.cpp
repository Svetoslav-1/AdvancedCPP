/*
Write a program that reads two integer matrices (2D arrays) from the console and compares them element by
element.
You are not allowed to use STL.
For better code reusability, you could do the comparison in a function, which returns true if they are equal and
false if not.
Each matrix definition on the console will contain a line with a positive integer number R – the number of rows in
the matrix – followed by R lines containing the numbers in the matrix, separated by spaces (each line will have an
equal amount of numbers.
The matrices will have at most 10 rows and most 10 columns.
Print equal if the matrices match, and not equal if they do not match.

Input                     Output
1                         equal
1 2 3
1
1 2 3

Input                     Output
2                         equal
1 2 3
2 1 3
2
1 2 3
2 1 3


Input                     Output
2                         not equal 
1 2 3
4 5 6
2
1 3 2
4 5 6


Input                     Output
2                         not equal 
1 2 3
4 5 6
2
1 2
3 4

*/

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int** readMatrix(istream& istr, int & rows, int & cols) { 
    int **matrix;

    istr >> rows; istr.ignore();

    matrix = new int* [rows];
  
    for (size_t cur = 0; cur < rows;cur++) { 

        string buffer;
        getline(istr, buffer); 

        istringstream curLine(buffer);
        int curValue;
        size_t colNum = 0; 

        matrix[cur] = new int[10]; // maximum column is 19
        while (curLine >> curValue) {
             
            matrix[cur][colNum] = curValue;
            colNum++; 
        }
        cols = colNum;
    }
    return matrix; 
}

bool compareMatrices(int** m1, size_t rows1, size_t cols1, int** m2,
    size_t rows2, size_t cols2) {
    if (rows1 != rows2 || cols1 != cols2)
        return false;

    for (size_t curRow = 0; curRow < rows1;curRow++)
        for (size_t curCol = 0;curCol < cols1;curCol++){
            if (m1[curRow][curCol] != m2[curRow][curCol]) 
    return false;
}
   return true;
}
void deleteMatrix(int** matrix, int rows) { 
    for (size_t row = 0; row < rows;row++)  
        delete[] matrix[row];
    delete matrix;  
}

int main() {
    int **matrix1;
    int matrix1rows, matrix1cols;
    matrix1 = readMatrix(cin, matrix1rows, matrix1cols);
    int **matrix2;
    int matrix2rows, matrix2cols;
    matrix2 = readMatrix(cin, matrix2rows, matrix2cols);
    cout << (compareMatrices(matrix1, matrix1rows, matrix1cols, matrix2, matrix2rows, matrix2cols) ? "equal" : "not equal" )<< endl;

    deleteMatrix(matrix1, matrix1rows);
    deleteMatrix(matrix2, matrix2rows);
     
    return 0;
}
