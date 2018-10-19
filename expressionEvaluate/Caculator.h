

#ifndef EXPRESSIONEVALUATE_CACULATOR_H
#define EXPRESSIONEVALUATE_CACULATOR_H

#include "Stack.h"
class Caculator {
private:
    char myOperator;
    double num1,num2;
    Stack<char> symbolStack;
    Stack<double> numberStack;
public:
    char s[100];
    double calculate (char* s);
    double oprate( double num1, char myOperator, double num2 );
    double oprate1( int num2 );
    void numberR( char* &s, Stack<double> &);
    int symbolTrans( char op );
    char compSymbol (char s1, char s2);
};


#endif //EXPRESSIONEVALUATE_CACULATOR_H
