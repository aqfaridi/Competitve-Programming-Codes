/*
ID: aqfari1
PROG: gift1
LANG: C++
*/

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
#include <fstream> 

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
string str[20];
string s;
map<string, pii > m;
int main()
{
    ofstream fout("gift1.out");
    ifstream fin("gift1.in");
    int n,give,each,remain,nof;
    fin>>n;
    for(int i=0;i<n;i++)    fin>>str[i];
    while(fin>>s){
        fin>>give>>nof;
        if(nof != 0){
            each = give/nof;
            remain = give%nof;
            m[s].first += (give-remain);
        }
        rep(i,nof){
            fin>>s;
            m[s].second += each;
        }
    }
    rep(i,n){
        fout<<str[i]<<" ";
        fout<<m[str[i]].second - m[str[i]].first<<endl;
    }
    return 0; 
}
