
/*
Circular Deque

Time-Limit: 1 sec Score: 1.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

Design your implementation of the circular double-ended queue (deque).

Your implementation should support the following operations:

MyCircularDeque(k): Constructor, set the size of the deque to be k.
insertFront(): Adds an item at the front of Deque. Return true if the operation is successful.
insertLast(): Adds an item at the rear of Deque. Return true if the operation is successful.
deleteFront(): Deletes an item from the front of Deque. Return true if the operation is successful.
deleteLast(): Deletes an item from the rear of Deque. Return true if the operation is successful.
getFront(): Gets the front item from the Deque. If the deque is empty, return -1.
getRear(): Gets the last item from Deque. If the deque is empty, return -1.
isEmpty(): Checks whether Deque is empty or not.
isFull(): Checks whether Deque is full or not.
Do it without using STL in C++. All operations should be O(1).


Input Format

The first line of input contains Q - the number of queries.
The second line contains k.
Each of the next lines contains queries of one of the types mentioned in the problem statement.


Constraints

1 ≤ k, Q ≤ 106


Sample Input 1

9
3
insertLast 1
insertLast 2
insertLast 3
insertLast 4
getRear
isFull
deleteLast
insertFront 4
getFront

Sample Output 1

True
True
True
False
3
True
True
True
4
*/








#include <bits/stdc++.h>
using namespace std;
class MyCircularDeque
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

    ListNode *head, *tail;
    int K;
    int curSize;

    MyCircularDeque(int k)
    {
        head = nullptr;
        tail = nullptr;
        K = k;
        curSize = 0;
    }

    bool insertFront(int value)
    {
        if (curSize == K)
            return false;

        ListNode *curNode = new ListNode(value);

        if (!curSize)
        {
            head = tail = curNode;
        }
        else
        {
            head->next = curNode;
            curNode->back = head;
            head = curNode;
        }

        curSize++;
        return true;
    }

    bool insertLast(int value)
    {
        if (curSize == K)
            return false;

        ListNode *curNode = new ListNode(value);

        if (!curSize)
        {
            head = tail = curNode;
        }
        else
        {
            tail->back = curNode;
            curNode->next = tail;
            tail = curNode;
        }

        curSize++;
        return true;
    }

    bool deleteFront()
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
            head = head->back;
            delete (head->next);
            head->next = nullptr;
        }

        curSize--;

        return true;
    }

    bool deleteLast()
    {
        if (!curSize)
            return false;

        if (curSize == 1)
        {
            delete (tail);
            tail = nullptr;
        }
        else
        {
            tail = tail->next;
            delete (tail->back);
            tail->back = nullptr;
        }

        curSize--;

        return true;
    }

    int getFront()
    {
        if (!curSize)
            return -1;
        return head->val;
    }

    int getRear()
    {
        if (!curSize)
            return -1;
        return tail->val;
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

    MyCircularDeque myCircularDeque(k);

    while (q--)
    {
        string s;
        cin >> s;

        if (s == "insertFront")
        {
            int val;
            cin >> val;
            if (myCircularDeque.insertFront(val))
                cout << "True\n";
            else
                cout << "False\n";
        }
        else if (s == "insertLast")
        {
            int val;
            cin >> val;
            if (myCircularDeque.insertLast(val))
                cout << "True\n";
            else
                cout << "False\n";
        }
        else if (s == "deleteFront")
        {
            if (myCircularDeque.deleteFront())
                cout << "True\n";
            else
                cout << "False\n";
        }
        else if (s == "deleteLast")
        {
            if (myCircularDeque.deleteLast())
                cout << "True\n";
            else
                cout << "False\n";
        }
        else if (s == "getFront")
        {
            cout << myCircularDeque.getFront() << "\n";
        }
        else if (s == "getRear")
        {
            cout << myCircularDeque.getRear() << "\n";
        }
        else if (s == "isEmpty")
        {
            if (myCircularDeque.isEmpty())
                cout << "True\n";
            else
                cout << "False\n";
        }
        else if (s == "isFull")
        {
            if (myCircularDeque.isFull())
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