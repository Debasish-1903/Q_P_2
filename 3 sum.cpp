/*3 Sum

Time-Limit: 2 sec Score: 1.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

Given an array A of N integers and an integer target, find three integers in A such that the sum is closest to the target (absolute value of (sum-target) is minimum). Print the minimum absolute value of (sum-target). You cannot select an index more than one. All three indexes should be distinct.


Input Format

The first line contains T, the number of test cases (1<=T<=100).

The first line contains two space-separated integers N, target where 3<=N<=10^3, -1e18<=target<=1e18.

Next line contains N space-separated integers (-1e9<=Ai<=1e9).

The Sum of N across all test cases ≤ 10^4.


Output Format

For each test case print the minimum absolute value of (sum-target).


Sample Input 1

1
5 3
1 2 3 4 5

Sample Output 1

3  */


#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
signed main()
{
   ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   int testcases;
   cin>>testcases;
   while(testcases--){
       ll n,target;
       cin>>n>>target;
       vector< ll > arr(n);
       for(int i=0;i<n;i++)
           cin>>arr[i];
       sort(arr.begin(),arr.end());
       ll best = arr[0]+arr[1]+arr[2];
       for(ll i=1;i<(ll)arr.size()-1;i++){
           ll lo = 0;
           ll hi = (ll)arr.size()-1;
           while(1){
               if(abs(arr[lo]+arr[i]+arr[hi]-target)<abs(best-target)){
                   best=arr[lo]+arr[i]+arr[hi];
               }
               if(arr[lo]+arr[i]+arr[hi]>target)hi--;
               else lo++;
               if(lo==i||hi==i)break;
           }
       }
       cout<<abs(best-target)<<"\n";
   }
}