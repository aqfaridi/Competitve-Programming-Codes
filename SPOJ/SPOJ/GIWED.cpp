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
#define MAX 10010
#define MOD 1000000007
using namespace std;
typedef long long LL;
typedef unsigned long long uLL;
bool grid[MAX][MAX];
int arr[MAX];
vector<pair<int,int> > v;
int ans,cnt,m,n;
/**
void floodfill(int i,int j)
{
    if(i<0 || i>=m || j<0 || j>=n)
        return ;

    if(grid[i][j] != 0)
        return ;
    
    grid[i][j] = 1;
    cnt++;
    floodfill(i,j-1);
    floodfill(i,j+1);
    floodfill(i+1,j);
    floodfill(i-1,j);
}
**/
deque<pair<int,int> > q;
pair<int,int> p;
void floodfill(int i,int j)
{
    //stack
    
    p = make_pair(i,j);
    q.push_front(p);
    while(!q.empty())
    {
        p = q.front();
        q.pop_front();
        if(p.first < 0 || p.first >=m || p.second < 0 || p.second >=n)
            continue;//out of boundary node
        if(grid[p.first][p.second] != 0)
            continue;
        
        grid[p.first][p.second] = 1;
        //cout<<p.first<<" "<<p.second<<endl;
        cnt++;
        q.push_front(make_pair(p.first,p.second+1));
        q.push_front(make_pair(p.first,p.second-1));
        q.push_front(make_pair(p.first-1,p.second));
        q.push_front(make_pair(p.first+1,p.second));
    }
}
bool cmp(int a,int b)
{
    return (a>b);
}
int main()
{
    int t,k,l,x1,y1,x2,y2;
    scanf("%d",&t);
    while(t--)
    {
        ans = 0;
        v.clear();
        q.clear();
        memset(grid,0,sizeof grid);
        scanf("%d %d %d %d",&m,&n,&k,&l);
        if(k==0)//no carpet
        {
            cout<<m*n<<endl;
            continue;
        }        for(int i=0;i<k;i++)
        {
            scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
            v.push_back(make_pair(x1,y1));
            v.push_back(make_pair(x2-1,y2-1));
            for(int y=y1;y<y2;y++)
                for(int x=x1;x<x2;x++)
                    grid[x][y] = 1;
        }        
        /** 
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }
        **/
        int index = 0;
        
        for(int i=0;i<v.size();i++)
        {
            
           cnt = 0;
           //cout<<grid[i][j]<<" ";
           if(grid[v[i].first][v[i].second + 1] ==0)
                    floodfill(v[i].first,v[i].second+1);
                //cout<<cnt<<endl;
           if(cnt!=0)
                    arr[index++] = cnt;

           cnt = 0; 
                
           if(grid[v[i].first][v[i].second - 1] ==0)
                    floodfill(v[i].first,v[i].second-1);
                //cout<<cnt<<endl;
           if(cnt!=0)
                    arr[index++] = cnt;

           cnt = 0; 
                                
           if(grid[v[i].first + 1][v[i].second] ==0)
                    floodfill(v[i].first+1,v[i].second);
                //cout<<cnt<<endl;
           if(cnt!=0)
                    arr[index++] = cnt;

           cnt = 0; 
          
           if(grid[v[i].first - 1][v[i].second] ==0)
                    floodfill(v[i].first-1,v[i].second);
                //cout<<cnt<<endl;
           if(cnt!=0)
                    arr[index++] = cnt;

        }
        //floodfill(0,0);
        //cout<<cnt<<endl;

        /** 
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }
        **/
        sort(arr,arr+index,cmp);
        //for(int i=0;i<index;i++)
          //  cout<<arr[i]<<" ";
        //cout<<endl;
        for(int i=0;i<l;i++)
        {
            ans += arr[i];
        }
        cout<<ans<<endl;
        
    }
    return 0;
}

