/*The Missing Number AZ101

Time-Limit: 1 sec Score: 100.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Description

You are given an array A. One random element is removed from A to form array B and one random element is removed from B to form array C. You have to find the missing element in B and the missing element in C.


Input Format

The first line of the input contains one integer T - the number of test cases. Then T test cases follow.

The first line of each test case contains one integer N - the length of the array. 

The second line of each test case contains N space-separated integers - array A.

The third line of each test case contains (N-1) space-separated integers - array B.

The fourth line of each test case contains (N-2) space-separated integers - array C.


Output Format

For each test case, print the missing element in B and the missing element in C.


Constraints

1 ≤ T ≤ 106

2 ≤ N ≤ 106

It is guaranteed that the sum of N over all the test cases does not exceed 106.

0 ≤ Ai ≤ 109


Sample Input 1

3
4
1 3 5 2
5 1 3
5 1
5
1 3 5 1 0
3 1 1 5
1 1 5
3
1 2 3
3 1
1

Sample Output 1

2 3
0 3
2 3   */

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
#define v vector<long long int>
#define vp vector<pair<int,int>>
#define vvl vector<vector<long long int>>
#define rep(n) for(int i=0 ; i<n ; i++)
#define rei(i) for(int i=n ; i>0 ; i--)
#define prio priority_queue
#define np next_permutation
#define N 200100

#define yes "YES"
#define no "NO"


void solve(){

ll n ;
cin>>n;

multiset<ll>a,b,c;

for(ll i=0;i<n;i++){
    
    ll x;
    cin>>x;
    a.insert(x);
    
}

for(ll i=0;i<n-1;i++){
    
    ll x;
    cin>>x;
    b.insert(x);
    
}
for(ll i=0;i<n-2;i++){
    
    ll x;
    cin>>x;
    c.insert(x);
    
}


for(auto it:a){
    
    if(!b.empty()){
        
        if(b.find(it)==b.end()){
            
            cout<<it<<" ";
        }
        
        
    }
    
}

for(auto it:b){
    
    if(!c.empty()){
        
        if(c.find(it)==c.end()){
            
            cout<<it<<nl;
        }
        
        
    }
    
}

	
	
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int _t; cin>>_t;while(_t--)
		solve();
	
	
	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	

	
	
	
}