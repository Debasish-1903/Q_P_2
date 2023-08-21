
/*
there are few questions given and their score, penalty(decay), and time taken to solve the problem is given.
in which order you need to solve the questions to gain the max score at the end

ex: score :          100 200
    delay(penalty)(
    per unit time
                 ):  20 50
    time :           5  3
    
    
    
    if we solve the questions p1-->p2 then the value we get at the end is 
       100-(5*20)+(200-(5+3)*50)=-200
       ans if we solve p2-->p1 then 
       200-(50*3)+(100-(5+3)*20)=50+(-60)=-10

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



struct prob
{
	
	ll s,d,t;
};


bool cmp(prob a,prob b){
	
	return a.d*b.t>b.d*a.t;
	
}





void solve(){
	
	
	 int n;
	 cin>>n;
	prob p[n];
	
	for(int i=0;i<n;i++){
		
		cin>>p[i].s>>p[i].d>>p[i].t;
		
	}
	
	sort(p,p+n,cmp);
	
	ll total_time_taken=0;
	ll ans=0;
	
	for(int i=0;i<n;i++){
		
		total_time_taken+=p[i].t;
		ans+=p[i].s-(p[i].d*total_time_taken);
		
	}
	
	
	
cout<<ans<<nl;
	
	
	
	
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	// int _t; cin>>_t;while(_t--)
		solve();
	
	
	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	
	
	
	
}