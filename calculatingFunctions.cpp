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
double** transpositions(double** matrixA, int rows, int cols)
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
double det(double** matrixA, int rows)
{
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
        det = matrixA[1][1] * matrixA[2][2] - matrixA[2][1] * matrixA[1][2];
    }
    if (rows == 4)
    {
        det = matrixA[1][1] * matrixA[2][2] - matrixA[2][1] * matrixA[1][2];
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            
        }
    }
    return det;
}