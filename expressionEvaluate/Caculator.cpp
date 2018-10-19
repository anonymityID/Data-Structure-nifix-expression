#include "Caculator.h"
#include <iostream>
#include <cmath>
using namespace std;
const int amount=9;
const char comp[amount][amount]={              //打表用于运算符的比较
        '>','>','<','<','<','<','<','>','>',   // +
        '>','>','<','<','<','<','<','>','>',   // -
        '>','>','>','>','<','<','<','>','>',   // *
        '>','>','>','>','<','<','<','>','>',   // /
        '>','>','>','>','>','<','<','>','>',   // ^
        '>','>','>','>','>','>',' ','>','>',   // !
        '<','<','<','<','<','<','<','=',' ',   // (
        ' ',' ',' ',' ',' ',' ',' ',' ',' ',   // )
        '<','<','<','<','<','<','<',' ','=',   // \0
};

int Caculator::symbolTrans (char op){
    switch (op){
        case '+':
            return 0;
        case '-':
            return 1;
        case '*':
            return 2;
        case '/':
            return 3;
        case '^':
            return 4;
        case '!':
            return 5;
        case '(':
            return 6;
        case ')':
            return 7;
        case '\0':
            return 8;
    }
}

char Caculator::compSymbol (char s1, char s2){       //栈顶符号和当前符号相比(调用symbolTrans函数）
    return comp[symbolTrans(s1)][symbolTrans(s2)];
}

double Caculator::oprate(double num1, char myOperator, double num2) {
    double res;
    switch (myOperator){
        case '+':
            res= num1+num2; break;
        case '-':
            res= num1-num2; break;
        case '*':
            res= num1*num2; break;
        case '/':
            res= num1/num2; break;
        case '^':
            res= pow(num1,num2); break;
        default: cout<<"error"<<endl;
    }
    return res;
}

double Caculator::oprate1( int num2) {
    double result=num2;
    for(int i=1; i<num2; i++)
        result*=i;
    return result;
}
void Caculator::numberR( char* &s, Stack<double> & numberStack){
    numberStack.push( (double)(*s-'0'));
    while( isdigit( *(++s)) )
    { numberStack.push( numberStack.pop()*10+ (*s-'0') ); }  //多为数字处理
    if('.'== *s){                                                                    //处理小数
        double fraction=1;
        while( isdigit( *(++s) ) ){ numberStack.push( numberStack.pop()+ (*s-'0')*(fraction/=10) ); }
    }
}
double Caculator::calculate(char* s) {
    symbolStack.push('\0');
    while(!symbolStack.empty()){
        if (isdigit(*s))
        { numberR( s, numberStack ); }    //读取数字可能出现多位数(转到numberR函数中处理)
        else{
            switch ( compSymbol (symbolStack.top(), *s )){
                case '<':
                    symbolStack.push(*s);
                    s++;  break;
                case '>':
                    if( '!' != symbolStack.top() ){                    //二元运算
                        myOperator=symbolStack.pop();
                        num2=numberStack.pop();
                        num1=numberStack.pop();
                        numberStack.push(oprate(num1,myOperator,num2));
                    }else {                                            //一元运算
                        myOperator=symbolStack.pop();
                        num2=numberStack.pop();
                        numberStack.push(oprate1(num2));
                    }
                    /**symbolStack.push(*s);
                    s++;**/
                    break;
                case '=':
                    symbolStack.pop();          //左右括号相遇的情况
                    s++;
                    break;
            }
        }
    }
    return numberStack.pop();
}