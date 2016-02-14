#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <utility>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#define MAX 1000010
#define MOD 1000000007
using namespace std;
typedef long long LL;
typedef unsigned long long uLL;
LL power10[] = {1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000LL};
void calculate(int num,int d,int cnt[],int fzero)
{
    int i,n = num / power10[d]; //first digit

    for(i=0;i<n;i++)        //effect of first digit
        cnt[i] += power10[d];

    cnt[i] += (num % power10[d] + 1); //effect remaining digit
   
    if(fzero)               //once     //initial extra zero added
        cnt[0] -= power10[d];

    if(d==0)             //base case
        return ;

    for(i=0;i<10;i++)     //everytime
        cnt[i] += n*d*power10[d-1];

    if(fzero)           //once cut extra zero of every time
        cnt[0] -= (power10[d]-1)/9;

    calculate(num%power10[d],d-1,cnt,0);
}
int main()
{
    int a,b,d,org_a;
    LL sum;
    while(1)
    {
        sum = 0LL;
        scanf("%d %d",&a,&b);
        if(a==-1 && b==-1)
            break;
        if(a>b)
            swap(a,b);
        org_a = a;

        if(a!=1)
            a -= 1;

        int cnt1[10] = {1};
        int cnt2[10] = {1};

        d = (int)floor(log10(a));
        if(org_a!=1)
            calculate(a,d,cnt1,1);
        //calculate(2,0,cnt1,1);
        /**
        for(int i=0;i<10;i++)
            cout<<cnt1[i]<<" ";
        cout<<endl;
        **/
        d = (int)floor(log10(b));
        calculate(b,d,cnt2,1);
        /**
        for(int i=0;i<10;i++)
            cout<<cnt2[i]<<" ";
        cout<<endl;
        
        //printf("%d",cnt2[0]-cnt1[0]); //formatting panga
        for(int i=0;i<10;i++)
            printf("%d ",cnt2[i] - cnt1[i]);
        cout<<endl;
        */
        for(long long i=0;i<10;i++)
            sum += (cnt2[i] - cnt1[i]) * i;

        printf("%lld\n",sum);      
        
    }
    return 0;
}

