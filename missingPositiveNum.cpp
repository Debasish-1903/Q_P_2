/*Missing positive number

Time-Limit: 1 sec Score: 1.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Description

You are given an unsorted array of N integers. Your task is to find the smallest positive integer which is missing in the array.


Input Format

The first line contains an integer T, the number of test cases. (1 ≤ T ≤ 10000)

The first line of each test case contains an integer N, 1≤N≤10^5.

The next line contains N space-separated integers, -10^6 ≤ A[i] ≤ 10^6.

Sum of N across all test cases ≤ 10^6.


Output Format

For each test case print in a new line first missing positive integer.


Sample Input 1

5
5
-1 2 4 1 5
5
1 4 3 8 2
5
1 7 8 5 2
5
-1 -2 -3 -4 -5
5
2 1 4 -6 8

Sample Output 1

3
5
3
1
3*/

#include <bits/stdc++.h>
using namespace std;
int getFirst(vector<int>& nums) {

       /// STEP 1: PUT ALL POSITIVE INTEGERS AT THE LEFT SIDE OF ARRAY 'nums'.
       int j = 0;
       for(int i=0; i<nums.size(); i++)
       {
           if(nums[i] > 0){
               swap(nums[i], nums[j++]);
           }
       }

       /// STEP2: Find Smallest positive integer which is not present in [0 ... new_size) using sign bits of numbers.
       /// if a number at index X is negative, it means there exists a positive integer with value X.
       /// Then we will search for the first index in [0 ... new_size) which is not positive.
       int new_size = j, i;

       for (i = 0; i < new_size; i++) {
           if (abs(nums[i]) - 1 < new_size && nums[abs(nums[i]) - 1] > 0)
               nums[abs(nums[i]) - 1] = -nums[abs(nums[i]) - 1];
       }

       /// STEP 3: Return first index with positive value.
       for(i=0; i<new_size; i++)
       {
           if(nums[i] > 0){
               break;
           }
       }
       return i+1;
}
signed main()
{
   ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   int testcases;
   cin>>testcases;
   while(testcases--){
       int n;
       cin>>n;
       vector<int>arr(n);
       for(int i=0;i<n;i++)cin>>arr[i];
       cout<<getFirst(arr)<<"\n";
   }
}