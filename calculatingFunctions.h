#ifndef CALCULATINGFUNCTIONS_H
#define CALCULATINGFUNCTIONS_H
double** sum(double** matrixA, double** matrixB, int rowsA, int colsA, int rowsB, int colsB);
double** multiplicationWithNumber(double** matrixA, int rows, int cols, int number);
double** transpone(double** matrixA, int rows, int cols);
double** devisionWithNumber(double** matrixA, int rows, int cols, int number);
double det(double** matrixA, int size);
double** inverse(double** matrixA, int rows);
double** multiplication(double** matrixA, double** matrixB, int rowsA, int colsA, int rowsB, int colsB);
#endif
