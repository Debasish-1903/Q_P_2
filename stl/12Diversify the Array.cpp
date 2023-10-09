
/*

Time-Limit: 2 sec Score: 1.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

You have given an array A. The diversity of the array A is defined as the number of pairs i, j, i < j such that Ai ≠ Aj.
You want to maximize the diversity of the array. For that, you are allowed to make at most K operations on it, in any of which, you can select a particular element and change its value to any integer in the range 1 to 109, both inclusive.
Find out the maximum diversity of the array that you can obtain.


Input Format

The first line will contain T, number of test cases. Then the test cases follow.
The first line of each test case contains two integers N, K. where N denotes the length of array A.
The next line of each test case contains N space-separated integers, the i-th of which denotes Ai.


Output Format

For each test case, output in a single line, the answer corresponding to the test case, which should be an integer denoting the maximum possible diversity.


Constraints

1 ≤ T ≤ 20
0 ≤ K ≤ 109
2 ≤ N ≤ 105
1 ≤ Ai ≤ 109


Sample Input 1

3
3 10
1 2 3
4 2
1 1 2 2
6 2
2 3 3 2 4 4


Sample Output 1

3
6
14


Note

Explanation 1:
Every element in the array is different. The diversity is 6, which is the maximum possible.

Explanation 2:
Change the array to A = [1, 3, 2, 5]. Here we only need to change elements at 2nd and 4th positions. Now all elements are different.
The maximum diversity is 6.

Explanation 3:
Change the array to A = [5, 6, 2, 3, 4, 4]. Here we change the elements at positions 1 and 2. The maximum diversity is 14.





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




 


void solve(){
	
	ll n,k;
	cin>>n>>k;
//	cout<<n<<k<<nl;
	
	ll temp=n;
	priority_queue<pair<ll,ll>>pq;
	
	unordered_map<ll,ll>mp;
	
	while(temp--){
	    
	    ll x;
	    cin>>x;
	    
	    mp[x]++;
	    
	    
	}
	
	
	//cout<<"n is"<<n<<nl;
	
	ll ans=n*(n-1)/2;
	
//	cout<<"ans is"<<ans<<nl;
	
	
	for(auto it:mp){
	    
	    if(it.s>1){
	        
	        pq.push({it.s,it.f});
	        
	        ans-=(((it.s)*(it.s-1))/2);
	        
	    }
	    
	    
	}
	
	
	while(k--){
	    
	   if(pq.empty())break;
	   
	 //  else{
	       
	      auto it=pq.top();
	      pq.pop();
	      ans+=it.f-1;
	      
	      it.f--;
	      if(it.f>1)pq.push(it);
	    
	 //  }
	    
	    
	    
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
