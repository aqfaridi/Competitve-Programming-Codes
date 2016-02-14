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
int arr[1010][1010];
int main()
{
    ios::sync_with_stdio(false);
    int r,c;
    memset(arr,31,sizeof arr);
    cin>>r>>c;
    for(int i=1;i<=r;i++)
        for(int j=1;j<=c;j++)
            cin>>arr[i][j];

    if(r == 1 && c == 1){
        cout<<0<<endl;
        return 0;
    }

    int cnt,finalcnt=0;
    for(int i=1;i<=r;i++)
        for(int j=1;j<=c;j++){
            cnt = 0;
            for(int k=-1;k<=1;k++)
                for(int p=-1;p<=1;p++)
                    if(arr[i+k][j+p] > arr[i][j])
                        cnt++;

            if(cnt == 8)
                finalcnt++;
        }
    cout<<finalcnt<<endl;
    return 0; 
}

