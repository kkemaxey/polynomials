#include <iostream>
#include "poly.h"
using namespace std;

//------------------
// Basic constructor
//------------------

ATerm::ATerm()
{
    coefficient = 0;
    exponent = 0;
    next = nullptr;  
}


//-----------------
// Basic destructor
//-----------------

ATerm::~ATerm()
{
    coefficient = 0;
    exponent = 0;
    next = nullptr;  
}


//----------------------------------------------
// Returns the absolute value of a given integer
//----------------------------------------------

int abs (int a)
{
    return (a < 0 ? -a : a);
}


//------------------------------------------------------
// This will return true if the character is an operator
//------------------------------------------------------

bool isSign (char c)
{
    return (c == '+' || c == '-');
}


//-----------------------------------------------
// This returns true if the character is a digit
//-----------------------------------------------

bool isDigit (char c)
{
    return (c >= '0' && c <= '9');
}


//-----------------------------------------------
// This returns true if the character is a digit
//-----------------------------------------------

void sort (Polynomial& poly)
{
    //Implement heap sort !!!! O(1) space

    

    //or radix sort

    Polynomial temp = poly;
    int highestEx = 0;
    string biggestVal = "1";

    while (!temp->next)
    {
        if (highestEx < temp->exponent)
        {
            highestEx = temp->exponent;
        }

        if (stoi(biggestVal) < temp->coefficient)
        {
            biggestVal = to_string(temp->coefficient);
        }
        
        temp = temp->next;
    }
    int highestDig = biggestVal.length();
    
    Polynomial temp = poly;
    while (!temp->next)
    {
        temp->exponent += highestEx + 1;
        temp = temp->next;
    }

    RadixSort(poly, highestDig);

    Polynomial temp = poly;
    while (!temp->next)
    {
        temp->exponent -= highestEx + 1;
        temp = temp->next;
    }
}


//-------------------------------------------------------------------------------------------------------
// This function loops through a given string an ensures that it's ready for any string to int conversion
//-------------------------------------------------------------------------------------------------------

bool isValidInput (string str)
{
    if (str.empty())
    {
        return false;
    }
    
    for (int i = 0; i < str.length(); i++)
    {
        if (!isDigit(str[i]))
        {
            return false;
        }
    }
    return true;
}


//--------------------------------------------------------------------------------------------------------
// This functions takes a string and deletes every space in the string then resizes the string accordingly
//--------------------------------------------------------------------------------------------------------

void deleteSpaces (string &s1)
{
    int j = 0;
    for (int i = 0; i < s1.size(); i++)
    {
        if (s1[i] != ' ')
        {
            s1[j] = s1[i];
            j++;
        }
    }
    
    s1.resize(j);
}


//--------------------------------------------------------------------------------------------------------------------
// This is a helper for the display function. It basically ensures that the polynomial is printed in its proper format
//--------------------------------------------------------------------------------------------------------------------

void formatPoly (const Polynomial poly)
{
    Polynomial temp = poly;

    if (temp->coefficient < 0)
    {
        cout << "-";
    }
    while (temp != nullptr)
    {
        if (temp->exponent == 0)
        {
            cout << abs(temp->coefficient);
        }
        else if (abs(temp->coefficient) == 1)
        {
            cout << "x";
        }
        else
        {
            cout << abs(temp->coefficient) << "x";
        }

        if (temp->exponent != 1 && temp->exponent != 0)
        {
            cout << "^" << temp->exponent;
        }

        if (temp->next != nullptr)
        {
            if (temp->next->coefficient < 0)
            {
                cout << " - ";
            }
            else
            {
                cout << " + ";
            }
        }
        temp = temp->next;
    }
}


//-------------------------------------------------------------------------------------------------------------------------------------------------
// This parses the polynomial as it checks it. Once parsed, it validates it and if valid by the end, it appends the new node creating a linked list
//-------------------------------------------------------------------------------------------------------------------------------------------------

bool isValidPoly (string s, Polynomial& p)
{
    if (s.empty())
    {
        return false;
    }

    string temp;
    int i = 0, 
    int n = s.size();

    while (i < n)
    {
        temp = "";

        if (isSign(s[i]))
        {
            temp += s[i];
            i++;
            if (i >= n) return false;
        }
        
        bool hasDigits = false;
        while (i < n && isDigit(s[i]))
        {
            hasDigits = true;
            temp += s[i];
            i++;
        }
        
        bool hasX = false;
        if (i < n && s[i] == 'x')
        {
            hasX = true;
            i++;
        }
        
        if (!hasDigits && !hasX) return false;
        
        if (!hasDigits) temp += "1";
        
        int coef;
        try { coef = stoi(temp); }
        catch (...) { return false; }
        temp = "";
        
        int expo = 0;
        if (hasX)
        {
            if (i < n && s[i] == '^')
            {
                i++;
                if (i >= n) return false;
                
                if (isSign(s[i]))
                {
                    temp += s[i];
                    i++;
                    if (i >= n) return false;
                }
                
                if (!isDigit(s[i])) return false;
                while (i < n && isDigit(s[i]))
                {
                    temp += s[i];
                    i++;
                }

                try { expo = stoi(temp); }
                catch (...) { return false; }
            }
            else
            {
                expo = 1;
            }
        }
        else
        {
            expo = 0;
        }

        Polynomial nn = new ATerm;
        nn->coefficient = coef;
        nn->exponent = expo;
        nn->next = nullptr;
        append(p, nn);
        
        if (i < n && !isSign(s[i]))
        return false;
    }
    
    return true;
}


