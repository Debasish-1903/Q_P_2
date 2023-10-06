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


class SnapshotArray
{
public:

vector<vector<pair<int,int>>>arr;
int timer;
	
	SnapshotArray(int length)
	{
		arr.resize(length);
		
		timer=0;
		
	}

	void set(int index, int val)
	{
	    
	    if(!arr[index].empty()&&arr[index].back().f==timer){     // optimization//
	        arr[index].pop_back();
	    }
		
		arr[index].push_back(make_pair(timer,val));
		
		
	}

	int snap()
	{
	timer++;
	return timer-1;
		
	}

	int get(int index, int snap_id)
	{
	    
	    auto it= lower_bound(arr[index].begin(),arr[index].end(),make_pair(snap_id,INT_MAX));
	    
	    
	    if(it==arr[index].begin()){
	        return 0;
	    }else{
	        
	        it--;
	        return it->s;
	        
	    }
		
	}
};

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	int Q, L;
	cin >> Q >> L;

	SnapshotArray snapshotArray(L);

	while (Q--)
	{
		string op;
		cin >> op;

		if (op == "set")
		{
			int index, val;
			cin >> index >> val;

			snapshotArray.set(index, val);
		}
		else if (op == "get")
		{
			int index, snap_id;
			cin >> index >> snap_id;

			cout << snapshotArray.get(index, snap_id) << "\n";
		}
		else if (op == "snap")
		{
			cout << snapshotArray.snap() << "\n";
		}
	}

	return 0;
}