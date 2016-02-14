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
#define pn()                     cerr << endl;
#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;

#define MAX 100010
#define MOD 1000000007
int l,mem[30][300],cumm[30];
int solve(int idx,int sum)
{
    if(idx == l+1)  return 1;

    int& res = mem[idx][sum];
    if(res != -1)   return res;
    res = 0;int s;
    for(int len=0;len<= (l-idx);len++)
    {
        s = cumm[idx+len] - cumm[idx-1];
        if(sum <= s)    
            res += solve(idx+len+1,s);
    }
    return res;//back to parent
}
int main()
{
    ios::sync_with_stdio(false);
    string str;
    int cases = 0;
    while(1)
    {
        cases++;
        cin>>str;
        if(str == "bye")    break;

        memset(mem,-1,sizeof(mem));
        l = str.length();
        for(int i=0;i<l;i++)
            cumm[i+1] = cumm[i] + (str[i]-'0');

        cout<<cases<<". "<<solve(1,0)<<endl;
    }
    return 0; 
}
