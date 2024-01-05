/*Minimal String AZ101

Time-Limit: 1 sec Score: 1.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Description

You are given a string S along with 2 empty strings T and U. You can make the following two moves: pop first character of S and append it to T or pop last character of T and append it to U.

You need to make the string U lexicographically minimum such that string S and T are empty.


Input Format

The first line of the input contains one integer T - the number of test cases. Then T test cases follow.

The first line of each test contains a string S.


Output Format

For each test case, print the lexicographically minimum possible string U.


Constraints

1≤ T ≤ 106

1≤ |S| ≤ 106

It is guaranteed that the sum of |S| over all test cases does not exceed 106.


Sample Input 1

3
bdab
sss
gtddb

Sample Output 1

abdb
sss
bddtg

Note

For the first test case, S = bdab

S = dab, T = b, U = 
S = ab, T = bd, U = 
S = b, T = bda, U = 
S = b, T = bd, U = a
S = , T = bd, U = ab
S = , T = b, U = abd
S = , T = , U = abdb
For the second test case, S = sss

S = ss, T = s, U = 
S = s, T = ss, U = 
S = s, T = s, U = s
S = , T = ss, U = s
S = , T = s, U = ss
S = , T = , U = sss
For the third test case, S = gtddb

S = tddb, T = g, U = 
S = ddb, T = gt, U = 
S = db, T = gtd, U = 
S = b, T = gtdd, U = 
S = , T = gtddb, U = 
S = , T = gtdd, U = b
S = , T = gtd, U = bd
S = , T = gt, U = bdd
S = , T = g, U = bddt
S = , T =, U = bddtg */



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




 /*ll add(ll a,ll b){
	
	ll ans=(a+b)%mod;
	if(ans<0) ans+=mod;
	
	return ans;
}

 ll sub(ll a,ll b){
	
	ll ans=(a-b)%mod;
	if(ans<0) ans+=mod;
	
	return ans;
}

ll mul(ll a,ll b){
	
	ll ans=(a*b)%mod;
	if(ans<0) ans+=mod;
	
	return ans;
}*/


void solve(){


string str;
stack<char>t;
string u="";

cin>>str;

ll n=str.size();

vector<char>arr(n);

arr[n-1]=str[n-1];

for(ll i=n-2;i>=0;i--){
   if(str[i]<arr[i+1]) arr[i]=str[i];
   else{
       arr[i]=arr[i+1];
   }
    
}


for(ll i=0;i<n;i++){
    
    if(i==0)t.push(str[i]);
    
    else {
        
        while(!t.empty()&&t.top()<=arr[i]){
            
            u+=t.top();
            t.pop();
        
        
          }
        t.push(str[i]);
    }
}

while(!t.empty()){
    
    u+=t.top();
    t.pop();
}

cout<<u<<nl;	
	
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	 int _t; cin>>_t;while(_t--)
		solve();
	
	
	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	
	
	
	
}