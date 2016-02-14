#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <climits>
#include <cassert>
#include <iomanip>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>
#include <complex>
#include <numeric>
#include <functional>
#include <sstream>
#include <algorithm>
#define MAX 1010
#define MOD 1000000007
using namespace std;
typedef long long LL;
typedef unsigned long long uLL;
char grid[MAX][MAX];
int m,n,trap[MAX][MAX],pathcnt,previous;//global
void floodfill(int i,int j)
{
    if(i<0 || j<0 || i>=m || j>=n)
    {
        cout<<"return ";
        return ;
    }

    
    if(trap[i][j]) //already set
    {
        pathcnt = trap[i][j]; //for backtracking set
        return ;
    }
    trap[i][j] = pathcnt;
    /** 4 dirn     WENS **/
    if(grid[i][j] == 'W') floodfill(i,j-1);
    else if(grid[i][j] == 'E') floodfill(i,j+1);
    else if(grid[i][j] == 'N') floodfill(i-1,j);
    else if(grid[i][j] == 'S') floodfill(i+1,j);
    
    trap[i][j] = pathcnt; //back set
}
int main()
{
    scanf("%d %d",&m,&n);
    for(int i=0;i<m;i++)
        scanf("%s",grid[i]);

    
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
        {
            if(!trap[i][j])
            {
                pathcnt = previous + 1;
                floodfill(i,j);
                if(pathcnt > previous)
                    previous++;
            }
        }
  
    /**
    floodfill(0,0);
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
            cout<<trap[i][j]<<" ";
    cout<<endl;
    }
    **/
    printf("%d\n",previous);
    return 0;
}

