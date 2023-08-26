/*Destroying intervals

Time-Limit: 1 sec Score: 100.00/100
Difficulty :*** 
 Memory: 256 MB Accepted Submissions: 100
Description

There are n intervals. The ith interval covers range [li,ri]  including points l and r.

You can destroy intervals by choosing some points. Suppose a point x is chosen, then any interval that covers x will be destroyed.

Find the minimum number of points to be selected to destroy all intervals.

 

 


Input Format

First line of input contains T, number of test cases.

First line of each test case contains n, the number of intervals.

Each of n next lines contain two integers , li and ri .

 


Output Format

For each testcase print a single integer, minimum points required.


Constraints

T ≤ 20
0 ≤ n ≤ 105
0 ≤ li ≤ ri ≤ 109


Sample Input 1

1
3
1 4
2 6
7 10

Sample Output 1

2

Note

You can choose point 3 which destroys interval 1 & 2, and point 7 to destroy interval 3.*/


//same as job scheduling problem only diff is in job scheduling the check func consist <= but here contains only <

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


struct intrvl{
    
    ll l,r;
};

bool cmp(intrvl a, intrvl b){
    
    return a.r<b.r;
    
}



void solve(){
  
ll n;
cin>>n;


//vector<intrvl>arr(n); or

intrvl arr[n];

for(ll i=0;i<n;i++){
    
   cin>>arr[i].l>>arr[i].r;
  
}


sort(arr,arr+n,cmp);

ll cnt=0;

ll prev_end=INT_MIN;

for(ll i=0;i<n;i++){
    
    if(prev_end<arr[i].l){
        cnt++;
      prev_end=arr[i].r;  
        
    }
    
    
    
}

cout<<cnt<<nl;

}



signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
    int _t; cin>>_t;while(_t--)
		solve();
	
	
	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	
	
	
	
}
