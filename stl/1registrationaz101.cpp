/*
Registration AZ101

Time-Limit: 1 sec Score: 100.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Description

Being the site administrator, you need to register the people on the website. A person registers with his name, S. If the name does not occur in the records, the person gets registered on the website and “OK” is shown. Otherwise, if the record already exists, print the name along with the number of times the person has registered on the website before, without any spaces.


Input Format

The first line of the input contains one integer T - the number of test cases. Then T test cases follow.

The first line of each test case contains one integer N - the number of people who register. 

Each of the next N lines contains a string S - the name in lower case alphabets.


Output Format

For each test case, print “OK” if the person registers for the first time. Otherwise, print the name along with the number of times the person has registered on the website before, without any spaces.


Constraints

1≤ T ≤ 105

1≤ N ≤ 105

1≤ |S| ≤ 30

It is guaranteed that the sum of N over all test cases does not exceed 106.


Sample Input 1

2
4
harry
ron
harry
hermione
3
abc
abc
abc

Sample Output 1

OK
OK
harry1
OK
OK
abc1
abc2

Note

For the first test case, harry registers again, so his name along with the name of times is printed.

For the second test case, abc registers thrice, so his name along with the name of times is printed.


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




 /*ll add(ll a,ll b){
	
	ll ans=(a+b)%mod;
	if(ans<0) ans+=mod;
	
	return ans;
}

 ll sub(ll a,ll b){
	
	ll ans=(a-b)%mod;
	if(ans<0) ans+=mod;
	
	return ans;
}

ll mul(ll a,ll b){
	
	ll ans=(a*b)%mod;
	if(ans<0) ans+=mod;
	
	return ans;
}*/


void solve(){
	
	ll n;
	cin>>n;


string str; 
unordered_map<string,ll>mp;

	while(n--){
	   	
	   	cin>>str;
	   	
	   	
	   	if(mp.find(str)==mp.end()){
	   	    
	   	    cout<<"OK"<<nl;
	   	    mp[str]++;
	   	}else{
	   	    
	   	    cout<<str<<mp[str]<<nl;
	   	    mp[str]++;
	   	}
	   	
	    
	    
	}
	
	
	
	
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	 int _t; cin>>_t;while(_t--)
		solve();
	
	
	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	
	
	
	
}