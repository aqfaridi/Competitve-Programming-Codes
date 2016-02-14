#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <vector>
#include <iomanip>
#include <cmath> 
#include <map>

using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

LL cumm[1000010];
int main()
{
    int t,n,num;
    LL cnt,result;
    scanf("%d",&t);
    while(t--)
    {
        result = 0;
        vector<LL> v;
        map<LL,LL> m;
        scanf("%d",&n);
        scanf("%d",&num);
        cumm[0] = num;
        m[cumm[0]]++;
        for(int i=1;i<n;i++)
        {
            scanf("%d",&num);
            cumm[i] = cumm[i-1] + num;
            m[cumm[i]]++;
        }

        map<LL,LL>::iterator it;
        for(it=m.begin() ; it != m.end() ; it++)
        {
            cnt = it->second; 
            if(it->first == 0)
                result += (cnt*(cnt+1))/2;
            else
                result += (cnt*(cnt-1))/2;
        }
        /*
        sort(cumm,cumm+n);
        for(int i=0;i<n;i++)
        {
            cnt = 1;
            while((i+1)<n && cumm[i]==cumm[i+1])
            {   cnt++;i++;}
            v.push_back(cnt);            
        }
        if(cumm[0]==0)
            result += v[0];
        
        int size = v.size();
        for(int i=0;i<size;i++)
            result += (v[i]*(v[i]-1))/2;
        */
        printf("%lld\n",result);
    }
    return 0;
}


