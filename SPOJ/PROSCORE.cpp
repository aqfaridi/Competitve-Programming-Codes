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

#define print(x)                 cerr << x << " ";    
#define pn()                     cerr << endl;
#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;

#define MAX 100010
#define MOD 1000000007
int arr[100][100],row[100],col[100];
int main()
{
    int t,n,m,ans,cnt,sum,cases=0;
    bool b1,b2,b3;
    scanf("%d",&t);
    while(t--)
    {
        cases++;
        b1 = b2 = b3 = true;
        ans = 0;
        scanf("%d %d",&n,&m);
        for(int i=0;i<n;i++)
        {
            sum = 0;
            for(int j=0;j<m;j++)
            {
                scanf("%d",&arr[i][j]);
                sum += arr[i][j];
            }
            row[i] = sum;
            if(sum == 0)
                b2 = false;
            if(sum == m)
                b3 = false;
        }
        //colsum
        cnt = 0;
        for(int j=0;j<m;j++)
        {
            sum = 0;
            for(int i=0;i<n;i++)
                sum += arr[i][j];
            col[j] = sum;
            if(col[j] > 0)
                cnt++;
        }
        if(cnt < m)
            b1 = false;

        if(b1)
            ans += 4;
        if(b2)
            ans += 2;
        if(b3)
            ans += 1;
        printf("Case %d: %d\n",cases,ans);
    }
    return 0; 
}
