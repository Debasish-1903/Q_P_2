
/*

LRU Cache

Time-Limit: 2 sec Score: 100.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.


Input Format

Implement the LRUCache class:

LRUCache(int capacity) : Initialize the LRU cache with positive size capacity.
int get(int key) : Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) : Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.

Output Format

For every call to the get function print the value of the key if it exists else print -1.


Constraints

1 ≤ capacity ≤ 105

1 ≤ key, value ≤ 105

At most 105 calls will be made to functions get and put.


Sample Input 1

9 2
put 1 1
put 2 2
get 1
put 3 3
get 2
put 4 4
get 1
get 3
get 4

Sample Output 1

1
-1
-1
3
4

Note

The cache after every operation is:

[{1,1}]
[{1,1},{2,2}]
[{2,2},{1,1}]
[{1,1},{3,3}]
[{1,1},{3,3}]
[{3,3},{4,4}]
[{3,3},{4,4}]
[{4,4},{3,3}]
[{3,3},{4,4}]*/







#include <bits/stdc++.h>
using namespace std;
#define s second
#define f first
#define nl "\n"
#define ll long long 
class LRUCache
{


    // LRUCache(int capacity)
    // {
    //     //Complete function
        
        
        list<int>order;
        unordered_map<int,pair<int,list<int>::iterator>>cach;
        int max_size=0;
        
        void touch(int id){
            auto it=cach.find(id);
            int key=it->f;
            order.erase(it->s.s);
            order.push_front(key);
            it->s.s=order.begin();
            
        }
            
       // }
        
   // }
    
    public:
    LRUCache(int capacity){
        max_size=capacity;
        order.clear();
        cach.clear();
    }
    
    

    int get(int key)
    {
        //Complete function
        
        if(cach.find(key)==cach.end()){
            
            return -1;
            
        }
        else{
            touch(key);
            return cach[key].f;
        }
        
    }

    void put(int key, int value)
    {
        //Complete function
        
        if(cach.find(key)==cach.end()){
            
            if(cach.size()==max_size){
                int del=order.back();
                cach.erase(del);
                order.pop_back();
                
                
            }
            order.push_front(key);
        }else{
            touch(key);
        }
        cach[key]=make_pair(value,order.begin());
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int q, cap;
    cin >> q >> cap;
    LRUCache *obj = new LRUCache(cap);
    for (int i = 0; i < q; i++)
    {
        string op;
        cin >> op;
        if (op == "get")
        {
            int key;
            cin >> key;
            cout << obj->get(key) << '\n';
        }
        else
        {
            int key, val;
            cin >> key >> val;
            obj->put(key, val);
        }
    }

    return 0;
}