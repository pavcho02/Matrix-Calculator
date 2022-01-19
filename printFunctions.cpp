#include "printFunctions.h"
#include "calculatingFunctions.h"

#include <iostream>
#include <fstream>
using namespace std;

void startMenu()
{
    cout << "Hello to Matrix Calculator!" << endl;
    cout << "1. Matrix Addition" << endl;
    cout << "2. Matrix Multiplication" << endl;
    cout << "3. Matrix Multiplication With a Number" << endl;
    cout << "4. Matrix Devision With a Number" << endl;
    cout << "5. Determinant" << endl;
    cout << "6. Transpose" << endl;
    cout << "7. Inverse Matrix" << endl;
    cout << "8. Exit" << endl;
    cout << "Enter a number to use the desired functionality:" << endl;
}

void continueMenu()
{
    cout << "Do you want to continue?" << endl;
    cout << "1. Yes" << endl;
    cout << "2. No" << endl;
    cout << "Enter a number referrred to the desired option:" << endl;
}

void clearScreen()
{
#ifdef _WIN32
    system("cls");
#elif __linux__
    system("clear");
#else
    for (int i = 0; i < 1000; i++)
    {
        cout << endl;
    }
#endif 
}

void matrixPrint(double** matrix, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void deleteMatrix(double** matrix, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void additionPrint()
{
    int rowsA;
    int columnsA;
    int rowsB;
    int columnsB;
    cout << "Enter two matrices!" << endl;
    cout << "Enter number of rows of Matrix A = ";    
    cin >> rowsA;
    cout << endl << "Enter number of columns of Matrix A = ";
    cin >> columnsA;
    cout << endl << "Enter Matrix A:" << endl;
    double** matrixA = new double*[rowsA];
    for (int i = 0; i < rowsA; i++)
    {
        matrixA[i] = new double[columnsA];
    }
    for (int i = 0; i < rowsA; i++)
    {
        for (int j = 0; j < columnsA; j++)
        {
            cin >> matrixA[i][j];
        }
    }
    cout << "Enter number of rows of Matrix B = ";
    cin >> rowsB;
    cout << endl << "Enter number of columns of Matrix B = ";
    cin >> columnsB;
    cout << endl << "Enter Matrix B:" << endl;
    double** matrixB = new double* [rowsB];
    for (int i = 0; i < rowsB; i++)
    {
        matrixB[i] = new double[columnsB];
    }
    for (int i = 0; i < rowsB; i++)
    {
        for (int j = 0; j < columnsB; j++)
        {
            cin >> matrixB[i][j];
        }
    }
    double** result = sum(matrixA,matrixB, rowsA,columnsA,rowsB,columnsB);
    if (result == nullptr)
    {
        cout << "Matrices must have equal dimensions" << endl;
        return;
    }
    cout << "A + B is:" << endl;
    matrixPrint(result,rowsA,columnsA);
    
    deleteMatrix(result, rowsA, columnsA);
    deleteMatrix(matrixA, rowsA, columnsA);
    deleteMatrix(matrixB, rowsB, columnsB);
}

void multiplicationWithNumberPrint()
{
    int rows;
    int columns;
    double number;
    cout << "Enter two operands!" << endl;
    cout << "Enter number of rows of Matrix = ";
    cin >> rows;
    cout << endl << "Enter number of columns of Matrix = ";
    cin >> columns;
    cout << endl << "Enter Matrix :" << endl;
    double** matrix = new double* [rows];
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = new double[columns];
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cin >> matrix[i][j];
        }
    }
    cout << "Number:" << endl;
    cin >> number;
    double** result = multiplicationWithNumber(matrix, rows, columns, number);
    cout << "A * x is:" << endl;
    matrixPrint(result, rows, columns);

    deleteMatrix(result, rows, columns);
    deleteMatrix(matrix, rows, columns);
}

