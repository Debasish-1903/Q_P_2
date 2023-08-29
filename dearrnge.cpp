/*
Dearrange

Time-Limit: 2 sec Score: 1.00/100
Difficulty :** 
 Memory: 256 MB Accepted Submissions: 100
Description

You are given an array A of n integers. You can perform as many swap operations as you want. In a swap operation you can swap the elements at any two positions. 

Define score as number of indices i such that after all the operations, Ai is different from the original value of Ai. Print the maximum score possible.


Input Format

First line of input contains T, number of test cases.

First line of each test case contains n.

Second line contains n integers, ith integer is Ai .

 


Output Format

For each testcase print the maximum score possible in a new line.
score is no. of elements are not in same place 
for ex: 1 1 1 1 1 1 3 3 4 4 ans=8...<n-(6-4) .. here n=10


Constraints

T ≤ 10

1 ≤ n ≤ 105

1 ≤ Ai ≤ 106


Sample Input 1

1

3

1 2 3


Sample Output 1

3*/


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


bool cmp(pair<ll,ll>&a,pair<ll,ll>&b){
    
    return a.s>b.s;
    
    
}
void solve(){

ll n;
cin>>n;
unordered_map<ll,ll>mp;
//vector<pair<ll,ll>>arr(0);
for(ll i=0;i<n;i++){
    
    ll x;
    cin>>x;
    if(mp.find(x)==mp.end()){
        mp[x]=1;
    }else{
        mp[x]++;
    }
}

ll mxcnt=0;
for(auto& it:mp){
    mxcnt=max(mxcnt,it.s);
   
}

//sort(arr.begin(),arr.end(),cmp);

//cout<<mxcnt<<nl;

if(mxcnt<=n/2){cout<<n<<nl;}
else{
    ll x=n-mxcnt;
    ll ans=mxcnt-x;
    ans=n-ans;
    
    cout<<ans<<nl;
    
    
}

}



signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
    int _t; cin>>_t;while(_t--)
		solve();
	
	
	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	
	
	
	
}
