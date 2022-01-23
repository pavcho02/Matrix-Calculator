/**
*
* Solution to course project # 11
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2021/2022
*
* @author Pavlin Georgiev Georgiev
* @idnumber 9MI0600106
* @compiler VC
*
* <file with calculating functions>
*
*/

#include "calculatingFunctions.h"

double** sum(double** matrixA, double** matrixB, int rowsA, int colsA, int rowsB, int colsB)
{
    int cols = colsA;
    int rows = rowsA;
    if (colsA != colsB && rowsA != rowsB)
    {
        return nullptr;
    }
    double** result = new double* [rows];
    for (int i = 0; i < rows; i++)
    {
        result[i] = new double[rows];
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < rows; j++)
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
    double** result = new double* [cols];
    for (int i = 0; i < cols; i++)
    {
        result[i] = new double[rows];
    }
    for (int i = 0; i < cols; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            result[i][j] = matrixA[j][i];
        }
    }
    return result;
}

double** devisionWithNumber(double** matrixA, int rows, int cols, int number)
{
    if (number == 0)
    {
        return nullptr;
    }
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

// Function to get cofactor of A[p][q] in used[][]
void cofactor(double** matrix, double** used, int size, int row, int column)
{
    int indexI = 0, indexJ = 0;
    for (int i = 0; i < size; i++) 
    {
        for (int j = 0; j < size; j++) 
        {
            if (i != row && j != column) 
            {
                used[indexI][indexJ++] = matrix[i][j];
                if (indexJ == size - 1) 
                {
                    indexJ = 0;
                    indexI++;
                }
            }
        }
    }

}

double det(double** matrix, int size)
{
    double determinant = 0;
    int sign = 1;
    if (size == 1)
    {
        return matrix[0][0];
    }
    double** result = new double* [size];
    for (int i = 0; i < size; i++)
    {
        result[i] = new double[size];
    }
    for (int i = 0; i < size; i++)
    {
        cofactor(matrix, result, size, 0, i);
        determinant += sign * matrix[0][i] * det(result, size - 1);
        sign = -sign;
    }
    return determinant;
}


void adjustable(double** matrix, double** adj, int size) 
{
    if (size == 1) 
    {
        adj[0][0] = 1;
        return;
    }
    int sign = 1;
    double** used = new double* [size];
    for (int i = 0; i < size; i++)
    {
        used[i] = new double[size];
    }
    for (int i = 0; i < size; i++) 
    {
        for (int j = 0; j < size; j++) 
        {
            cofactor(matrix, used, i, j, size);
            if ((i + j) % 2 == 0) 
            {
                sign = 1;
            }
            else 
            {
                sign = -1;
            }
            adj[j][i] = (sign) * (det(used, size - 1)); //transpose matrix with all adQuantities
        }
    }
}

double** inverse(double** matrix, int size)
{
    double** result = new double* [size];
    for (int i = 0; i < size; i++)
    {
        result[i] = new double[size];
    }
    double determinant = det(matrix, size);
    double** adj = new double* [size];
    for (int i = 0; i < size; i++)
    {
        adj[i] = new double[size];
    }
    adjustable(matrix, adj, size);
    for (int i = 0; i < size; i++) 
    {
        for (int j = 0; j < size; j++) 
        {
            result[i][j] = adj[i][j]/(determinant);
        }
    }
    return result;
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
            result[i][j] = 0;
            for (int k = 0; k < colsA; k++)
            {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
    return result;
}
