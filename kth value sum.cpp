/*Kth Sum Value

Time-Limit: 3 sec Score: 75.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

Given two arrays A of size N and B of size M and an integer K. Create a new array C of size N*M consisting of A[i]+B[j] for 1≤i≤N, 1≤j≤M. Find the Kth smallest element in the array C.


Input Format

The first line contains T, the number of test cases (1<=T<=10000).

The first line contains 3 space-separated integer N, M, K where 1<=N<=10^6, 1<=M<=10^6, 1<=K<=N*M.

Next line contains N space-separated integers (0<=Ai<=1e4).

Next line contains M space-separated integers (0<=Bi<=1e4).

Sum of min(N, M) across all test cases<=10^5.


Output Format

For each test case print the Kth smallest element in the array C.


Sample Input 1

1
3 3 6
1 2 3
4 5 6

Sample Output 1

7

Note

Array C -> [1+4,1+5,1+6,2+4,2+5,2+6,3+4,3+5,3+6] -> [5,6,7,6,7,8,7,8,9]
Array C after sorting - [5,6,6,7,7,7,8,8,9]
6th element is 7.*/

/*
We can use binary search on the possible sums between A and B. For a given value in A, you can find the possible solutions in B for a sum, say X i.e. 
A
[
i
]
+
B
[
j
]
≤
X
.


If the count for values with sum 
X
≥
K
, then we can divide the array into two parts and perform binary search on one part. Similarly, we can do this if 
c
o
u
n
t
≤
K
.


Let’s say 
N
≤
M
(swap the arrays if this is not the case). We are doing this to reduce the time complexity. We would be performing binary search on the possible sum of the K-th element in the new array, 
A
i
+
B
i
. Sort both the arrays and take the left pointer as L, the smallest sum possible i.e. A[0] + B[0], and the right pointer as R, the largest sum possible i.e. 
A
[
N
−
1
]
+
B
[
M
−
1
]
. We take 
m
i
d
=
L
+
R
2
.

We would traverse through the first array (with size N) and find the count of numbers such that its sum with 
A
i
 is ≤ mid. If the count of such numbers is 
≥
K
, that can be a possible answer and we continue binary search from 
L
 to 
R
=
m
i
d
−
1
. Otherwise, we need to increase the sum of numbers and hence we perform binary search from 
L
=
m
i
d
+
1
 to 
R
.

Remember that you must iterate in the check function over the smaller array otherwise you will get TLE.So try to find the array which is smaller and do the iteration over it and apply the upper bound over the larger function.

Condition is given as min(n,m) over all test cases doesnt exceed 
10
5
 so we must take the hint to take the smaller array as the iterating version.

Time Complexity per test case: 
O
(
N
×
l
o
g
2
M
×
l
o
g
2
(
m
a
x
(
A
i
+
B
i
)
−
m
i
n
(
A
i
+
B
i
)
)
 where 
N
≤
M

*/


//we need to find (the no of element <=x)>=k  // here acutally x is middle we need to find this suitable middle 
// actually checking this mid is actually a monotone function 

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

	ll n,m,k;
vector<int>arr,brr;

ll check(ll x){
    
    ll cnt=0;
   for(int i=0;i<n;i++){
       cnt+=upper_bound(brr.begin(),brr.end(),x-arr[i])-brr.begin();
     
   }
   
   return cnt>=k;
    
}





void solve(){
	

	
	cin>>n>>m>>k;
	
	arr.resize(n);
	brr.resize(m);
	
	for(int i=0;i<n;i++){
	    cin>>arr[i];
	}
	
		for(int i=0;i<m;i++){
	    cin>>brr[i];
	}
	
	
	if(n>m){
	    swap(n,m);
	    swap(arr,brr);
	}
	
	sort(arr.begin(),arr.end());
	sort(brr.begin(),brr.end());
	
	ll low=arr[0]+brr[0];
	ll high=arr.back()+brr.back();
	ll ans=-1;
	
	
	while(low<=high){
	    
	    ll mid=low+(high-low)/2;
	    
	    if(check(mid)){
	        
	        
	        // 0's followed by 1's
	        
	        ans=mid;
	        high=mid-1;
	        
	    }else{
	        low=mid+1;
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