#include <iostream>
#include "Caculator.h"
#include <cctype>
#include <cstdio>
using namespace std;
 int main(){
    Caculator Ca1;
    cin.getline(Ca1.s,50);
    cout<<Ca1.calculate(Ca1.s);
    return  0;
}






