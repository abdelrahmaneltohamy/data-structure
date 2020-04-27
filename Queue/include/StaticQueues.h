/*
 * StaticQueues.h
 *
 *  Created on: Apr 18, 2017
 *      Author: haytham
 */

#ifndef STATICQUEUES_H_
#define STATICQUEUES_H_

const int maxQueue = 200;
template <class QueueElementType>
class StaticQueue {
public:
    StaticQueue();
    bool enqueue(const QueueElementType& item);
    bool dequeue(QueueElementType& item);
    bool front(QueueElementType& item);
    bool isEmpty();

private:
    int front_index; // indicates front
    int rear_index; // indicates rear
    QueueElementType queueArray[maxQueue];
    int nextPosition(int pointer);
};

template <class QueueElementType>
StaticQueue<QueueElementType>::StaticQueue()
{
    front_index = 0;
    rear_index = 0;
}

template <class QueueElementType>
bool StaticQueue<QueueElementType>::enqueue(const QueueElementType& item)
{
    if (nextPosition(rear_index) == front_index) {
        return false; // Queue is Full
    }
    else {
        rear_index = nextPosition(rear_index);
        queueArray[rear_index] = item;
        return true;
    }
}

template <class QueueElementType>
bool StaticQueue<QueueElementType>::dequeue(QueueElementType& item)
{
    if (rear_index == front_index) {
        return false; // Queue is Empty
    }
    else {
        front_index = nextPosition(front_index);
        item = queueArray[front_index];
        return true;
    }
}

template <class QueueElementType>
bool StaticQueue<QueueElementType>::front(QueueElementType& item)
{
    if (rear_index == front_index) {
        return false; // Queue is Empty
    }
    else {
        item = queueArray[nextPosition(front_index)];
        return true;
    }
}

template <class QueueElementType>
bool StaticQueue<QueueElementType>::isEmpty()
{
    return bool(rear_index == front_index);
}

template <class QueueElementType>
int StaticQueue<QueueElementType>::nextPosition(int pointer)
{
    return ((pointer + 1) % maxQueue);
}

#endif /* STATICQUEUES_H_ */
