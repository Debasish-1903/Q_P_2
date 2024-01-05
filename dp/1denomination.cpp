

//denomination //

// we were given some integers, in a denomination , we need to make a target number=s using these 
//numbers using each no.s any no of time;



//sequence of solving dp problem


/* step1: which form? form1 or 2 or 3 or 4 ?
step2: state formation ==defination  of dp  rec(level,x){  // can we make x ? // count the total no of possible way to make // find the min}
step3: transition  --> or/and  || summ +  || min/max

step4: time complexity: O(no of states(1+transistion per state))==O(#s(1+#T)) ==O(E+V) of dag(directed acyclick graph)


*/



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


int n;
int den[1005];

bool dp[1005][1005];
bool done[1005][1005]; // visited array

bool rec(int level,int x){
	
	
	//pruning 
	
	 if(x<0)return false;
	//base case
	if(level==n){
		
		if(x==0)return true;
		else return false;
	}
	
	
	// cache check
	
	if(done[level][x])return dp[level][x];
	
	
	// recursive case
	bool ans=rec(level,x-den[level])||rec(level+1,x);
	
	// save and return
	
	
	dp[level][x]=ans;
	done[level][x]=true;
	
	return ans;
	
	
}

void solve(){
	
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>den[i];
	}
	
	int target_sum;
	cin>>target_sum;
	
	for(int i=0;i<n;i++){
		
		for(int j=0;j<=target_sum;j++){
			
			done[i][j]=false;
		}
	}
	
	
	
	cout<<rec(0,target_sum)<<nl;
	//herer rec(level,x)//
	
	
	
	
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	// int _t; cin>>_t;while(_t--)
		solve();
	
	
	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	
	
	
	
}