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
#define MAX 1000010
#define MOD 1000000007
using namespace std;
typedef long long LL;
typedef unsigned long long uLL;
vector<pair<int,int> > u(110);
vector<pair<int,int> > v(110);
int path[110][110];
int main()
{
    int t,n,c,x,y,a,b,k;
    t = 1;
    while(t--)
    {
        memset(path,0,sizeof path);
        k = 1;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            cin>>c;
            if(c==1)
            {
                //add
                cin>>x>>y;
                u[k] = make_pair(x,y);
                v[k] = make_pair(x,y);
                if(k>=2)
                for(int ii = 1;ii<=k;ii++)
                {

                    cout<<k<<endl;

                        cout<<u[ii].second<<" "<<v[k].second<<" "<<u[ii].second<<" "<<v[k].first<<endl;
                    if(((u[ii].first < v[k].second) && (u[ii].first > v[k].first)) || ((u[ii].second < v[k].second) && (u[ii].second > v[k].first)))
                    {
                        cout<<u[ii].second<<" "<<v[k].second<<" "<<u[ii].second<<" "<<v[k].first<<endl;
                        path[ii][k] = 1;
                        cout<<ii<<" "<<k<<endl;
                        cout<<path[ii][k]<<endl;
                    }
                    else
                        path[ii][k] = 0;
                }
                path[k][k] = 0;
                if(k>=2)
                for(int ii = 1;ii<=k-1;ii++)
                {
                    if((u[k].first < v[ii].second && u[k].first > v[ii].first) || (u[k].second < v[ii].second && u[k].second > v[ii].first))
                        path[k][ii] = 1;
                    else
                        path[k][ii] = 0;
                }
                if(k>=2)
                for(int ii=1;ii<=k;ii++)
                {
                    path[ii][k] = (path[ii][k] || (path[ii+1][k] && path[ii][k-1]));
                }
                if(k>=2)
                for(int ii=1;ii<=k-1;ii++)
                {
                    path[k][ii] = (path[k][ii] || (path[k-1][ii] && path[k][ii+1]));
                }
                k++;
            }
            else if(c==2)
            {
                //query
                cin>>a>>b; //kth inserted interval
                if(path[a][b])
                    cout<<"YES"<<endl;
                else 
                    cout<<"NO"<<endl;

            }
        }       
        for(int ii=0;ii<=3;ii++)
        {
            for(int jj=0;jj<=3;jj++)
                cout<<path[ii][jj]<<" ";
            cout<<endl;
        }
    }
    return 0;
}

