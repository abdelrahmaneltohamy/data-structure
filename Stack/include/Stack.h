#ifndef STACK_H
#define STACK_H
//#include <assert.h>

template <class StackElemType>
class Stack {
public:
    Stack(int Size);
    bool push(StackElemType& item);
    bool pop(StackElemType& item);
    bool top(StackElemType& item);
    bool isEmpty();
    bool isFull();
    ~Stack();

private:
    StackElemType* stackArray;
    int arraySize;
    int topIndex;
};
#endif // STACK_H
