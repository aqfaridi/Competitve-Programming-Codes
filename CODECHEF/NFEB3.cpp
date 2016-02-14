#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <vector>
#include <iomanip>
#include <cmath> 
#include <climits>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

#define MAX 550
#define MOD 1000000007    
int arr[MAX][MAX],path[MAX][MAX],p[MAX];
int kk;
void make_path(int i,int j)
{
    if(path[i][j] == 2)
        return;
    if(path[i][j] == 0)
    {
        p[kk++] = arr[i][j];
        make_path(i-1,j+1);
    }
    else
    {
        p[kk++] = arr[i][j];
        make_path(i-1,j-1);
    }
}
vector<int> v;
int main()
{
    //ios::sync_with_stdio(false);
    int t,n,m,k,var;
    bool flag;
    cin>>t;
    while(t--)
    {
        v.clear();
        memset(path,0,sizeof path);
        //maxx = -INT_MAX;
        cin>>n>>m>>k;
        for(int i=0;i<n;i++)
        {
            arr[i][0] = -INT_MAX;
            arr[i][m+1] = -INT_MAX;
        }

        for(int i=0;i<n;i++)
            for(int j=1;j<=m;j++)
            {
                cin>>var;
                arr[i][j] = -var;
            }
        
        for(int i=1;i<=m;i++)
        {
            arr[0][i] += k;
            if(arr[0][i] > 100)
                arr[0][i] = 100;
            if(arr[0][i] < 0)
                arr[0][i] = 0;
            path[0][i] = 2;
        }

        for(int i=1;i<n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(arr[i-1][j+1] > arr[i-1][j-1])
                    path[i][j] = 0;
                else
                    path[i][j] = 1;

                arr[i][j] += max(arr[i-1][j+1],arr[i-1][j-1]);
                if(arr[i][j] > 100)
                    arr[i][j] = 100;
                if(arr[i][j] < 0)
                    arr[i][j] = 0;
            }
        }
        
       // for(int i=1;i<=m;i++)
         //   if(arr[n-1][i] > maxx)
            //    maxx = arr[n-1][i];                
        int x;
        flag = false;
        for(int i=1;i<=m;i++)
        {
            //if(arr[n-1][i] == maxx)
            //{
                kk = 0;
                make_path(n-1,i);
                for(x=0;x<kk;x++)
                {
                    if(p[x] <= 0)
                        break;
                }
                if(x == kk)
                {
                    flag = true;
                    v.push_back(arr[n-1][i]);
                }
            //}
        }

        if(flag)
            cout<<*max_element(v.begin(),v.end())<<endl;
        else
            cout<<-1<<endl;
    }
    return 0;
}
