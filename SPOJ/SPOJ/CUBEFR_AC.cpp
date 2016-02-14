#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#define Lim 1000001
using namespace std;
bool b[Lim];
vector<int> notcube;

void cubesieve()
{
    for(int i=2;i*i*i<Lim;i++)
    {
        int k=i*i*i;
        for(int j=k;j<Lim;j+=k)
            b[j]=1;
    }
    notcube.push_back(1);
    for(int i=1;i<Lim;i++)
        if(!b[i])
            notcube.push_back(i);

}

int main()
{
    cubesieve();
    int t,n,cases=0;

    scanf("%d",&t);
    while(t--)
    {
        cases++;
        scanf("%d",&n);
        if(n==1)
            { printf("Case %d: 1\n", cases) ; continue;}
        if(b[n]) 
            printf("Case %d: Not Cube Free\n", cases) ;
        else
        {
            vector<int>::iterator location=lower_bound(notcube.begin(),notcube.end(),n);
            int index=location - notcube.begin();
            printf("Case %d: %d\n",cases,index);
        }
    }
    
    return 0;
}

