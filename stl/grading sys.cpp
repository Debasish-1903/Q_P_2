/*Grading System AZ101

Time-Limit: 1 sec Score: 100.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Description

You are given the marks of a student in mid-term, final-term and the make-up examinations. If the student does not attend an exam, marks are assigned as -1. You have to find the grade of the student according to the following guidelines:

If the student does not take the mid-term or the final-term exam, grade is F
If the total score in mid-term and final-term is greater than or equal to 80, grade is A.
If the total score in mid-term and final-term is greater than or equal to 65 and less than 80, grade is B.
If the total score in mid-term and final-term is greater than or equal to 50 and less than 65, grade is C.
If the total score in mid-term and final-term is greater than or equal to 30 and less than 50, grade is D. However, if the score of the make-up examination is greater than or equal to 50, the grade will be C.
If the total score in mid-term and final-term is less than 30, grade is F.

Input Format

The first line of the input contains one integer T - the number of test cases. Then T test cases follow.

The first line of each test case contains three space-separated integers M, F, R - the marks of the student in the mid-term, final-term and the make-up examinations.


Output Format

For each test case, print the grade of the student.


Constraints

1≤ T ≤ 105

1≤ M, F ≤ 50

1≤ R ≤ 100


Sample Input 1

4
41 48 76
-1 48 100
20 25 61
21 5 20

Sample Output 1

A
F
C
F   */


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


void solve(){

ll m,f,r;

cin>>m>>f>>r;


//cout<<"ans is .. ";
if(m==-1||f==-1){cout<<"F"<<nl;return;}
if(m+f<30)cout<<"F"<<nl;
 if(m+f>=80)cout<<"A"<<nl;
 if(m+f>=65&&m+f<80)cout<<"B"<<nl;
 if(m+f>=50&&m+f<65)cout<<"C"<<nl;
 if(m+f>=30&&m+f<50){
    
    if(r>=50)cout<<"C"<<nl;
    
   else cout<<"D"<<nl;
     
 }

	
	
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int _t; cin>>_t;while(_t--)
		solve();
	
	
	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	

	
	
	
}