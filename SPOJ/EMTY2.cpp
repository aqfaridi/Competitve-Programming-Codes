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

#define MAX 100010
#define MOD 1000000007
bool isEmpty(string str)
{
    int l = str.ln,zeros=0,ones=0;
    if(str[l-1]=='0' && str[l-2]=='0' && str[0]=='1')
    {
        rep(i,l)
        {
            if(str[i]=='0') zeros++;
            else if(str[i]=='1') ones++; 
        }
        if(zeros == 2*ones)
            return true;
        return false;
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    int t,n,cases=0;
    string str;
    cin>>t;
    while(t--)
    {
        cases++;
        cin>>str;
        if(isEmpty(str))
            cout<<"Case "<<cases<<": yes"<<endl;
        else
            cout<<"Case "<<cases<<": no"<<endl;
    }
    return 0; 
}
