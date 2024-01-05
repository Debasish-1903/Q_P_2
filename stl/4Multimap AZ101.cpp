/*Multimap AZ101

Time-Limit: 1 sec Score: 100.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Description

You are given Q queries and have to perform the following operations:

add x y - add student name X (string) for marks y (integer). If it already exists, add a new entry.
erase x - erase the first current entry of student with name x
eraseall x - erase all entries of student with name x
print x - print the first entry of marks of student with name x, if entry is not there for x, print 0.

Input Format

The first line of the input contains one integer T - the number of test cases. Then T test cases follow.

The first line of each test case contains one integer Q - the number of queries.

Each of the next Q ines contains queries.


Output Format

For each test case, print the required queries.


Constraints

1≤ T ≤ 105

1≤ Q ≤ 105

1≤ X ≤ 106

It is guaranteed that the sum of Q over all test cases does not exceed 105.


Sample Input 1

1
9
add alice 24
add bob 21
add alice 23
add alice 22
print alice
erase alice
print alice
eraseall alice
print alice

Sample Output 1

24
23
0

Note

Map becomes: [alice: 24]
Map becomes: [alice: 24, bob: 21]
Map becomes: [alice: 24, bob: 21, alice: 23]
Map becomes: [alice: 24, bob: 21, alice: 23, alice: 22]
alice: 24
Map becomes: [bob: 21, alice: 23, alice: 22] (since first entry of alice is removed)
alice: 23
Map becomes: [bob: 21]
key alice doesn't exist, hence alice: 0*/

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


multimap<string,int>mp;

ll q;
cin>>q;

while(q--){
    
    string x,z;
    ll y;
    
    cin>>z;
    if(z=="add"){
        
        cin>>x>>y;
        
      mp.insert(make_pair(x,y));
    }
    
    else if(z=="print"){
        
        cin>>x;
        
        auto it = mp.find(x);
        if (it != mp.end()) cout << it->s<< nl;  // or cout<<(*it).s<<nl;
        else cout<<0<<nl;
        
    }else if(z=="erase"){
        
        cin>>x;
            auto it = mp.find(x);
            if (it != mp.end()) mp.erase(it);
        
    }else if(z=="eraseall"){
        
        cin>>x;
        mp.erase(x);
        
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