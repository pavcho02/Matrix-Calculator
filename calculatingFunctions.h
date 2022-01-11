#ifndef CALCULATINGFUNCTIONS_H
#define CALCULATINGFUNCTIONS_H
double** sum(double** matrixA, double** matrixB, int rows, int cols);
double** multiplicationWithNumber(double** matrixA, int rows, int cols, int number);
double** transpone(double** matrixA, int rows, int cols);
double** devisionWithNumber(double** matrixA, int rows, int cols, int number);
double det(double** matrixA, int rows, int cols);
double** inverse(double** matrixA, int rows, int cols);
double** multiplication(double** matrixA, double** matrixB, int rowsA, int colsA, int rowsB, int colsB);
#endif
