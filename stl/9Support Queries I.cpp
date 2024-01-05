/*Support Queries I

Time-Limit: 1 sec Score: 100.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

Design a Data Structure which can support the following queries:

1 x: Add x in structure
2 x: Remove x from the structure if present in the structure. If x doesn't present in the structure, do nothing. If there are multiple occurrences of x, delete only one occurrence of x.
3 ?: Print the minimum number present in the structure. If the structure is empty, print -1.
4 ?: Print the maximum number present in the structure. If the structure is empty, print -1.
5 ?: Print the sum of all numbers present in the structure. If the structure is empty, print 0.

Initially, the structure is empty.


Input Format

The first line of input contains Q - the number of queries.
Next, Q lines contain queries of the format specified in the statement.


Output Format

For queries of type 3, 4 and 5, print the answer in a new line.


Constraints

1 ≤ Q ≤ 105
0 ≤ x ≤ 109


Sample Input 1

18

1 5

1 4

1 4

3 ?

4 ?

5 ?

2 4

3 ?

4 ?

5 ?

2 4

3 ?

4 ?

5 ?

2 5

3 ?

4 ?

5 ?


Sample Output 1

4

5

13

4

5

9

5

5

5

-1

-1

0  */


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

map<ll,ll>mp;

ll q;
cin>>q;
ll ans=0;
while(q--){
    ll a;
    cin>>a;
    
     ll x;
    if(a==1){
        
       
        cin>>x;
        
        mp[x]++;
        ans+=x;
       // cout<<"ans is :"<<ans<<nl;
        
    }else if(a==2){
        
        cin>>x;
        
        if(mp.find(x)!=mp.end()){
            
            mp[x]--;
            ans-=x;
            
            
            if(mp[x]==0)mp.erase(x);
            // cout<<"ans is :"<<ans<<nl;
        }
        
    }else if(a==3){
        char y;
        cin>>y;
        auto it =mp.begin();
        if(!mp.empty())cout<<it->f<<nl;
        else cout<<-1<<nl;
    }else if(a==4){
        char y;
        cin>>y;
        
        auto it =mp.rbegin();
        if(!mp.empty())cout<<it->f<<nl;
        else cout<<-1<<nl;
    }else if(a==5){
        char y;
        cin>>y;
        
        if(!mp.empty())cout<<ans<<nl;
        else cout<<0<<nl;
    }
    
    
}

}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	// int _t; cin>>_t;while(_t--)
		solve();
	
	
	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	
	
	
	
}