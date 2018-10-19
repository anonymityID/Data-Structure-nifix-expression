
#ifndef EXPRESSIONEVALUATE_STACK_H
#define EXPRESSIONEVALUATE_STACK_H

#include <iostream>


using namespace std;

template <typename T>
class Stack{
private:
    const int maxSize=100;
    int count;
    T* ptr=NULL;                      //ָ��Ԫ�ش洢�ռ�
    void init();          //��ʼ��
public:
    Stack();
    ~Stack();
    bool empty();                //�ж��Ƿ�Ϊ��
    T pop();
    void push(const T  e);
    T top();
};

#include <iostream>

using namespace std;
template <typename T>
Stack<T>::Stack() {
    init();
}

template <typename T>
Stack<T>::~Stack() {
    delete [] ptr;
}

template <typename T>
void Stack<T>::init() {
    if(ptr!=NULL)
        delete [] ptr;
    ptr=new T [maxSize];
    count==0;
}
template <typename T>
bool Stack<T>::empty() {
    return count==0;
}

template <typename T>
T Stack<T>::pop() {
    T e=ptr[count-1];
    count--;
    return e;
}

template <typename T>
void Stack<T>::push(const T e) {
    ptr[count++]=e;
}

template <typename T>

T Stack<T>::top() {
    return ptr[count-1];
}
#endif //EXPRESSIONEVALUATE_STACK_H
