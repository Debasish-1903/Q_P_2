
/*Knapsack

Time-Limit: 2 sec Score: 1.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

There are 
�
 items numbered from 1 to 
�
. The 
�
�
ℎ
 item has a weight of 
�
�
 and a value of 
�
�
.

You have to choose some items out of the 
�
 items and carry them home in a knapsack. The capacity of the knapsack is 
�
 which donate the maximum weight that can be carried inside the knapsack. In other words, 
�
 means the total summation of all weights of items that can be carried in the knapsack.

Print maximum possible sum of values of items that you can take home.

Note: Solve this problem using recursion.


Input Format

First line contains two numbers 
�
 and 
�
 number of items and the capacity of the knapsack.

Next 
�
 lines will contain two numbers 
�
�
 and 
�
�
 .


Output Format

Print maximum possible sum of values of items that you can take home.


Constraints

(1≤N≤20,1≤W≤100)

(1≤wi≤50,1≤vi≤1000)


Sample Input 1

3 8
3 30
4 50
5 60

Sample Output 1

90

Sample Input 2

6 15
6 5
5 6
6 4
6 6
3 5
7 2

Sample Output 2

17*/



#include <bits/stdc++.h>
using namespace std;
int N, W;
vector<int> w, v;
int knapsack(int wei, int n)
{
    if (n == 0 || wei == 0)
        return 0;
    // If weight of the nth item is more
    // than Knapsack capacity wei, then
    // this item cannot be included
    // in the optimal solution
    if (w[n - 1] > wei)
    {
        return knapsack(wei, n - 1);
    }
    // Return the maximum of two cases:
    // (1) nth item included
    // (2) not included
    return max(v[n - 1] + knapsack(wei - w[n - 1], n - 1), knapsack(wei, n - 1));
}
int main()
{

    cin >> N >> W;
    w.resize(N);
    v.resize(N);
    for (int i = 0; i < N; i++)
    {
        cin >> w[i] >> v[i];
    }
    int ans = knapsack(W, N);
    cout << ans << endl;
}