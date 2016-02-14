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
#define MAX 1000010
LL divsum[MAX];
void divsumm()
{
    for(int i=2;i<MAX;i++)
        divsum[i] = 1;//adding div=1 extra    
    
    for(int i=2;i<MAX;i++)
    {
        for(int j=2*i;j<MAX;j+=i)
            divsum[j] += i;    
        divsum[i] += divsum[i-1];
    }
}
int main()
{
    divsumm();
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        printf("%lld\n",divsum[n]);        
    }
    return 0;
}


