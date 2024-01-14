/*Maximum Sum in Grid

Time-Limit: 1 sec Score: 0.00/100
Difficulty : ***(std)
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

Given a grid of size n x m with integers, you need to find the maximum sum Subgrid.


Input Format

The first line of the input contains one integer t - the number of test cases. Then t test cases follow.
The first line of each test case contains two space-separated integers n, m - the size of the grid.
Each of the next n lines contains m space-separated integers, a[i][j] - the number at the cell (i, j).


Output Format

For each test case, print the maximum sum.


Constraints

1 ≤ t ≤ 105
1 ≤ n, m ≤ 105
-105 ≤ a[i][j] ≤ 105

It is guaranteed that the sum of n x m over all test cases does not exceed 105.


Sample Input 1

3
2 3
10 2 -1
-4 5 -1
2 2
-1 -1
-1 -1
2 2
1 2
3 4

Sample Output 1

13
-1
10

Note

For the first test case, the top left 2 x 2 subgrid, 10 + 2 - 4 + 5 = 13.

For the second test case, all cells have a maximum sum which is -1.

For the third test case, all cells are positive, maximum sum subgrid is the entire grid with sum 10.


1   */


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


// using dimenstion reduction  : if o(((min(m,n))^ 2*max(m,n)) if m<n we first fix the column
 //and we take chunks of rows to make rectangle  and make 2d problem into 1d problem and then use kadane's algo on n size array of the rowsums (a1,a2,a3...an)
 // and find the  max subgrid (now it is sub array)


ll get_best_subarray_sum(vector<ll>arr){    // finding the max sum subarray // kadane's algo
	
	ll n=arr.size();
	
	ll last=-1e18;
	ll ans=-1e18;
	
	for(ll i=0;i<n;i++){
		
		
		if(i==0){
			last=arr[i];
		}else{
			
			last=max(last+arr[i],arr[i]);
			
		}
		ans=max(ans,last);
		
	}
	
	return ans;
	
	
}




void solve(){
	
	ll n,m;
	
	cin>>n>>m;
	
	ll arr[n][m];
	
	for(ll i=0;i<n;i++){
		
		for(ll j=0;j<m;j++){
			
			
			cin>>arr[i][j];
		}
	}
	
	ll ans=-1e18;
	
	if(m<n){   // no of col is less than no of rows  
		
		for(ll c1=0;c1<m;c1++){
			vector<ll>row_sum(n,0);
			
			 for(ll c2=c1;c2<m;c2++){
			 	   
			 	   for(ll r=0;r<n;r++){
			 	   	
			 	   	row_sum[r]+=arr[r][c2];
			 	   	
			 	   }
			 	
			 	
			 	ans=max(ans,get_best_subarray_sum(row_sum));
			 	
			 }
			
		}
		
		
		
	}else{
		
		for(ll r1=0;r1<n;r1++){
			vector<ll>col_sum(m,0);
			
			for(ll r2=r1;r2<n;r2++){
				
				for(ll c=0;c<m;c++){
					
					col_sum[c]+=arr[r2][c];
					
				}
				
					ans=max(ans,get_best_subarray_sum(col_sum));
				
			}
			
		}
		
		
	}
	
	
	
	cout<<ans<<nl;
	
	
	
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	int _t; cin>>_t;while(_t--)
		solve();
	
	
	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	
	
	
	
}




