#include <cstdio>
#include <cstring>
typedef long long L;
int v[] = {1,4,7,16,19,25,28,31},n;
L m[34][32][32];
L r(int x,int k,int f){if(x==n)return f==0;L& t=m[x][k][f];if(t!=-1)return t;t = 0;for(int i=0;i<=7;i++){bool V=true;for(int j=0;j<=4;j++)if((f & (1<<j)) && (v[i] & (1<<j))==0){V=false;break;}if(V)t=t+r(x+1,v[i],(f^v[i]));}return t;}
int main()
{
    for(n=2;n<=34;n+=2)
    {
        memset(m,-1,sizeof m);
        printf("%lld\n",r(0,0,0));
    }
    return 0; 
}
