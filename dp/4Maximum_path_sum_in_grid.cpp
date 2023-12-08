/*Maximum path sum in grid

Time-Limit: 1 sec Score: 0.00/100
Difficulty : *
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

Given a grid of size n*m with non-negative integers, you need to find the maximum path sum from (1, 1) to (n, m). You are allowed to move from (x, y) to (x+1, y) and (x, y) to (x, y+1).


Input Format

The first line of the input contains one integer t - the number of test cases. Then t test cases follow.

The first line of each test case contains two space-separated integers n, m - the size of the grid.

Each of the following n lines contains m space-separated integers, aij - the number at that cell.


Output Format

For each test case, print the maximum path sum.


Constraints

1 ≤ t ≤ 105

1 ≤ n, m ≤ 103

0 ≤ aij ≤ 107

It is guaranteed that the sum of n*m over all test cases does not exceed 106.


Sample Input 1

3
2 3
3 2 1
4 1 1
3 3
1 2 1
3 5 1
4 1 1
2 2
1 2
3 4

Sample Output 1

9
11
8

Note

For the first test case, path 3 → 4 → 1 → 1 maximises the sum.

For the second test case, path 1 → 2 → 5 → 1 → 1 and 1 → 3 → 4 → 1 → 1 maximises the sum.

For the third test case, path 1 → 3 → 4 maximises the sum.*/




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

ll n,m;

ll arr[1010][1010];

ll dp[1010][1010];

bool done[1010][1010];


ll rec(ll x,ll y){//best route length(longest)ending at(x,y)position from [{0,0}......{x,y}] 
	
	
	//pruning
	
	if(x<0||y<0)return -1e9;
	
	// base case
	
	if(x ==0&& y ==0){
        return arr[0][0];
    }
	
	//cache check
	
	if(done[x][y])return dp[x][y];
	
	
	//compute 
	
	ll ans=-1e9;
	
	// if(x!=0){
	// 	ans=max(ans,rec(x-1,y)+arr[x][y]);
	// }
	// if(y!=0){
		
	// 		ans=max(ans,rec(x,y-1)+arr[x][y]);
	// }
	
	
	ans=max(rec(x-1,y)+arr[x][y],rec(x,y-1)+arr[x][y]); // it is short cut as if rec(0,1) is called then in pruning section it take -1e9 and ans=max(-INF,rec(0,(1-1=0))+arr[x][y])= rec(0,(1-1=0))+arr[x][y],same will be happend for if(1...n,0) is called then 
	// ans=max(.......,-inf)=.......
	
	done[x][y]=true;
	return dp[x][y]=ans;
	
	//save and return
	
	
}


void solve(){
	
	cin>>n>>m;
	
	
	for(int i=0;i<n;i++){
		
		for(int j=0;j<m;j++){
			
			cin>>arr[i][j];
			
			done[i][j]=false;
		}
	}
	
	// ll best=-1e9;
	// for(int i=0;i<n;i++){
		
	// 	for(int j=0;j<m;j++){
			
	// 		best=max(best,rec(i,j));
	// 	}
	// }
	
	// cout<<best<<nl;
	
	
	//*** rec(n-1,m-1)---> means the best path  sum emding at n-1,m-1.. eventually this only is asked in the question 
	// so we don't need to write the // ll best=-1e9;
	// for(int i=0;i<n;i++){
		
	// 	for(int j=0;j<m;j++){
			
	// 		best=max(best,rec(i,j));
	// 	}
	// }
	
	// cout<<best<<nl; for checking all the cell   ******// --- understand the meaning of rec(x,y)properly
	
	
	
	cout<<rec(n-1,m-1)<<nl;
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	int _t; cin>>_t;while(_t--)
		solve();
	
	
	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	
	
	
	
}