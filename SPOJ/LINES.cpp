#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <vector>
#include <iomanip>
#include <cmath> 
#include <set>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

int main()
{
    int t,n,x,y,size,cnt,g;
    long double slope;
    while(1)
    {
        cin>>n;
        if(n==0)
            break;
        vector< pii > v,m;
       
        for(int i=0;i<n;i++)
        {
            cin>>x>>y;
            v.push_back(make_pair(x,y));
        }      
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                y = (v[i].second - v[j].second);
                x = (v[i].first - v[j].first);
                g = __gcd(x,y);
                y /= g ; x /= g;
                
                if(x<0)
                    {x=-x;y=-y;}
                m.push_back(make_pair(x,y));
            }
        }
        sort(m.begin(),m.end());
        size = m.size();
        cnt = 0;
        
        for(int i=0;i<size;i++)
        {
            while((i+1 < size) && m[i].first==m[i+1].first && m[i].second==m[i+1].second)
                i++;
            cnt++;
            
        }
     
        cout<<cnt<<endl;
    }
    return 0;
}
