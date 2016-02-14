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
string d = "qwertyuiopasdfghjkl;zxcvbnm,./";
int main()
{
    ios::sync_with_stdio(false);
    char ch;
    string str;
    cin>>ch;
    cin>>str;
    int l = str.length();
    
    if(ch == 'R')
        for(int i=0;i<l;i++)
        {
            for(int j=0;j<=29;j++)
                if(str[i] == d[j]){
                    cout<<d[j-1];break;}
        }  
    else{
    
        for(int i=0;i<l;i++)
        {
            for(int j=0;j<=29;j++)
                if(str[i] == d[j]){
                    cout<<d[j+1];break;}
        }
    }


    return 0; 
}

