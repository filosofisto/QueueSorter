#include <iostream>
#include <queue>
#include "QueueSorter.h"

using namespace std;

int main()
{
    queue<int> q;
    q.push(30);
    q.push(11);
    q.push(15);
    q.push(4);

    // Sort queue
    QueueSorter<int> sorter;
    sorter.sort(q);

    // Print sorted queue
    while (q.empty() == false)
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
    return 0;
}