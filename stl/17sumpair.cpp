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
ll n, m, q;

class FindPairswithSum
{
public:

unordered_map<ll,ll>mp;

vector<ll>brr; 
vector<ll>arr;
    FindPairswithSum(vector<ll> &A, vector<ll> &B)
    {
        // brr.resize(m);
        // arr.resize(n);
        
        
        for(auto it:B){
            
            mp[it]++;
            brr.push_back(it);
            
        }
        for(auto it:A){
            arr.push_back(it);
            
        }
        
        
        
        
    }

    void add(int index, int val)
    {
        if(mp.find(brr[index])!=mp.end()&&mp[brr[index]]>0) mp[brr[index]]--;
        
        brr[index]+=val;
        mp[brr[index]]++;
        
        
    }

    int count(int total)
    {
        ll ans=0;
        for(ll i=0;i<arr.size();i++){
            
            if(mp.find(total-arr[i])!=mp.end()&&mp[total-arr[i]]>0){
                
                ans+=mp[total-arr[i]];
                
                
            }
            
        }
        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    
    cin >> n >> m >> q;

    vector<ll> A(n), B(m);

    for (auto &i : A)
    {
        cin >> i;
    }

    for (auto &i : B)
    {
        cin >> i;
    }

    FindPairswithSum *obj = new FindPairswithSum(A, B);

    for (int i = 0; i < q; i++)
    {
        string op;
        cin >> op;
        if (op == "add")
        {
            int index, val;
            cin >> index >> val;
            obj->add(index, val);
        }
        else
        {
            int total;
            cin >> total;
            cout << obj->count(total) << '\n';
        }
    }

    return 0;
}