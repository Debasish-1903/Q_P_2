/*Burn them All

Time-Limit: 2 sec Score: 0.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

You have given an undirected graph of N vertices and M edges. Edge weight d on edge between nodes u and v represents that u and v are connected by a thread of length d units. 
You set node A on to the fire. It takes to fire 1 unit of time to travel 1 unit of distance via threads.
Let T be the minimum time in which all the threads will be burned out. 

Your task is to find 10T. We can prove that 10T will always be an integer number.

See the sample test cases for more explanation.


Input Format

The first line of input contains N - the number of nodes in the graph.
The second line contains M - the number of edges in the graph.
Next M lines contain three integers u, v, d - there is a thread between node u and v of length d.
The last line of input contains A - the node on which we set fire.

It’s guaranteed that graph is connected.


Output Format

Print the value of 10T.


Constraints

1 ≤ N ≤ 2 x 105
1 ≤ M ≤ 2 x 105
1 ≤ u, v ≤ N
1 ≤ d ≤ 109


Sample Input 1

2
1
1 2 2
1

Sample Output 1

20

Sample Input 2

3
3
1 2 2
2 3 2
1 3 6
1

Sample Output 2

50

Sample Input 3

3
3
1 2 2
1 3 2
2 3 1
1

Sample Output 3

25

Note

Explanation 1:

At t = 0, node 1 is at fire.
At t = 1, thread 1-2 is half burned.
At t = 2, thread 1-2 is fully burned.
So T = 2. And 10T = 20.

Explanation 2:

At t = 0, node 1 is at fire.
At t = 2, thread 1-2 is fully burned, and thread 1-3 is 1/3rd burned.
At t = 4, threads 1-2 and 2-3 are fully burned, and 4 units of thread 1-3 are burned. For the remaining 2 units of thread 1-3, fire is approaching from both ends.
At t = 5, all threads are fully burned.
So T = 5. And 10T = 50.

Explanation 3:

At t = 0, node 1 is starting to burn.
At t = 2, threads 1-2 and 1-3 are fully burned. Now for thread 2-3, fire is approaching from both ends at equal speed.
At t = 2.5, thread 2-3 is fully burned.
So T = 2.5. And 10T = 25.   */



#include <bits/stdc++.h>
using namespace std;

#define ll long long int

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int m;
    cin >> m;

    vector<pair<int, ll>> graph[n + 1];
    vector<pair<pair<int, int>, ll>> edges;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        ll d;
        cin >> u >> v >> d;
        graph[u].push_back({v, d});
        graph[v].push_back({u, d});
        edges.push_back({{u, v}, d});
    }

    int st;
    cin >> st;

    ll dist[n + 1];

    for (int i = 1; i <= n; i++)
    {
        dist[i] = 1e18;
    }

    priority_queue<pair<ll, int>> q;

    q.push({0, st});
    dist[st] = 0;

    bool visited[n + 1];
    memset(visited, false, sizeof(visited));

    while (!q.empty())
    {
        auto it = q.top();
        q.pop();

        ll w = -it.first;
        int u = it.second;

        if (visited[u])
            continue;

        visited[u] = true;

        for (auto it : graph[u])
        {
            int v = it.first;
            ll d = it.second;

            if (dist[v] > w + d)
            {
                dist[v] = w + d;
                q.push({-dist[v], v});
            }
        }
    }

    ll ans = -1e18;

    for (int i = 1; i <= n; i++)
        assert(visited[i]);

    for (auto it : edges)
    {
        int u = it.first.first;
        int v = it.first.second;
        ll d = it.second;

        ans = max(ans, (dist[u] + dist[v] + d) * 5); 
        // acutally if 
        //abs(dist[u]-dist[v])>=d----> taken time =(min(dist[u],dist[v])+d)*10
        // else ((t-dist[u])+(t-dist[v]))=d---->t=(dist[u]+dist[v]+d)/2-->10t
        
        // actually if we see the if case there is no chance of > ,only there can be == is
        // possible for condition checking because this path is taken bcs this one is shortest (by dijkstra)
        
        // that's why for both case we can write  ans = max(ans, (dist[u] + dist[v] + d) * 5); as we calculate 10t
    }

    assert(ans > 0);

    cout << ans << "\n";
}





/* method-2  // same method just little bit modification :D)

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define float double
#define ll int64_t
int n, m;
vector<vector<pair<ll, ll>>> g;
vector<ll> dist;
vector<pair<pair<ll, ll>, ll>> edge_list;
void dj(ll node)
{
    dist[node]=0;
    priority_queue<pair<ll, ll>> pq;
    pq.push({-0, node});
    while (!pq.empty())
    {
        ll cur_dist = -pq.top().first;
        ll cur_node = pq.top().second;
        pq.pop();
        for (auto v: g[cur_node])
        {
            if(dist[v.first]> cur_dist + v.second)
            {
                dist[v.first] = cur_dist + v.second;
                pq.push({-dist[v.first], v.first});
            }
        }
        
    }  
}

float burn(ll a, ll b, ll c)
{
    if(abs(a-b)>=c)
    {
        return (float)c + (float)min(a, b);
    }
    else
    {
        return (float)min(a, b)+ abs(a-b) + (c-abs(a-b))/2.0;
    }
}

void solve(){
    cin>>n>>m;
    g.resize(n+1);
    dist.assign(n+1, 1e18);
    while (m--)
    {
        ll a, b, c;
        cin>>a>>b>>c;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
        edge_list.push_back({{a, b}, c});
    }
    ll fire;
    cin>>fire;
    dj(fire);
    ll m = 0;
    for(auto e: edge_list)
    {
        ll a= dist[e.first.first];
        ll b = dist[e.first.second];
        ll c = e.second;
        m = max(m, a+b+c);
    }
    cout<<5*m<<endl;
    
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t=1; while(t--){
        solve();
    }
    return 0;
}*/



/*approach

The time it takes for the spark to reach either of the endpoints of edge be depends on the distances
involved. Let's assume, for now, that edge ab is greater than ac. In that case:
• The maximum time to reach vertex b would be max(dist[b], dist[c]), where dist[x] represents the
distance of a vertex from the source vertex a.
• The minimum time to reach vertex c would be min(dist[b], dist[c])



Generalizing this approach for any edge with endpoints b and c, the time taken is 
solely dependent on the edge's length and the distance from the source vertex. This 
value can be precalculated, and all that remains is finding the maximum time taken to 
burn any edge. Since all of them are absolute time values of time taken to burn 
any edge, we just need to return the maximum over all such values.

The time complexity of this approach is that of Dijkstra's algorithm since we
 need to find the distance of all vertices from the source vertex,
  resulting in a complexity of 
O(Elog(V)).*/

