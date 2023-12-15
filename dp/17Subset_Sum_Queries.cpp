/*Subset Sum Queries

Time-Limit: 1 sec Score: 1.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

Given an array of size 
N
, and 
Q
 queries, for each query, you need to get the indices of the elements of the array whose subset-sum is equal to the queried sum 
s
u
m
i
, if possible, else return 
−
1
.


Input Format

Complete the Function subset_queries( vector &arr, vector &queries ) that takes vector 
a
 and 
q
u
e
r
i
e
s
 vector as input.


Output Format

Return a vector < vector < int > > having 
0
-based indices of the elements of the array whose subset-sum is equal to the queried sum 
s
u
m
i
 for each 
i
t
h
 query, if possible, else return vector { 
−
1
 }.


Constraints

1
≤
N
≤
100
 , size of vector < int > arr
1
≤
Q
≤
10
5
 , size of vector < int > queries
1
≤
a
r
r
[
i
]
≤
10
5

1
≤
s
u
m
i
≤
10
5

Sample Input 1

arr[] = { 1, 2, 3, 4, 5 }
queries[]= { 7, 16, 3 }

Sample Output 1

{ {1, 4}, {-1}, {2} } */

#include <bits/stdc++.h>
using namespace std;

#define ll int64_t
int dp[105][100100];
vector<int>curr;

int rec(int level,vector<int>&arr,int left){
    int n=arr.size();
    if(left<0)return 0;
    if(level==n){
        if(left==0)return 1;
        else return 0;
    }
    //int ans=0;
    if(dp[level][left]!=-1)return dp[level][left];
    int ans=rec(level+1,arr,left)||rec(level+1,arr,left-arr[level]);
    dp[level][left]=ans;
    return ans;
}



void indicies(int level,vector<int>&arr,int left){
    
    if(level==arr.size())return;
    
    if(rec(level+1,arr,left)){
        //curr.push_back(level);
        indicies(level+1,arr,left);
    }else if(rec(level+1,arr,left-arr[level])==1){
        
        curr.push_back(level);
        
        indicies(level+1,arr,left-arr[level]);
        
    }
    
    
    
    
}

vector<vector<int>> subset_queries(vector<int> &arr, vector<int> &queries) {
    memset(dp,-1,sizeof(dp));
   int x=queries.size();
   int n=arr.size();
   vector<vector<int>>ans;
   
   for(auto it:queries){
       curr.clear();
       
       if(rec(0,arr,it)==1){
           
           indicies(0,arr,it);
           ans.push_back(curr);
       }
       else{
           ans.push_back({-1});
       }
       
   }
   
   return ans;
   }
   

void solve() {
    int N, Q;
    cin >> N >> Q;
    vector<int> arr(N);
    for (int i = 0; i < N; i++)cin >> arr[i];
    vector<int> queries(Q);
    for (int i = 0; i < Q; i++)cin >> queries[i];
    auto ans = subset_queries(arr, queries);

    // checker.
    if (ans.size() != Q) {
        cout << 101 << endl;
        return;
    }
    for (int i = 0; i < Q; i++) {
        auto x = ans[i];
        if (x.size() == 0) {
            cout << 101 << endl;
            continue;
        }
        if (x.size() == 1 && x[0] == -1) {
            cout << -1 << endl;
            continue;
        }
        ll sum = 0, p = -10;
        for (auto y : x) {
            if (y < 0 || y >= N || p >= y ) { // valid 0-indexed.
                sum = -1111;
                break;
            }
            p = y;
            sum += arr[y];
        }
        if (sum == queries[i]) {
            cout << 1 << endl;
        }
        else cout << 101 << endl;
    }
}
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

#ifdef Mastermind_
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    // int i = 1;
    // cin >> t;
    while (t--) {
        // cout << "Case #" << i << ": ";
        solve();
        // i++;
    }
    return 0;
}