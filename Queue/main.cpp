#include <iostream>
using namespace std;
const int maxQueue = 200;
template <class Type>
class Queue {
public:
    Queue()
    {
         Front = 0;
         Back = 0;
    }
    Queue(Type value,int intial_Size)
    {
        Front=0;
        Back=0;
        for(int i=0;i<intial_Size;i++)
        {
            push(value);
        }
    }
    ~Queue()
    {
        ////////////NO NEED FOR A DESTRUCTOR AS IT IS A STATIC QUEUE///////////////
        delete queueArray;
    }
    void push(Type value)
    {

        if (Next(Back) == Front)
        {
            throw "Queue is Full";
        }
        else
         {
            queueArray[Back] = value;
            Back=Next(Back);
        }
    }
    Type pop()
    {
        if(Back == Front)
        {
            throw "Queue is Empty";
        }
        else
        {
            Type popedValue=queueArray[Front];
            Front=Next(Front);
            return popedValue;
        }
    }
    Type& getFront()
    {
        return queueArray[Front];
    }
    bool isEmpty()
    {
        if(Back == Front)
            return true;
        else
            return false;
    }
    int Size()
    {
        if(Front-Back<0)
            return Back-Front;
        else
            return Front-Back;
    }
    Next(int pointer)
    {
        return ((pointer + 1) % maxQueue);
    }

private:
    int Front; // indicates front
    int Back; // indicates rear
    Type queueArray[maxQueue];
};
int main()
{
    Queue<int> queue1(3,30);
    cout<<queue1.Size()<<endl;
    for(int i=0;i<30;i++)
    {
        cout<<queue1.pop()<<endl;
    }
    for(int i=0;i<20;i++)
    {
        queue1.push(i);
    }
    cout<<"in between "<<queue1.getFront()<<endl;
     for(int i=0;i<20;i++)
    {
        cout<<queue1.pop()<<endl;
    }
    if(queue1.isEmpty())
        cout<<"queue is empty"<<endl;
    else
        cout<<"queue is not empty";
    Queue<int> queue2;
    for(int i=20;i<40;i++)
    {
        queue1.push(i);
    }
    for(int i=0;i<20;i++)
    {
        cout<<queue1.pop()<<endl;
    }
    return 0;
}
