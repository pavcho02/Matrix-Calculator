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
* <header file with print functions>
*
*/

#ifndef PRINTFUNCTIONS_H
#define PRINTFUNCTIONS_H
void startMenu();
void continueMenu();
void clearScreen();
void additionPrint();
void multiplicationWithNumberPrint();
void multiplicationPrint();
void devisionWithNumberPrint();
void determinantPrint();
void transposePrint();
void inversePrint();
void matrixPrint(double** matrix, int rows, int cols);
void deleteMatrix(double** matrix, int rows, int cols);
#endif
