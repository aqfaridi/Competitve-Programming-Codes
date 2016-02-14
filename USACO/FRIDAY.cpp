/*
ID: aqfari1
PROG: friday
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
int days[] = {31,28,31,30,31,30,31,31,30,31,30,31};
int arr[10];
int main()
{
    ofstream fout("friday.out");
    ifstream fin("friday.in");
    int n;
    bool leap;
    fin>>n;
    int cnt = 0;
    for(int i=1900;i<1900+n;i++){
        leap = false;
        if(((i%100 != 0) && (i%4 == 0)) || (i%400 == 0))
            leap = true;
        if(leap)    days[1] = 29;
        else    days[1] = 28;
        for(int j=0;j<=11;j++)
            for(int k=1;k<=days[j];k++,cnt++){                
               if(k == 13) arr[(cnt%7)]++;
            }
    }
    fout<<arr[5]<<" "<<arr[6];
    for(int i=0;i<=4;i++)
        fout<<" "<<arr[i];
    fout<<endl;

    return 0; 
}
