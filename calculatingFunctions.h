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
* <header file with calculating functions>
*
*/

#ifndef CALCULATINGFUNCTIONS_H
#define CALCULATINGFUNCTIONS_H
double** sum(double** matrixA, double** matrixB, int rowsA, int colsA, int rowsB, int colsB);
double** multiplicationWithNumber(double** matrixA, int rows, int cols, int number);
double** transpone(double** matrixA, int rows, int cols);
double** devisionWithNumber(double** matrixA, int rows, int cols, int number);
double det(double** matrixA, int size);
void cofactor(double** matrix, double** used, int size, int row, int column);
double** inverse(double** matrixA, int size);
double** multiplication(double** matrixA, double** matrixB, int rowsA, int colsA, int rowsB, int colsB);
#endif
