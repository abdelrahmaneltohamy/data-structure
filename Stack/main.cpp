#include <iostream>
using namespace std;
template <class StackElemType>
class Stack {
public:
    Stack(int Size)
    {
        if(Size<1)
            throw"cannot construct an empty stack";
        stackArray = new StackElemType[Size];
        arraySize = Size;
        topIndex = -1; // Point at no where in the array

    }
    Stack(StackElemType value, int intial_size)
    {
        if(intial_size<1)
            throw"cannot construct an empty stack";
        stackArray = new StackElemType[intial_size];
        arraySize = intial_size;
        topIndex = -1;
        for(int i=0;i<arraySize;i++)
        {
            push(value);
        }
    }
    void push(StackElemType value)
    {

        if (topIndex >= arraySize - 1)
        {
            throw"reached max of array";
        }
        else
        {
            topIndex++;
            stackArray[topIndex] = value;
        }

    }
    StackElemType& pop()
    {
        if (topIndex < 0)
             throw"stack is empty";
        else
        {
           return stackArray[topIndex--];

        }
    }
    StackElemType& top()
    {
        if (topIndex < 0)
            throw"stack is empty";
        else
        {
            return stackArray[topIndex];

        }
    }
    bool isEmpty()
    {
        if(topIndex==-1)
            return true;
        else
            return false;
    }
    bool isFull()
    {
        if(topIndex==arraySize-1)
            return true;
        else
            return false;
    }
    ~Stack()
    {
        delete[] stackArray;
    }
    int Size()
    {
        return topIndex+1;
    }

private:
    StackElemType* stackArray;
    int arraySize;
    int topIndex;
};
int main()
{
    Stack<int> mystack(20,30);
     int mm=mystack.top();
    cout<<mm<<endl<<mystack.Size()<<endl;
    while(!mystack.isEmpty())
    {
        mm=mystack.pop();
        cout<<mm<<"  ";
    }
    cout<<endl;
    Stack<int> mystack2(10);
    mystack2.push(3);
    mystack2.push(4);
    mystack2.push(5);
    try
    {
        while(!mystack2.isEmpty())
        {
            mm=mystack2.pop();
            cout<<endl<<mm<<"  ";
        }
    }
    catch (char const* hh)
    {
        cout<<endl<<hh;
    }
    return 0;
}
