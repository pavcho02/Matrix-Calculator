#include <iostream>
#include "calculatingFunctions.h"
#include "printFunctions.h"
using namespace std;


int main()
{
    int operation = 0;
    while (true)
    {
        if (operation != 0 && operation != 8)
        {
            continueMenu();
            cin >> operation;
            if (operation == 1)
            {
                clearScreen();
                operation = 0;
            }
            if (operation == 2)
            {
                clearScreen();
                cout << "Goodbye!";
                break;
            }
        }
        if (operation == 0)
        {
            startMenu();
            cin >> operation;
        }
        if (operation == 8)
        {
            clearScreen();
            cout << "Goodbye!";
            break;            
        }
        if (operation == 1)
        {
            additionPrint();
        }
        if (operation == 2)
        {            
            multiplicationPrint();
        }
        if (operation == 3)
        {
            multiplicationWithNumberPrint();
        }
        if (operation == 4)
        {
            devisionWithNumberPrint();
        }
        if (operation == 5)
        {
            determinantPrint();
        }
        if (operation == 6)
        {
            transposePrint();
        }
        if (operation == 7)
        {
            inversePrint();
        }
    }
    return 0;
}
