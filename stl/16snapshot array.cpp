/*Snapshot Array

Time-Limit: 1 sec Score: 1.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

Implement a SnapshotArray that supports the following interface:

SnapshotArray(int length) initializes an array-like data structure with the given length. Initially, each element equals 0.
void set(index, val) sets the element at the given index to be equal to val.
int snap() takes a snapshot of the array and returns the snap_id: the total number of times we called snap() minus 1.
int get(index, snap_id) returns the value at the given index, at the time we took the snapshot with the given snap_id.

Input Format

The first line of input contains Q, L - the number of queries and the length of the array.
Next, Q lines contain queries of the types mentioned in the problem statement.


Constraints

1 ≤ Q ≤ 105
1 ≤ L ≤ 109
0 ≤ val ≤ 109
0 ≤ snap_id < (the total number of times we call snap())
0 ≤ index < L


Sample Input 1

4 3
set 0 5
snap
set 0 6
get 0 0

Sample Output 1

0
5*/





/*#include<bits/stdc++.h>
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
} */



#include <bits/stdc++.h>
using namespace std;

class SnapshotArray
{
public:
    unordered_map<int, vector<pair<int, int>>> v;
    int snapId;

    SnapshotArray(int length)
    {
        snapId = 0;
    }

    void set(int index, int val)
    {
        if (v.find(index) != v.end())
        {
            if (v[index].back().second == snapId)
                v[index].back().first = val;
            else
                v[index].push_back({val, snapId});
        }
        else
            v[index].push_back({val, snapId});
    }

    int snap()
    {
        snapId++;
        return snapId - 1;
    }

    int get(int index, int snap_id)
    {
        if (v.find(index) == v.end())
            return 0;

        vector<pair<int, int>> &temp = v[index];

        int L = 0, R = (int)temp.size() - 1;
        int ans = 0;

        while (L <= R)
        {
            int mid = (L + R) / 2;
            if (temp[mid].second <= snap_id)
            {
                ans = temp[mid].first;
                L = mid + 1;
            }
            else
                R = mid - 1;
        }

        return ans;
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