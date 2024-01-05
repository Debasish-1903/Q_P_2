


/*Count LIS

Time-Limit: 2 sec Score: 0.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

Given an integer array 
a
r
r
 of length 
n
, output the number of longest increasing subsequences.

Notice that the sequence has to be strictly increasing.


Input Format

First line contains 
T
 - the number of test cases.
First line of each test case contains 
n
 - the length of the array 
a
r
r
.
Second line of each test case contains array 
a
r
r
.


Output Format

For each test case, output the number of longest increasing subsequences in a newline.


Constraints

1
≤
T
≤
100

1
≤
n
≤
1000

−
10
6
≤
a
r
r
[
i
]
≤
10
6

Sample Input 1

4
5
1 2 2 3 6
5
1 3 5 4 7
6
1 1 1 1 1 1
4
3 1 1 2

Sample Output 1

2
2
6
2

*//*WRONG ANS*/ // THIS CODE IS GIVING WRONG ANS SO PLS DON'T FOLLOW IT 

/*#include<bits/stdc++.h>
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



ll n;
ll arr[1010];

ll dp[1010][100100];
bool done[1010][100100];

ll rec(ll level,ll last_taken){ // form 2 : best increasing lenght(max length) from [0...level];
	
	//pruning
	
	// basecase 
	if(level>n)return 0;
	
	// cache check 
	if(done[level][last_taken])return dp[level][last_taken];
	
	// compute 
	
	ll ans=1;
	ans=max(ans,rec(level+1,last_taken));// don't take
	if(arr[level]>arr[last_taken]){
		
		ans=max(ans,1+rec(level+1,level)); //take
	}
	
	
	
	
	// save and return
	
	done[level][last_taken]=1;
	return dp[level][last_taken]=ans;
	
	
	
	
	
	
}

void solve(){
	cin>>n;

for(ll i=0;i<n;i++){
	
	cin>>arr[i];
	
}

	
memset(done,0,sizeof(done));


ll temp;
unordered_map<ll,ll>mp;
for(ll i=0;i<n;i++){
	
	temp=rec(i,i);
	mp[temp]++;
	
	
	
}
ll cnt=0;
for(auto it:mp){
	cnt=max(cnt,it.s);
	
}

	//cout<<"rec(i,i)="<<temp<<nl;
	cout<<cnt<<nl;
	
	

	
	
	
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	 int _t; cin>>_t;while(_t--)
		solve();
	
	
	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	
	
	
	
} */


/*WRONG ANS*/ //THIS CODE IS GIVING WRONG ANS SO FOLLOW BELOW ONE //




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




 ll n;
  ll arr[1010];
ll cnt[1010];
ll dp[1010];
bool done[1010];

ll rec(ll level){
	
	// base case
	if(cnt[level]==1)return 1;
	
	
	// cache check;
	
	if(done[level])return dp[level];
	// compute
	
	ll ans=0;
	for(ll i=level-1;i>=0;i--){
		
		if(arr[i]<arr[level]&&cnt[i]==cnt[level]-1){
			
			ans+=rec(i);
		}
	} 
	
	
	// save and return
	done[level]=true;
	return dp[level]=ans;
	
	
	
}





void solve(){
	
	cin>>n;
	for(ll i=0;i<n;i++){
		
		cin>>arr[i];
	}
	
	
	
	
	std::vector<ll>ans;
	
	memset(done,0,sizeof(done));
	
	for(ll i=0;i<n;i++){
		
		if(ans.empty()||ans.back()<arr[i]){
			ans.push_back(arr[i]);
			cnt[i]=ans.size();
			
	}else{
		
		auto it=lower_bound(ans.begin(),ans.end(),arr[i]);
		*it=arr[i];
		cnt[i]=it-ans.begin()+1;
		
	}
	}
	
	ll result=0;
	for(ll i=0;i<n;i++){
		
		if(cnt[i]==ans.size()){
			
			result+=rec(i);
		}
	}
	
	
	cout<<result<<nl;
	
	
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	int _t; cin>>_t;while(_t--)
		solve();
	
	
	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	
	
	
	
}