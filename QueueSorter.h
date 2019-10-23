//
// Created by Eduardo Ribeiro da Silva on 23/10/19.
//

#ifndef SORTQUEUE_QUEUESORTER_H
#define SORTQUEUE_QUEUESORTER_H

#include <queue>

using namespace std;

template <typename T>
class QueueSorter {
public:
    QueueSorter();
    virtual ~QueueSorter();

    void sort(queue<T>& queue);

private:
    int minIndex(queue<T> &q, int sortedIndex);
    void insertMinToRear(queue<T> &q, int min_index);
};

template<typename T>
void QueueSorter<T>::sort(queue<T> &queue)
{
    for (int i = 1; i <= queue.size(); i++)
    {
        int min_index = minIndex(queue, queue.size() - i);
        insertMinToRear(queue, min_index);
    }
}

template<typename T>
QueueSorter<T>::QueueSorter() = default;

template<typename T>
QueueSorter<T>::~QueueSorter() = default;

// Queue elements after sortedIndex are
// already sorted. This function returns
// index of minimum element from front to
// sortedIndex
template<typename T>
int QueueSorter<T>::minIndex(queue<T> &q, int sortedIndex)
{
    int min_index = -1;
    T min_val = q.front();
    int n = q.size();
    for (int i=0; i<n; i++)
    {
        T curr = q.front();
        q.pop();  // This is dequeue() in C++ STL

        // we add the condition i <= sortedIndex
        // because we don't want to traverse
        // on the sorted part of the queue,
        // which is the right part.
        if (curr <= min_val && i <= sortedIndex)
        {
            min_index = i;
            min_val = curr;
        }
        q.push(curr);  // This is enqueue() in
        // C++ STL
    }
    return min_index;
}

// Moves given minimum element to rear of
// queue
template <typename T>
void QueueSorter<T>::insertMinToRear(queue<T> &q, int min_index)
{
    T min_val = q.front();
    int n = q.size();

    for (int i = 0; i < n; i++)
    {
        int curr = q.front();
        q.pop();
        if (i != min_index)
            q.push(curr);
        else
            min_val = curr;
    }
    q.push(min_val);
}

#endif //SORTQUEUE_QUEUESORTER_H
