/* Paired Cubes

Time-Limit: 2 sec Score: 1.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

You have given n positive integers A1, A2, …, An. Your task is to find the number of pairs (i, j) such that Ai * Aj is a cube number.


Input Format

The first line of input contains n - the size of the array.
The second line of input contains n space-separated integers A1, A2, …, An.


Output Format

Print the answer on a new line.


Constraints

1 ≤ n ≤ 105
1 ≤ Ai ≤ 106


Sample Input 1

5
1 2 4 8 27

Sample Output 1

4

Note

The pairs are (1, 8), (2, 4), (1, 27), (8, 27). */



/*
Consider the number n = p1a1  p2a2  p3a3  ….  pmam. Lets define normal value of n as norm(n) = p1a1%3  p2a2%3  p3a3%3  ….  pmam%3 and inverse-normal of n as invnorm(n) = p1(3 - a1%3) % 3  p2(3 - a2%3) % 3  ….  pm(3 - am%3) % 3. 

Observe that if products of two numbers x and y is a cube number iff norm(x * y) = 1. That means all powers of prime numbers in xy is multiple of 3. Again observe that norm(n) * invnorm(n) is a cube number.
Using these properties we can conclude that the norm(x) = invnorm(y) OR norm(y) = invnorm(x). Se if we maintain the count of norm(x) for all values, to find the number of numbers when multiply by y gives a cube number is basically the count of invnorm(y) in the count table. 

These mathematical notations might be confusing, but the main motive behind is to make all powers of prime numbers to a multiple of 3.

For more clarification, see the editorial code.

*/








#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


signed main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);

   int n; cin >> n;

   map <ll,int> M;

   ll ans = 0;

   for(int i = 0; i < n; i++) {
      int x; cin >> x;
      ll norm = 1;
      ll tar = 1;
      for(int j = 2; j * j <= x; j++) {
         int cnt = 0;
         while(x % j == 0) {
            x /= j;
            cnt++;
         }
         cnt %= 3;
         for(int k = 0; k < cnt; k++) {
            norm *= j;
         }
         if(cnt) {
            for(int k = 0; k < 3 - cnt; k++) {
               tar *= j;
            }
         }
      }
      if(x > 1) {
         norm *= x;
         tar *= (x * x);
      }
      ans += M[tar];
      M[norm]++;
   }

   cout << ans << "\n";
}