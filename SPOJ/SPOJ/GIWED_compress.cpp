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
#include <map>
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
#define MAX 110
#define MOD 1000000007
using namespace std;
typedef long long LL;
typedef unsigned long long uLL;
bool grid[MAX][MAX];
int arr[MAX];
vector<pair<complex<int>,complex<int> > > v;
int cnt,m,n,k,l;
long long ans;
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
vector<int> x,y;
map<int,int> mx;
map<int,int> rev_mx;
map<int,int> my;
map<int,int> rev_my;

void floodfill(int i,int j)
{
    //stack
    
    p = make_pair(i,j);
    q.push_front(p);
    while(!q.empty())
    {
        p = q.front();
        q.pop_front();
        if(p.first < 0 || p.first >= x.size() || p.second < 0 || p.second >= y.size())
            continue;//out of boundary node
        if(grid[p.first][p.second] != 0)
            continue;
        
        //grid[p.first][p.second] = 1;
        //cout<<p.first<<" "<<p.second<<endl;
        //cout<<"here";
        //cout<<grid[p.first][p.second]<<endl;
        
        grid[p.first][p.second] = 1;
        cnt += ((rev_mx[p.first+1] - rev_mx[p.first]) * (rev_my[p.second+1] - rev_my[p.second]));
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
    int t,x1,y1,x2,y2;
    scanf("%d",&t);
    while(t--)
    {
        ans = 0;
        v.clear();
        q.clear();
        x.clear();y.clear();mx.clear(),my.clear();
        
        memset(grid,0,sizeof grid);
        scanf("%d %d %d %d",&m,&n,&k,&l);
        if(k==0)//no carpet
        {
            cout<<m*n<<endl;
            continue;
        }
        for(int i=0;i<k;i++)
        {
            scanf("%d %d %d %d",&x1,&y1,&x2,&y2);

            complex<int> c1(x1,y1),c2(x2,y2);
            v.push_back(make_pair(c1,c2));
            x.push_back(x1);
            x.push_back(x2);
            y.push_back(y1);
            y.push_back(y2);
        }        
        sort(x.begin(),x.end());
        sort(y.begin(),y.end());
        if(x[0]==0 && y[0]==0)
        {
            //lock 1st row and 1st col
            for(int i=0;i<x.size()+3;i++)
                grid[i][0] = 1;
            for(int i=0;i<y.size()+3;i++)
                grid[0][i] = 1;
        }
        x.push_back(0);
        y.push_back(0);
        x.push_back(m);
        y.push_back(n);
        sort(x.begin(),x.end());
        sort(y.begin(),y.end());
       // for(int i=0;i<x.size();i++)
         //   cout<<x[i]<<" ";
        //cout<<endl;
        x.erase(unique(x.begin(),x.end()),x.end());

        //for(int i=0;i<x.size();i++)
          //  cout<<x[i]<<" ";
        //cout<<endl;
        y.erase(unique(y.begin(),y.end()),y.end());
        //all points are distinct 
        mx[0] = 0; my[0] = 0;
        rev_mx[0] = 0;
        rev_my[0] = 0;
        for(int i=0;i<x.size();i++)
        {
            mx[x[i]] = i+1;
            rev_mx[i+1] = x[i];
           // cout<<x[i]<<" "<<i+1<<endl;
        }
       // cout<<"break"<<endl;
        for(int i=0;i<y.size();i++)
        {
            my[y[i]] = i+1;
            rev_my[i+1] = y[i];
           // cout<<y[i]<<" "<<i+1<<endl;
        }

        int index = 0;
        int minx,miny,maxx,maxy;  
        //for(int i=0;i<v.size();i++)
       // {
            
           //complex<int> c1(v[i].first),c2(v[i].second);
           //cout<<real(c1)<<" "<<imag(c1)<<" "<<real(c2)<<" "<<imag(c2)<<endl; 
       // }   
        for(int i=0;i<v.size();i++)
        {
                     
           complex<int> c1(v[i].first),c2(v[i].second);
           minx = min(mx[real(c1)] , mx[real(c2)]);
           maxx = max(mx[real(c1)] , mx[real(c2)]);
           miny = min(my[imag(c1)] , my[imag(c2)]);
           maxy = max(my[imag(c1)] , my[imag(c2)]);
          // cout<<minx<<" "<<maxx<<" "<<miny<<" "<<maxy<<endl;            
           for(int j = minx ; j<maxx ; j++)
               for(int kk = miny ; kk<maxy ; kk++)
                   grid[j][kk] = 1;
           /*

          for(int i=0;i<2*k;i++)
          {
            for(int j=0;j<2*k;j++)
                cout<<grid[i][j]<<" ";
            cout<<endl;
          }*/
        }
      /** 
        for(int i=0;i<2*k;i++)
        {
            for(int j=0;j<2*k;j++)
                cout<<grid[i][j]<<" ";
            cout<<endl;
        }
        floodfill(0,0);
        cout<<x.size()<<" "<<y.size()<<endl;
    
        for(int i=0;i<2*k;i++)
        {
            for(int j=0;j<2*k;j++)
                cout<<grid[i][j]<<" ";
            cout<<endl;
        }
    **/   
        //floodfill(0,0);
        //cout<<cnt<<endl;
        
        for(int i=0;i<x.size();i++)
            for(int j=0;j<y.size();j++)
            {
                cnt = 0;
                if(grid[i][j] == 0)
                    floodfill(i,j);

                arr[index++] = cnt;
            }
       /** 
        for(int i=0;i<2*k;i++)
        {
            for(int j=0;j<2*k;j++)
                cout<<grid[i][j]<<" ";
            cout<<endl;
        }**/
        sort(arr,arr+index,cmp);
      //  for(int i=0;i<index;i++)
        //    cout<<arr[i]<<" ";
        //cout<<endl;
        
        for(int i=0;i<l;i++)
        {
            ans += arr[i];
        }
       // if(x[0] > 0)
         //   ans += x[0]*y[0] + (x[x.size()-1]-x[0])*y[0] + (y[y.size()-1]-y[0])*x[0] ;
        //cout<<((m-x[x.size()-1])*y[y.size()-1])<<endl;
        //cout<<((n-y[y.size()-1])*m)<<endl;
        //ans += (((m-x[x.size()-1])*y[y.size()-1]) + ((n-y[y.size()-1])*m) );
        cout<<ans<<endl;
        
    }
    return 0;
}

