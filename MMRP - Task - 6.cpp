/*
You are given an N by M matrix (N and M are two integers entered on the console), in which the cells contain single
characters – either a . (dot) or a ! (exclamation mark) – representing "empty" or "mined" positions.
Write a program that prints an N by M matrix, where each cell contains a number, representing how many adjacent
cells, including itself, are "mined".
Each cell in a matrix has at most 8 adjacent cells – the cells directly above, below, to the left, to the right, as those
diagonally – to the left and above, to the right and above, to the right and below and to the left and below.
You are not allowed to use STL!

Input                     Output
5 5                       00111
.....                     00111
...!.                     00111
.....                     00000
.....                     00000
.....

Input                     Output
5 8
........                  00111000
...!....                  00122100
....!...                  00122100
........                  00122100
...!....                  00111000


Input                     Output
3 3                       353
!!!                       585
!.!                       353
!!!

5 5
.....
...!.
.....
.....
.....


*/
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

char ** readField(istream & istr, size_t & rows, size_t & cols) {
    char **matrix;

    istr >> rows >> cols;

    matrix = new char* [rows];

    for (size_t curRow = 0; curRow < rows;curRow++) {

        matrix[curRow] = new char[cols];
        for (size_t curCol = 0;curCol < cols;curCol++)
            cin >> matrix[curRow][curCol];

    }
    return matrix;
}

void deleteField(char** matrix, int rows) {
    for (size_t row = 0; row < rows;row++)
        delete[] matrix[row];
    delete matrix;
}

void printField(char **matrix, size_t rows, size_t cols) {

    for (size_t curRow = 0; curRow < rows;curRow++) { 
        for (size_t curCol = 0;curCol < cols;curCol++)
            cout << matrix[curRow][curCol];
        cout << endl;

    }
}

void markMine(char** result, size_t curRow, size_t curCol) {
    result[curRow][curCol]++;

}

void detectMine(char **result, size_t rows, size_t cols, size_t curRow, size_t curCol) {
    //upper row, all points
    if (curRow) {
        if (curCol)
            markMine(result, curRow - 1, curCol - 1);
        markMine(result, curRow - 1, curCol);
        if (curCol < (cols - 1))
            markMine(result, curRow - 1, curCol + 1);

    }
    //current row, all points
    if (curCol)
        markMine(result, curRow, curCol - 1);
    markMine(result, curRow, curCol);
    if (curCol < (cols - 1))
        markMine(result, curRow, curCol + 1);

    //bottom row, all points
    if (curRow < (rows - 1)) {
        if (curCol)
            markMine(result, curRow + 1, curCol - 1);
        markMine(result, curRow + 1, curCol);
        if (curCol < (cols + 1))
            markMine(result, curRow + 1, curCol + 1);

    }
}

char** processField(char** field, size_t rows, size_t cols) {
    char** result = new char* [rows];
    for (size_t curRow = 0; curRow < rows;curRow++) {

        result[curRow] = new char[cols];

        for (size_t curCol = 0;curCol < cols;curCol++)
            result[curRow][curCol] = '0';

    }

    for (size_t curRow = 0; curRow < rows;curRow++)
        for (size_t curCol = 0;curCol < cols;curCol++) {
            if (field[curRow][curCol] == '!') // mine  
               detectMine(result, rows, cols, curRow, curCol);
        }

    return result;
}

int main() {
    size_t rows, cols;
    char ** field = readField(cin, rows, cols);

    char **result = processField(field, rows, cols); 

    printField(result, rows, cols);

    deleteField(result, rows);
    deleteField(field, rows);
    return 0;
}
