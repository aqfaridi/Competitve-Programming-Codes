/*
ID: aqfari1
PROG: beads
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

int main()
{
    ofstream fout("beads.out");
    ifstream fin("beads.in");
    int n,rt,lt,maxx = 0;
    string str;
    fin>>n;
    fin>>str;
    str = (str+str);
    for(int i=2;i<2*n;i++){
        rt = 1; lt = 1;
        char lch = str[i-1],rch = str[i];
        for(int j=i;j<2*n;j++){
            if(str[j] == 'w')   continue;
            else {rch =  str[j];break;}
        }
        for(int j=i-1;j>=0;j--){
            if(str[j] == 'w') continue;
            else {lch = str[j];break;}
        }

        for(int j=i+1;j<2*n;j++)
            if((str[j] == rch) || (str[j] == 'w')){
                rt++;
            }
            else
                break;
        for(int j=i-2;j>=0;j--)
            if((str[j] == lch) || (str[j] == 'w')){
                lt++;
            }
            else
                break;
        maxx = max(maxx,lt+rt);
    }
    if(maxx > n)
        maxx = n;
    fout<<maxx<<endl;
    return 0; 
}
