#ifndef POLY_H
#define POLY_H
using namespace std;

struct ATerm
{
    int coefficient;
    int exponent;
    ATerm* next;

    ATerm();
    ~ATerm();
};
typedef ATerm* Polynomial;

int abs(int);
bool isSign (char);
bool isDigit (char);
void sort (Polynomial&)
bool isValidInput (string);
void deleteSpaces (string&);
void formatPoly (const Polynomial);
bool isValidPoly(string, Polynomial&);
void append (Polynomial&, Polynomial&);
Polynomial add (const Polynomial, const Polynomial);
Polynomial multiply (const Polynomial, const Polynomial);
void termByTerm (const Polynomial, const Polynomial, Polynomial&);
void displayPoly (const Polynomial*, int, const Polynomial, char);
#endif