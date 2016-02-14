#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <set>
#include <map>
#include <queue> 
#include <climits>
#include <cassert>

using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

#define pb push_back
#define mp make_pair
#define sz size()
#define ln length()
#define forr(i,a,b)                 for(int i=a;i<b;i++)
#define rep(i,n)                    forr(i,0,n) 
#define all(v)                      v.begin(),v.end()	
#define uniq(v)                     sort(all(v));v.erase(unique(all(v)),v.end())
#define clr(a)                      memset(a,0,sizeof a)
	
#define debug                       if(1)
#define debugoff                    if(0)	

#define print(x)                 cerr << x << " ";    
#define pn()				     cerr << endl;
#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;

#define MAX 100010
#define MOD 1000000007
int palin[1010][1010];
int mem[1010];
int n;
string s;
int ispalin(int i,int j){
    if(i == j)  return 1;
    if(i+1 == j)  return s[i] == s[j];

    int& res = palin[i][j];
    if(res != -1)   return res;

    res = 0;
    if(s[i] == s[j])
        res = ispalin(i+1,j-1);
    return res;
}
int solve(int idx){
    if(idx == n)
        return 0;
    
    int& res = mem[idx];
    if(res != -1)   return res;
    
    res = (1<<20);
    for(int i=idx;i<n;i++){
        if(palin[idx][i])
            res = min(res,1 + solve(i+1));
    }
    
    return res;
}
int minCut(string A) {
    n = A.length();
    s = A;
    memset(palin,-1,sizeof palin);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(palin[i][j] == -1)
                palin[i][j] = ispalin(i,j);

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
        	cerr<<palin[i][j]<<" ";
        cerr<<endl;
    }

    memset(mem,-1,sizeof mem);
    return solve(0)-1;
    
}

int main()
{
	ios::sync_with_stdio(false);
	int t,n;
	cout<<minCut("dVGAaVO25EmT6W3zSTEA0k12i64Kkmmli09Kb4fArlF4Gc2PknrlkevhROxUg")<<endl;
	return 0; 
}