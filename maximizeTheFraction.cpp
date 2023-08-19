/*

Maximise the fraction

Time-Limit: 4 sec Score: 1.00/100
Difficulty : ***
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

Given two arrays A and B of size N and an integer K. You have to select K indexes i1,i2,i3....iK such that 

(A[i1]+A[i2]+A[i3]+……+A[iK]) / (B[i1]+B[i2]+B[i3]+……+B[iK]) is maximum.


Input Format

The first line contains T, the number of test cases (1<=T<=10000).

The first line contains an integer N, K where 1<=N<=10^4, 1<=K<=N.

Next line contains N space-separated integers (1<=Ai<=1e4).

Next line contains N space-separated integers (1<=Bi<=1e4).

Sum of N across all test cases<=10^5.


Output Format

For each test case print the maximum possible value of (A[i1]+A[i2]+A[i3]+……+A[iK]) / (B[i1]+B[i2]+B[i3]+……+B[iK]). You have to print the result round off to 6 decimal places.


Sample Input 1

3
3 2
10 9 7
3 5 4
8 3
4 4 2 1 5 3 2 5
2 2 2 5 3 5 2 3
1 1
1 
1

Sample Output 1

2.428571
1.857143
1.000000

Note

1st test case:
Select index → [1,3], result = 17/7*/



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






void solve(){
	
	ll n,k;
	cin>>n>>k;
	
	ld arr[n],brr[n];
	ld sum=0;
	for(ll i=0;i<n;i++){
	    
	    cin>>arr[i];
	    sum+=arr[i];
	}
	for(ll i=0;i<n;i++){
	    
	    cin>>brr[i];
	}
	
	ld low=0;
	ld high=sum;
	ld ans;
	ld mid;
	
	while(abs(low-high)>1e-9){   //min difference between low and high should be min double which can exist for precision 6 for safty we use 1e-9 instead of 1e-7
	    
	    mid=(low+high)/2.0;
	    priority_queue<ld,vector<ld>,greater<ld>>pq;
	    
	    for(int i=0;i<n;i++){
	        
	        pq.push(arr[i]-mid*brr[i]);
	        
	        if(pq.size()>k)pq.pop();
	    }
	    
	    
	    ld s=0.0;
	    while(pq.size()){
	        
	        s+=pq.top();
	        pq.pop();
	    }
	    
	    if(s>=0.0){
	        
	        ans=mid;
	        low=mid;
	    }else{
	        
	        high=mid;
	    }
	    
	    
	}
	
	cout<<fixed<<setprecision(6)<<ans<<nl;
	
	
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	int _t; cin>>_t;while(_t--)
		solve();
	
	
	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	
	
	
	
}