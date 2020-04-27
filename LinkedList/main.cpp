#include <iostream>
using namespace std;
class List
{
    class Node;
      public:
    List()
    {
        Node* DummyNode= new Node;
        head=DummyNode;
        tail=DummyNode;

    }
    ~List()
    {

  Node *current = head;

    while (current!=tail)
    {
        Node* next = current->next;
        delete current;
        current = next;
    }
    delete tail;

    }
    class Iterator;

    List(int value,int initial_size)
    {
        Iterator it;
        Node* DummyNode= new Node;
        for(int i=0;i<initial_size;i++)
        {
            Node* n1= new Node;
            n1->data=value;
            if(i==0)
            {
                head=n1;
                it.setCurrent(n1);
            }
            else if(i==initial_size-1)
            {
                it.Current->next=n1;
                n1->previous=it.Current;
                tail=n1;
                tail->next=DummyNode;
                it.Current=it.Current->next;
            }
            else
            {
                it.Current->next=n1;
                n1->previous=it.Current;
                it.Current=it.Current->next;
            }

        }

    }
    int Size()
    {
        int listSize=0;
        Iterator It(head);
        bool reachedtheend=false;
    while(It.Current!=tail->next && !reachedtheend)
    {
        listSize++;
        if(It.Current!=tail)
            {
                It++;
            }
            else
            {
                reachedtheend=true;
            }
    }

        return listSize;
    }
    Iterator setIteratorPosition(int position)
    {
        Iterator it(head);
        if(position<1 || position>Size())
            {
                throw"position is out of range";
            }

            for(int i=1;i<position;i++)
            {
                it.Current=it.Current->next;
            }
            return it;
    }
    void push_Back(int value)
    {
        Iterator It(tail);
        Node* n1 = new Node;
        n1->data=value;
        n1->previous=tail;
        n1->next=tail->next;
        tail->next->previous=n1;
        tail->next=n1;
        tail=n1;

    }
    void Insert(int value, Iterator position)
    {
        Node* n1= new Node;
        n1->data=value;
        if(position.Current==tail)
        {
            n1->previous=tail->previous;
            tail->previous->next=n1;
            tail->previous=n1;
            n1->next=tail;
        }
        else if(position.Current==head)
        {
            //cout<<"iam changing heads"<<endl;
            head->previous=n1;
            n1->next=head;
            head=n1;
        }
        else
        {
            n1->previous=position.Current->previous;
            position.Current->previous=n1;
            n1->previous->next=n1;
            n1->next=position.Current;

        }

    }
    Iterator Erase(Iterator position)
    {
        Node* temp=position.Current;
        if(position.Current==tail->next)
            throw"cant delete after tail";
        if(position.Current==head)
        {
            head=position.Current->next;
            head->previous=nullptr;
            position.Current=head;
        }
        else if(position.Current==tail)
        {
            tail=position.Current->previous;
            tail->next=position.Current->next;
            position.Current=tail;
        }
        else
        {
            position.Current->previous->next=position.Current->next;
            position.Current->next->previous=position.Current->previous;
            position.Current=position.Current->next;
        }
        free(temp);
    }
    Iterator Begin()
    {
            Iterator It(head);
            return It;
    }
    Iterator End()
    {
        Iterator It(tail);
            return It;
    }
    List& operator=( List& another_list)
    {
        Iterator it(another_list.gethead());
        Iterator thisit;
        Node* DummyNode= new Node;
        for(int i=0;i<another_list.Size();i++)
        {
            Node* n1= new Node;
            n1->data=it.Current->data;
          if(i==0)
            {
                head=n1;
                thisit.setCurrent(n1);
                it.Current=it.Current->next;
            }
            else if(i==another_list.Size()-1)
            {
                thisit.Current->next=n1;
                n1->previous=thisit.Current;
                tail=n1;
                tail->next=DummyNode;
            }
            else
            {
                thisit.Current->next=n1;
                n1->previous=thisit.Current;
                thisit.Current=thisit.Current->next;
                it.Current=it.Current->next;
            }
        }
        return *this;
    }
    class Iterator
    {
        public:
            Node* Current;
        Iterator()
        {

        }
        Iterator(Node* pNode)
        {
            Current=pNode;
        }

        void operator++(int)
        {
            if(Current->next->next==nullptr)
                throw"cant increment beyond the tail";
            Current=Current->next;
        }
        void operator--(int)
        {
            if(Current->previous!=nullptr)
                throw"cant decrement beyond the head";
            Current=Current->previous;
        }
        bool operator==(const Iterator& It1)
        {
            if(It1.Current==Current)
                return true;
            else
                return false;
        }
        void setCurrent(Node* pNode)
        {
            Current=pNode;
        }
        int operator*()
        {
             return Current->data;
        }
    };
     Node* gettail()
    {
        return tail;
    }
    Node* gethead()
    {
        return head;
    }
    private:

    class Node
    {
        public:
         int data;
         Node* next=nullptr;
         Node* previous=nullptr;
    };
      Node* head;
      Node* tail;
};
int main()
{
    List L1(3,5);
    L1.push_Back(5);
    L1.Insert(2,L1.Begin());
    List::Iterator It(L1.gethead());
    L1.Insert(1,L1.setIteratorPosition(3));
    L1.Erase(L1.setIteratorPosition(4));
    bool reachedtheend=false;
    List L2;
    L2=L1;
    L1.push_Back(5);
    It.setCurrent(L1.gethead());
    //cout<<L1.gethead()->data<<en dl<<L2.gethead()->data;
    while(It.Current!=L1.gettail()->next && !reachedtheend)
    {
        cout<<It.Current->data<<" ";
        if(It.Current!=L1.gettail())
            {
                It++;
            }
            else
            {
                reachedtheend=true;
            }
    }
    return 0;
}
