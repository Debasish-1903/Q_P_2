
/*

Design a queue that supports push and pop operations in the front, middle, and back.


Input Format

Implement the FrontMiddleBack class:

FrontMiddleBack() : Initializes the queue.
void pushFront(int val) : Adds val to the front of the queue.
void pushMiddle(int val) : Adds val to the middle of the queue.
void pushBack(int val) : Adds val to the back of the queue.
int popFront() : Removes the front element of the queue and returns it. If the queue is empty, return -1.
int popMiddle() : Removes the middle element of the queue and returns it. If the queue is empty, return -1.
int popBack() : Removes the back element of the queue and returns it. If the queue is empty, return -1.
Note: When there are two middle position choices, the operation is performed on the left middle position choice. For example:

Pushing 6 into the middle of [1, 2, 3, 4, 5] results in [1, 2, 6, 3, 4, 5].
Popping the middle from [1, 2, 3, 4, 5, 6] returns 3 and results in [1, 2, 4, 5, 6].

Output Format

For every pop function, return the popped element.


Constraints

1 ≤ val ≤ 109

At most 105 calls will be made to pushFront, pushMiddle, pushBack, popFront, popMiddle, and popBack.


Sample Input 1

9
pushFront 1
pushBack 2
pushMiddle 3
pushMiddle 4
popFront
popMiddle
popMiddle
popBack
popFront

Sample Output 1

1
3
4
2
-1

Note

The state of the queue after the operations:
[1]
[1, 2]
[1, 3, 2]
[1, 4, 3, 2]
[4, 3, 2]
[4, 2]
[2]
[]
-1 -> [] (The queue is empty)*/



#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define ull unsigned long long int
#define mod 1000000007
#define inf 1e9
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define pob pop_back
#define f first
#define s second
#define nl "\n"
#define pi pair<int,int>
//#define v vector<long long int>
#define vp vector<pair<int,int>>
#define vvl vector<vector<long long int>>
#define rep(n) for(int i=0 ; i<n ; i++)
#define rei(i) for(int i=n ; i>0 ; i--)
#define prio priority_queue
#define np next_permutation
#define N 200100

#define yes "YES"
#define no "NO"

class FrontMiddleBackQueue
{
public:

 deque<int>f,s;
 
    FrontMiddleBackQueue()
    {
      // balancing//
      
    
       
        
    }
    
     void balancing(){
         
           if(f.size()>s.size()){
          s.push_front(f.back());    // making fist size= s.size-1;  // for odd no of element
          f.pop_back();
      }
      
      if(s.size()>f.size()+1){   
          
          f.push_back(s.front()); // making f.size==s.size   // for total even no of element
          s.pop_front();
      } 
         
         
         
     }
    
    
    
    void pushFront(int val)
    {
        f.push_front(val);
        
        balancing();
        
        
    }

    void pushMiddle(int val)
    {
        
        if(f.size()==s.size()){
            s.push_front(val);
        }else{
            
            f.push_back(val);
            
        }
        
        
    }

    void pushBack(int val)
    {
        
        s.push_back(val);
        balancing();
        
    }

    int popFront()
    {
        if(f.empty()&&s.empty()) return -1;
        
        int x;
        if(f.empty()){
            
            x=s.front();
            s.pop_front();
            
            
        }else{
            
            x=f.front();
            f.pop_front();
           
        }
         balancing();
            
        return x;
        
    }

    int popMiddle()
    {
        
       if(f.empty()&&s.empty()) return -1;
       
      int x; 
      if(f.size()==s.size()){
          
          x=f.back();
          f.pop_back();
          
          
          
      }else{
          
          x=s.front();
          s.pop_front();
          
          
      }
        
        
        return x;
        
        
    }

    int popBack()
    {
        
        if(f.empty()&&s.empty()) return -1; 
        
        int x;
        x=s.back();
        s.pop_back();
        
        balancing();
        return x;
        
        
        
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int q;
    cin >> q;
    FrontMiddleBackQueue *obj = new FrontMiddleBackQueue();
    for (int i = 0; i < q; i++)
    {
        string op;
        cin >> op;
        if (op == "pushFront")
        {
            int val;
            cin >> val;
            obj->pushFront(val);
        }
        else if (op == "pushMiddle")
        {
            int val;
            cin >> val;
            obj->pushMiddle(val);
        }
        else if (op == "pushBack")
        {
            int val;
            cin >> val;
            obj->pushBack(val);
        }
        else if (op == "popFront")
        {
            cout << obj->popFront() << '\n';
        }
        else if (op == "popMiddle")
        {
            cout << obj->popMiddle() << '\n';
        }
        else if (op == "popBack")
        {
            cout << obj->popBack() << '\n';
        }
    }
    return 0;
}