/*Fibonacci Breakdown

Time-Limit: 1 sec Score: 1.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Description

Given a number k, find the minimum number of fibonacci numbers

whose sum is equal to k. You can use any of the fibonacci numbers  

any number of times.

Fibonacci Numbers:

F(1) = 1

F(2) = 1

F(n) = F(n-1) + F(n-2) : for n>=3

 


Input Format

First line of input contains T, number of test cases.

The only line of each test case contains an integer k.

 


Output Format

For each test case output one integer: The minimum number of fibonacci numbers needed.


Constraints

T ≤ 100

1 ≤ k ≤ 109

 


Sample Input 1

1

7


Sample Output 1

2


Note

7 can be formed using 2 + 5, where 2, 5 are fibonacci numbers.*/


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
  ll fibo[50];

void solve(){
    
    ll k;
    cin>>k;
    
    
  
    
    
    int terget=49;
    
    ll ans=0;
    while(k){
        
        if(k>=fibo[terget]){
            
            k-=fibo[terget];
            
            ans++;
        }
        terget--;
        
    }
    
cout<<ans<<nl;

}



signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	
    
    fibo[1]=fibo[2]=1;
    
    
    for(ll i=3;i<50;i++){
        
        
        fibo[i]=fibo[i-1]+fibo[i-2];
    }
    
    int _t; cin>>_t;while(_t--)
		solve();
	
	
	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	
	
	
	
}
