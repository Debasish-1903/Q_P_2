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



class CustomStack {
public:

	vector<pair<ll,ll>>st; 
	ll top_current;
	
	CustomStack(int maxSize) {
	   st.resize(maxSize);
	   
	    top_current=0;
	
	}

	void push(int x) {
	    
	    if(top_current<st.size()){
	        
	        st[top_current].f=x;
	        st[top_current].s=0;
	        
	        
	        top_current++;
	        
	    }
	    
	    
		
	}

	int pop() {
		
		if(top_current!=0){
		    
		    top_current--;
		    st[top_current].f+=st[top_current].s;
		    if(top_current){
		        
		        st[top_current-1].s+=st[top_current].s;
		    }
		    
		    return st[top_current].f;
		    
		}
		
		return -1;
		
	}

	void increment(ll k, ll val) {
		
	k=min(k,top_current);
	k--;
	if(k>=0)st[k].s+=val;
		
	}
};

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	int maxSize;
	cin >> maxSize;

	int q;
	cin >> q;

	CustomStack* customStack = new CustomStack(maxSize);

	for (int itr = 0; itr < q; itr++) {
		string op;
		cin >> op;

		if (op == "push") {
			int x;
			cin >> x;

			customStack->push(x);
		}
		else if (op == "pop") {
			cout << customStack->pop() << "\n";
		}
		else if (op == "inc") {
			int k, val;
			cin >> k >> val;
			customStack->increment(k, val);
		}
	}

}