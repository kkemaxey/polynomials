#include <iostream>
#include <string>
#include "poly.h"
using namespace std;

//------------------------------------------
// The main will handle the input validation
//------------------------------------------

int main()
{
    string userInput;
    do
    {    
        do
        {
            cout << "Number of polynomials -> ";
            
            getline(cin, userInput);

            if (userInput == "0") return 0;

            if (!isValidInput(userInput) || stoi(userInput) > 10 || stoi(userInput) < 2)
            {
                cout << "Please enter a valid input. " << endl;
                userInput = "11";
            }
        } while (userInput == "11");

        int MAX_POLY = stoi(userInput);
        Polynomial* polyArr = new Polynomial[MAX_POLY];
        string polyInput;

        for (int i = 0; i < MAX_POLY; i++)
        {
            polyArr[i] = nullptr;
            cout << "Input polynomial " << i+1 << " -> ";
            getline(cin, polyInput);
            deleteSpaces(polyInput);
            
            if (!isValidPoly(polyInput, polyArr[i]))
            {
                cout << "Please enter a valid input. " << endl;
                i--;
            }

            // sort(polyArr[i]);
        }
    
        Polynomial sum = nullptr;
        Polynomial product = nullptr;
        for (int i = 0; i < MAX_POLY; i++)
        {
            sum = add(sum, polyArr[i]);
            product = multiply(product, polyArr[i]);
        }

        cout << endl;
        cout << "Sum = ";
        displayPoly(polyArr, MAX_POLY, sum, '+');
        cout << "Product = ";
        displayPoly(polyArr, MAX_POLY, product, '*');
        cout << "----------------------------------------" << endl << endl;
        
        userInput = "11";
    } while (userInput == "11");

    return 0;
}