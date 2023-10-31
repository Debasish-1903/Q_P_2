

/*Circular Queue

Time-Limit: 1 sec Score: 1.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

Design your implementation of the circular queue. The circular queue is a linear data structure in which the operations are performed based on FIFO (First In First Out) principle and the last position is connected back to the first position to make a circle. It is also called "Ring Buffer".

In a normal Queue, we can insert elements until the queue becomes full. But once the queue becomes full, we can not insert the next element even if there is a space in front of the queue.

Implement the following functions:

MyCircularQueue(k): Initializes the object with the size of the queue to be k.
int Front(): Gets the front item from the queue. If the queue is empty, return -1.
int Rear(): Gets the last item from the queue. If the queue is empty, return -1.
bool enQueue(int value): Inserts an element into the circular queue. Return true if the operation is successful.
bool deQueue(): Deletes an element from the circular queue. Return true if the operation is successful.
bool isEmpty(): Checks whether the circular queue is empty or not.
bool isFull(): Checks whether the circular queue is full or not.
Initially, the queue is empty.

You must solve the problem without using the built-in queue data structure in your programming language. 


Input Format

The first line of input contains Q - the number of queries.
The second line contains k.
Each of the next lines contains queries of one of the types mentioned in the problem statement.


Constraints

1 ≤ k, Q ≤ 105


Sample Input 1

9
3
enQueue 1
enQueue 2
enQueue 3
enQueue 4
Rear
isFull
deQueue
enQueue 4
Rear

Sample Output 1

True
True
True
False
3
True
True
True
4s*/


#include <bits/stdc++.h>
using namespace std;

class MyCircularQueue
{
public:
    struct ListNode
    {
        int val;
        ListNode *next, *back;
        ListNode() : val(0), next(nullptr), back(nullptr) {}
        ListNode(int x) : val(x), next(nullptr), back(nullptr) {}
        ListNode(int x, ListNode *next, ListNode *back) : val(x), next(next), back(back) {}
    };

    ListNode *head;
    int K;
    int curSize;

    MyCircularQueue(int k)
    {
        head = nullptr;
        K = k;
        curSize = 0;
    }

    bool enQueue(int value)
    {
        if (curSize == K)
            return false;

        ListNode *newNode = new ListNode(value);

        if (!curSize)
        {
            head = newNode;
            head->next = head;
            head->back = head;
        }
        else
        {
            ListNode *tail = head->next;
            tail->back = newNode;
            newNode->next = tail;
            newNode->back = head;
            head->next = newNode;
        }

        curSize++;

        return true;
    }

    bool deQueue()
    {
        if (!curSize)
            return false;

        if (curSize == 1)
        {
            delete (head);
            head = nullptr;
        }
        else
        {
            ListNode *tail = head->next;
            head = head->back;
            delete (head->next);
            head->next = tail;
            tail->back = head;
        }

        curSize--;
        return true;
    }

    int Front()
    {
        if (head)
            return head->val;
        return -1;
    }

    int Rear()
    {
        if (head)
            return head->next->val;
        return -1;
    }

    bool isEmpty()
    {
        return !curSize;
    }

    bool isFull()
    {
        return (curSize == K);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int q;
    cin >> q;

    int k;
    cin >> k;

    MyCircularQueue myCircularQueue(k);

    while (q--)
    {
        string s;
        cin >> s;

        if (s == "enQueue")
        {
            int val;
            cin >> val;

            if (myCircularQueue.enQueue(val))
                cout << "True\n";
            else
                cout << "False\n";
        }
        else if (s == "deQueue")
        {
            if (myCircularQueue.deQueue())
                cout << "True\n";
            else
                cout << "False\n";
        }
        else if (s == "Front")
        {
            cout << myCircularQueue.Front() << "\n";
        }
        else if (s == "Rear")
        {
            cout << myCircularQueue.Rear() << "\n";
        }
        else if (s == "isEmpty")
        {
            if (myCircularQueue.isEmpty())
                cout << "True\n";
            else
                cout << "False\n";
        }
        else if (s == "isFull")
        {
            if (myCircularQueue.isFull())
                cout << "True\n";
            else
                cout << "False\n";
        }
        else
        {
            assert(1 == 0); //This never happen
        }
    }

    return 0;
}