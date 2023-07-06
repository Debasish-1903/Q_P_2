/*Distinct Characters AZ101

Time-Limit: 1 sec Score: 100.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Description

You are given a string S. You are given Q queries of two types, asking the number of distinct characters in the range [L, R] and changing the i-th character to c. (1-based indexing)


Input Format

The first line of the input contains one integer T - the number of test cases. Then T test cases follow.

The first line of each test contains a string S.

The second line of each test case contains one integer Q - the number of queries. 

Each of the next Q lines contain two types of queries: either 1 i c or 2 L R. The query 1 is for changing the i-th character to c and the query 2 is for finding the number of distinct characters in the range [L, R].


Output Format

For each test case, print the required queries.


Constraints

1≤ T ≤ 105

1≤ |S| ≤ 105

1≤ Q ≤ 106

1≤ Ai ≤ 105

It is guaranteed that the sum of |S| and the sum of Q over all test cases does not exceed 105.


Sample Input 1

2
abbac
3
2 1 3
1 2 c
2 1 4
flower
4
2 2 5
1 3 l
1 6 w
2 1 6

Sample Output 1

2
3
4
4

Note

For the first test case, distinct characters from 1-3 in abbac are ‘a’ and ‘b’. Changing string to acbac, distinct characters from 1-3 in abcac are ‘a’, ‘b’ and ‘c’.

For the second test case, distinct characters from 2-5 in flower are ‘l’, ‘o’, ‘w’, ‘e’. Changing string to fllwer and then to fllwee, distinct characters from 1-6 are ‘f’, ‘l’, ‘w’, ‘e’.*/

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
    
	string str;
	cin>>str;
	int q;
	cin>>q;
	
	unordered_set<char>st;
	while(q--){
	    st.clear();
	  char c;
	  int i, a,l,r;
	  
	  cin>>a;
	  
	  if(a==1){
	      cin>>i>>c;
	      
	      str[i-1]=c;
	      
	  }else if(a==2){
	      
	      cin>>l>>r;
	      for(int j=l-1;j<r;j++){
	          
	          st.insert(str[j]);
	          
	      }
	      
	      cout<<st.size()<<nl;
	      
	      
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