void multiplicationPrint()
{
    int rowsA;
    int columnsA;
    int rowsB;
    int columnsB;
    cout << "Enter two matrices!" << endl;
    cout << "Enter number of rows of Matrix A = ";
    cin >> rowsA;
    cout << endl << "Enter number of columns of Matrix A = ";
    cin >> columnsA;
    cout << endl << "Enter Matrix A:" << endl;
    double** matrixA = new double* [rowsA];
    for (int i = 0; i < rowsA; i++)
    {
        matrixA[i] = new double[columnsA];
    }
    for (int i = 0; i < rowsA; i++)
    {
        for (int j = 0; j < columnsA; j++)
        {
            cin >> matrixA[i][j];
        }
    }
    cout << "Enter number of rows of Matrix B = ";
    cin >> rowsB;
    cout << endl << "Enter number of columns of Matrix B = ";
    cin >> columnsB;
    cout << endl << "Enter Matrix B:" << endl;
    double** matrixB = new double* [rowsB];
    for (int i = 0; i < rowsB; i++)
    {
        matrixB[i] = new double[columnsB];
    }
    for (int i = 0; i < rowsB; i++)
    {
        for (int j = 0; j < columnsB; j++)
        {
            cin >> matrixB[i][j];
        }
    }
    double** result = multiplication(matrixA, matrixB, rowsA, columnsA, rowsB, columnsB);
    if (result == nullptr)
    {
        cout << "Columns of matrix A must equal rows of matrix B!" << endl;
        return;
    }
    cout << "A * B is:" << endl;
    matrixPrint(result, rowsA, columnsB);

    deleteMatrix(result, rowsA, columnsB);
    deleteMatrix(matrixA, rowsA, columnsA);
    deleteMatrix(matrixB, rowsB, columnsB);
}

void devisionWithNumberPrint()
{
    int rows;
    int columns;
    double number;
    cout << "Enter two operands!" << endl;
    cout << "Enter number of rows of Matrix = ";
    cin >> rows;
    cout << endl << "Enter number of columns of Matrix = ";
    cin >> columns;
    cout << endl << "Enter Matrix :" << endl;
    double** matrix = new double* [rows];
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = new double[columns];
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cin >> matrix[i][j];
        }
    }
    cout << "Number:" << endl;
    cin >> number;
    double** result = devisionWithNumber(matrix, rows, columns, number);
    if (result == nullptr)
    {
        cout << "Cannot devide by 0!" << endl;
        return;
    }
    cout << "A / x is:" << endl;
    matrixPrint(result, rows, columns);

    deleteMatrix(result, rows, columns);
    deleteMatrix(matrix, rows, columns);
}

void determinantPrint()
{
    int rows;
    int columns;
    cout << "Enter a matrix!" << endl;
    cout << "Enter number of rows of Matrix = ";
    cin >> rows;
    cout << endl << "Enter number of columns of Matrix = ";
    cin >> columns;
    cout << endl << "Enter Matrix :" << endl;
    double** matrix = new double* [rows];
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = new double[columns];
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cin >> matrix[i][j];
        }
    }
    if (rows != columns)
    {
        cout << "Only square matrices have a determinant!";
        return;
    }
    double result = det(matrix, rows);
    cout << "detA is: " << result << endl;

    deleteMatrix(matrix, rows, columns);
}

void transposePrint()
{
    int rows;
    int columns;
    cout << "Enter a matrix!" << endl;
    cout << "Enter number of rows of Matrix = ";
    cin >> rows;
    cout << endl << "Enter number of columns of Matrix = ";
    cin >> columns;
    cout << endl << "Enter Matrix :" << endl;
    double** matrix = new double* [rows];
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = new double[columns];
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cin >> matrix[i][j];
        }
    }
    double** result = transpone(matrix, rows, columns);
    cout << "The transpose matrix is:" << endl;
    matrixPrint(result, columns, rows);    

    deleteMatrix(result, columns, rows);
    deleteMatrix(matrix, rows, columns);
}

void inversePrint()
{     
    int rows;
    int columns;
    cout << "Enter a matrix!" << endl;
    cout << "Enter number of rows of Matrix = ";
    cin >> rows;
    cout << endl << "Enter number of columns of Matrix = ";
    cin >> columns;
    cout << endl << "Enter Matrix :" << endl;
    double** matrix = new double* [rows];
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = new double[columns];
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cin >> matrix[i][j];
        }
    }
    if (rows != columns)
    {
        cout << "Only square matrices have inverse matrix!";
        return;
    }
    if (det(matrix, rows) == 0)
    {
        cout << "There is no inverse matrix!";
        return;
    }
    double** result = inverse(matrix, rows);   
    cout << "The inverse matrix is:" << endl;
    matrixPrint(result, rows, columns);

    deleteMatrix(result, rows, columns);
    deleteMatrix(matrix, rows, columns);
}
