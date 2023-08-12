/*You are given an array A, where each ith index represents an elevation on that index. The width of each bar is 1. You have to compute how much water it is able to trap after raining.


Input Format

The first line of the input contains one integer T - the number of test cases. Then T test cases follow.
The first line of each test case contains one integer N - the length of the array. 
The second line of each test case contains N space-separated integers, where Ai denotes the height of the ith bar.


Output Format

For each test case, you have to print how much water it is able to trap after raining.


Constraints

1 ≤ T ≤ 100
1 ≤ N ≤ 105
0 ≤ Ai ≤ 105


Sample Input 1

3
3
3 0 2
5
2 0 0 4 3
5
1 2 3 1 5

Sample Output 1

2
4
2*/



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
    
    ll n;
    cin>>n;
    
    ll arr[n];
    for(ll i=0;i<n;i++){
        
        cin>>arr[i];
    }
    
    stack<ll>st;
    
    ll ans=0;
    
    for(ll i=0;i<n;i++){
        
        
        
        while(!st.empty()&&arr[st.top()]<arr[i]){
            

            ll pop_hieght=arr[st.top()];
            st.pop();
            
            
            
            if(st.empty())break;
            
            
            ll dist=i-st.top()-1;
           
           
            ll min_hieght=min(arr[st.top()],arr[i])-pop_hieght; 
            
            
            ans+=dist*min_hieght;
            
            
        }
        
        
        st.push(i);
        
        
        
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