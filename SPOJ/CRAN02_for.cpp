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

LL cumm[1000010];
int main()
{
    int t,n,num,cnt,zeros;
    LL result;
    scanf("%d",&t);
    while(t--)
    {
        result = 0;
        zeros = 0;
        vector<LL> v;
        scanf("%d",&n);
        scanf("%d",&num);
        cumm[0] = num;
        for(int i=1;i<n;i++)
        {
            scanf("%d",&num);
            cumm[i] = cumm[i-1] + num;
        }
        sort(cumm,cumm+n);
        for(int i=0;i<n;i++)
        {
            cnt = 1;
            while((i+1)<n && cumm[i]==cumm[i+1])
            {   cnt++;i++;}
            if(cumm[i]==0)
                zeros = cnt;
            v.push_back(cnt);            
        }
       
        result += zeros;
        int size = v.size();
        for(int i=0;i<size;i++)
            result += (v[i]*(v[i]-1))/2;
        printf("%lld\n",result);
    }
    return 0;
}




