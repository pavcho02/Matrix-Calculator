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

void additionPrint()
{
    cout << "Enter two file names!" << endl;
    cout << "File name(Matrix A):" << endl;
    cout << "File name(Matrix B):" << endl;
    char file1[100];
    char file2[100];
    cin.getline(file1, 100);
    cin.getline(file2, 100);
    cout << "A + B is:" << endl;
}

void multiplicationWithNumberPrint()
{
    cout << "Enter two file names!" << endl;
    cout << "File name(Matrix):" << endl;
    cout << "File name(Number):" << endl;
    char fileName1[100];
    char fileName2[100];
    cin.getline(fileName1, 100);
    cin.getline(fileName2, 100);
    cout << "A * x is:" << endl;
    /*int rows;
    int columns;
    double** matrix = new double* [rows];
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = new double[columns];
    }
    fstream file1;
    file1.open(fileName1, fstream::in);
    
    file1.close();
    fstream file2;
    file2.open(fileName2, fstream::in);

    file2.close();
    for (int i = 0; i < rows; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;*/
}

void multiplicationPrint()
{
    cout << "Enter two file names!" << endl;
    cout << "File name(Matrix A):" << endl;
    cout << "File name(Matrix B):" << endl;
    char fileName1[100];
    char fileName2[100];
    cin.getline(fileName1, 100);
    cin.getline(fileName2, 100);
    cout << "A * B is:" << endl;
}

void devisionWithNumberPrint()
{
    cout << "Enter two file names!" << endl;
    cout << "File name(Matrix):" << endl;
    cout << "File name(Number):" << endl;
    char fileName1[100];
    char fileName2[100];
    cin.getline(fileName1, 100);
    cin.getline(fileName2, 100);
    cout << "A / x is:" << endl;
}

void determinantPrint()
{
    cout << "Enter file name!" << endl;
    cout << "File name(Matrix):" << endl;
    char fileName[100];
    cin.getline(fileName, 100);
    cout << "detA is:" << endl;
    //if (det() == -1)
    {
        cout << "Only square matrices have a determinant!";
        return;
    }
}

void transposePrint()
{
    cout << "Enter file name!" << endl;
    cout << "File name(Matrix):" << endl;
    char fileName[100];
    cin.getline(fileName, 100);
    cout << "The transpose matrix is:" << endl;
}

void inversePrint()
{
    cout << "Enter file name!" << endl;
    cout << "File name(Matrix):" << endl;
    char fileName[100];
    cin.getline(fileName, 100);
    cout << "The inverse matrix is:" << endl;
    if (det() == 0)
    {
        cout << "There is no inverse matrix!";
        return;
    }
}
