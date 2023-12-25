/*22Merge_Elements_1

Time-Limit: 1 sec Score: 0.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

You are given N elements, in an array A. You can take any 2 consecutive elements a and b and merge them. On merging you get a single element with value (a+b)%100 and this process costs you a*b. After merging you will place this element in place of those 2 elements.
 

If the sequence is [A1, A2, A3, A4] and you merge A2 and A3, you incur a cost of A2*A3 and the array becomes [A1, (A2+A3)%100, A4].
 

Find the Minimum cost to merge all the elements into a single element.


Input Format

The first line contains a single element N. 1 <= N <= 500

The Second line contains N space separated integers, the Ai for the Array.  0 <= Ai < 100


Output Format

Output a single integer, the Minimum cost to Merge all the elements.


Sample Input 1

3
1 2 4 

Sample Output 1

14

Note

If you merge elements 1 and 2 first, You get [3,4] and pay a cost of 1*2=2. Then if you merge 3 and 3, You get [7] and pay a cost of 3*4=12.

Total cost incurred = 2+12 = 14.

If you merge elements 2 and 4 first, You get [1,6] and pay a cost of 24=8. Then if you merge 1 and 6, You get [7] and pay a cost of 16=6.

Total cost incurred =  8+6 = 14.

So the best you can do is at cost 14.  */



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
vector<ll>arr;
ll dp[510][510];

ll rec(ll l,ll r){
	
	// pruning
	
	if(n==1)return arr[0]%100;
	
	if(n==2)return (arr[0]*arr[1])%100;
	
	// base case 
	if(l==r)return 0;
	
	// cache check 
	
	if(dp[l][r]!=-1)return dp[l][r]%100;
	ll add_tot=0;
	for(ll mid=l;mid<=r;mid++){
		
		add_tot+=arr[mid]%100;
	}
	
	
	
	// compute
	ll ans=1e9;
	ll sum=0;
	
	for(ll mid=l;mid<r;mid++){
		
		sum+=arr[mid]%100;
		
		ans=min(ans,rec(l,mid)+rec(mid+1,r)+(sum%100*((add_tot-sum)%100)));
		
	}
	



// save and return 
	
	
	
	return dp[l][r]=ans%100;
	
	
	
	
	
}


 

void solve(){
	
	cin>>n;
	
	arr.resize(n);
	arr.clear();
	
	//add_tot=0;
	for(ll i=0;i<n;i++){
		
		cin>>arr[i];
		// add_tot+=arr[i]%100;
		// if(i==0)sum[i]=arr[i];
		// else{
		// 	sum[i]=(sum[i-1]+arr[i])%100;
		}
		
		
	
	memset(dp,-1,sizeof(dp));
	
	
	cout<<rec(0,n-1)<<nl;
	
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	//int _t; cin>>_t;while(_t--)
		solve();
	
	
	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	
	
	
	
}