//------------------------------------------------------------------------------------------------------------
// This appends by taking in two polynomial variables and attaching the second one to the end of the first one
//------------------------------------------------------------------------------------------------------------

void append (Polynomial &p1, Polynomial &nn) //write this recursively
{
    if (!p1)
    {
        p1 = nn;
    }
    else
    {
        Polynomial temp = p1;
        while (temp->next != nullptr)
        {
            if (temp->exponent == nn->exponent)
            {
                temp->coefficient += nn->coefficient;
                return;
            }
            
            temp = temp->next;
        }
        
        if (temp->exponent == nn->exponent)
        {
            temp->coefficient += nn->coefficient;
            return;
        }
        nn->next = nullptr;
        temp->next = nn;
    }
}


//--------------------------------------------------------------------------------------------------------------------------------
// First check if either polynomial is empty, if so, return the other one. Otherwise compare each element and add if the exponents
// are equivalent. Then add anything left over in either of the polynomials to the end of the list.
//--------------------------------------------------------------------------------------------------------------------------------

Polynomial add (const Polynomial p1, const Polynomial p2)
{
    if (!p1) return p2;
    if (!p2) return p1;

    Polynomial p1Temp = p1;
    Polynomial p2Temp = p2;
    Polynomial answer = nullptr;
    Polynomial nn;

    while (p1Temp != nullptr && p2Temp != nullptr)
    {
        
        if (p1Temp->exponent > p2Temp->exponent)
        {
            nn = new ATerm;
            nn->coefficient = p1Temp->coefficient;
            nn->exponent = p1Temp->exponent;
            nn->next = nullptr;

            append(answer, nn);
            p1Temp = p1Temp->next;
        }
        else if (p1Temp->exponent < p2Temp->exponent)
        {
            nn = new ATerm;
            nn->coefficient = p2Temp->coefficient;
            nn->exponent = p2Temp->exponent;
            nn->next = nullptr;

            append(answer, nn);
            p2Temp = p2Temp->next;
        }
        else
        {
            int check = p1Temp->coefficient + p2Temp->coefficient;
            if (check != 0)
            {
                nn = new ATerm;
                nn->coefficient = check;
                nn->exponent = p1Temp->exponent;
                nn->next = nullptr;
                append(answer, nn);
            }

            p1Temp = p1Temp->next;
            p2Temp = p2Temp->next;
        }
    }

    while (p1Temp != nullptr)
    {
        nn = new ATerm;
        nn->coefficient = p1Temp->coefficient;
        nn->exponent = p1Temp->exponent;
        nn->next = nullptr;

        append(answer, nn);
        p1Temp = p1Temp->next;
    }

    while (p2Temp != nullptr)
    {
        nn = new ATerm;
        nn->coefficient = p2Temp->coefficient;
        nn->exponent = p2Temp->exponent;
        nn->next = nullptr;

        append(answer, nn);
        p2Temp = p2Temp->next;
    }

    if (!answer) 
    {
        answer = new ATerm;
        answer->coefficient = 0;
        answer->exponent = 0;
        answer->next = nullptr;
    }

    return answer;
}



//----------------------------------------------------------------------------------------------------------------------------------------------
// This multiplies one term by the other polynomial, saves the resulting linked list then adds it the linked list that will hold the full answer
//----------------------------------------------------------------------------------------------------------------------------------------------

Polynomial multiply (const Polynomial p1, const Polynomial p2)
{
    if (!p1)
    {
        return p2;
    }
    if (!p2)
    {
        return p1;
    }
    else
    {
        Polynomial p1Temp = p1;
        int p1Len = 1;
        while (p1Temp->next != nullptr)
        {
            p1Len++;
            p1Temp = p1Temp->next;
        }
        
        p1Temp = p1;
        Polynomial answer = nullptr;
        Polynomial termAnswer;
        for (int i = 0; i < p1Len; i++)
        {
            termAnswer = nullptr;
            termByTerm(p1Temp, p2, termAnswer);
            answer = add(answer, termAnswer);
            p1Temp = p1Temp->next;
        }   //maybe should delete all this memory afterwards
        
        return answer;
    }
}


//--------------------------------------------------------------------------------------------------
// This recursively multiplies 1 term by every term in the other list, then saves it into a new list
//--------------------------------------------------------------------------------------------------

void termByTerm (const Polynomial p1, const Polynomial p2, Polynomial& p3)
{
    if (!p2)
    {
        p3 = nullptr;
        return;
    }
    else
    {
        p3 = new ATerm;
        p3->coefficient = p1->coefficient * p2->coefficient;
        p3->exponent = p1->exponent + p2->exponent;
        
        termByTerm (p1, p2->next, p3->next);
    }
}


//------------------------------------------------------------------------------------
// Simple print function to go through each poly and print each term to specifications
//------------------------------------------------------------------------------------

void displayPoly (const Polynomial* arr, int size, const Polynomial ans, char op)
{
    for (int i = 0; i < size; i++)
    {
        cout << "[";
        formatPoly(arr[i]);
        cout << "] ";

        if (i != size - 1)
        {
            cout << op << " ";
        }
    }
    
    if (op == '+')
    {
        cout << endl << "    = ";
    }
    else
    {
        cout << endl << "        = ";
    }
    formatPoly(ans);
    cout << endl << endl;
}