#include "Stack.h"


template <class StackElemType>
Stack<StackElemType>::Stack(int Size)
{
    if(Size<1)
        throw"cannot construct an empty stack";
    stackArray = new StackElemType[Size];
    arraySize = Size;
    topIndex = -1; // Point at no where in the array
}
template <class StackElemType>
bool Stack<StackElemType>::push(StackElemType& item)
{
    if (topIndex >= arraySize - 1) {
        return false; // Reached Max of Stack
    }
    else {
        topIndex++;
        stackArray[topIndex] = item;
        return true;
    }
}

template <class StackElemType>
bool Stack<StackElemType>::pop(StackElemType& item)
{
    if (topIndex < 0) {
        return false; // No items in stack
    }
    else {
        item = stackArray[topIndex];
        topIndex--;
        return true;
    }
}

template <class StackElemType>
bool Stack<StackElemType>::top(StackElemType& item)
{
    if (topIndex < 0) {
        return false; // No items in stack
    }
    else {
        item = stackArray[topIndex];
        return true;
    }
}

template <class StackElemType>
bool Stack<StackElemType>::isEmpty()
{
    return bool(topIndex == -1);
}

template <class StackElemType>
bool Stack<StackElemType>::isFull()
{
    return bool(topIndex == arraySize - 1);
}

template <class StackElemType>
Stack<StackElemType>::~Stack()
{
    delete[] stackArray;
}
