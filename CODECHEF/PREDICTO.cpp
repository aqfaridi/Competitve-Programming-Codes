#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <vector>
#include <iomanip>
#include <cmath> 

using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
typedef pair< pii , pii > tri;
#define MAX 100010
#define MOD 1000000007    
vector< tri > v,vl;
int main()
{
    ios::sync_with_stdio(false);
    int t,l,p,q,L,W,posi,posj,size1,size2,s1,e1,s2,e2;
    string str;
    cin>>t;
    while(t--)
    {
        v.clear();
        vl.clear();
        cin>>p>>q;
        cin>>str;
        l = str.length();
        W = L = 0;
        int i=0;j=p-1;
        while(j<l)
        {
            for(int k=i;k<=j;k++)
            {
                if(str[i]=='W')
                    W++;
                else
                    L++;
            }
            v.push_back(make_pair(make_pair(W,L),make_pair(posi,posj)));
            i++;j++;
        }
        sort(v.begin(),v.end());
        size1 = v.size();
        i=0;j=q-1;
        while(j<l)
        {
            for(int k=i;k<=j;k++)
            {
                if(str[i]=='W')
                    W++;
                else
                    L++;
            }
            vl.push_back(make_pair(make_pair(L,W),make_pair(posi,posj)));
            i++;j++;
        }
        sort(vl.begin(),vl.end());
        size2 = vl.size();
        int w1,l1,w2,l2;
        for(i=size1-1;i>=0;i--)
        {
            for(j=size2-1;j>=0;j--)
            {
                w1 = v[i].first.first;
                l1 = v[i].first.second;
                w2 = v[j].first.second;
                l2 = v[j].first.first;
                s1 = v[i].second.first;
                e1 = v[i].second.second;
                s2 = v[j].second.first;
                e2 = v[j].second.first;
                
                maxx = max(maxx,w1);    
                

            }
        }

    }
    return 0;
}
