/*Combination Sum II

Time-Limit: 1 sec Score: 1.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

Find all valid combinations of k numbers that sum up to n such that the following conditions are true:

Only numbers 1 through 9 are used.
Each number is used at most once.
Return a list of all possible valid combinations. The list must not contain the same combination twice, and the combinations may be returned in any order.


Input Format

Complete the function combinationSum(k, n).


Output Format

Return a list ( vector<vector<int>> ) of all possible valid combinations. The list must not contain the same combination twice, and the combinations may be returned in any order.


Constraints

2 ≤ k ≤ 9
1 ≤ n ≤ 60

Sample Input 1

k = 3, n = 9

Sample Output 1

[[1,2,6],[1,3,5],[2,3,4]]

Sample Input 2

k = 4, n = 1

Sample Output 2

[]

Sample Input 3

k = 9, n = 45

Sample Output 3

[[1,2,3,4,5,6,7,8,9]] */

vector<int> temp;
vector<vector<int>> ans;
void solve(int i, int &k, int sum, int &n) {
    if (sum > n)return ; // pruning.
    if (i == 10) { // base
        if (temp.size() == k && sum == n)ans.push_back(temp);
        return;
    }
    // not taking i in the combination.
    solve(i + 1, k, sum, n);

    // taking i into combination.
    temp.push_back(i);
    solve(i + 1, k, sum + i, n);
    temp.pop_back(); // backtracking.
}
vector<vector<int>> combinationSum(int k, int n) {
    ans.clear();
    solve(1, k, 0, n);
    return ans;
}