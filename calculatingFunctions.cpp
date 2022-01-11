#include "calculatingFunctions.h"

double** sum(double** matrixA, double** matrixB, int rows, int cols)
{
    double** result = new double* [rows];
    for (int i = 0; i < rows; i++)
    {
        result[i] = new double[cols];
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
    return result;
}

double** multiplicationWithNumber(double** matrixA, int rows, int cols, int number)
{
    double** result = new double* [rows];
    for (int i = 0; i < rows; i++)
    {
        result[i] = new double[cols];
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[i][j] = matrixA[i][j] * number;
        }
    }
    return result;
}

double** transpone(double** matrixA, int rows, int cols)
{
    double** result = new double* [rows];
    for (int i = 0; i < rows; i++)
    {
        result[i] = new double[cols];
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[i][j] = matrixA[j][i];
        }
    }
    return result;
}

double** devisionWithNumber(double** matrixA, int rows, int cols, int number)
{
    double** result = new double* [rows];
    for (int i = 0; i < rows; i++)
    {
        result[i] = new double[cols];
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[i][j] = matrixA[i][j] / number;
        }
    }
    return result;
}

double det(double** matrixA, int rows, int cols)
{
    if (cols != rows || rows > 4 || cols > 4)
    {
        return -1;
    }
    double det = 0;
    if (rows == 1)
    {
        det = matrixA[0][0];
    }
    if (rows == 2)
    {
        det = matrixA[0][0] * matrixA[1][1] - matrixA[1][0] * matrixA[0][1];
    }
    if (rows == 3)
    {
        det = matrixA[0][0] * matrixA[1][1] * matrixA[2][2] + matrixA[0][1] * matrixA[1][2] * matrixA[2][0] + matrixA[0][2] * matrixA[1][0] * matrixA[2][1] - matrixA[0][2] * matrixA[1][2] * matrixA[2][0];
    }
    if (rows == 4)
    {
        det = matrixA[0][0] * matrixA[1][1] - matrixA[1][0] * matrixA[0][1];
    }
    
    return det;
}

double** inverse(double** matrixA, int rows, int cols)
{
    if(det(matrixA,rows,cols)==0)
    return nullptr;
}

double** multiplication(double** matrixA, double** matrixB, int rowsA, int colsA, int rowsB, int colsB)
{
    if (colsA != rowsB)
    {
        return nullptr;
    }
    double** result = new double* [rowsA];
    for (int i = 0; i < rowsA; i++)
    {
        result[i] = new double[colsB];
    }
    for (int i = 0; i < rowsA; i++)
    {
        for (int j = 0; j < colsB; j++)
        {
            for (int k = 0; k < colsA; k++)
            {
                result[i][j] = 0;
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
    return result;
}
