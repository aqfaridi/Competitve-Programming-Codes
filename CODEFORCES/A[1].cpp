#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define MAX 1000010
#define MOD 1000000009
typedef int LL;
using namespace std;
LL dp[MAX],pos[MAX*9];
LL str[MAX];
int scan_d() 
{
	int ip=getchar_unlocked(),ret=0,flag=1;
	for(;ip<'0'||ip>'9';ip=getchar_unlocked())if(ip=='-'){flag=-1;ip=getchar_unlocked();break;}
	for(;ip>='0'&&ip<='9';ip=getchar_unlocked())ret=ret*10+ip-'0';
	return flag*ret;
}
void println_d(int n) 
{
	if(n<0){n=-n;putchar_unlocked('-');}
	int i=10;
	char output_buffer[11];
	output_buffer[10]='\n';
	do{output_buffer[--i]=(n%10)+'0';
		n/=10;}while(n);
	do{putchar_unlocked(output_buffer[i]);
	}while(++i<11);
}
void compute(int l)
{
    dp[0] = 1; //empty set({})
    dp[1] = 2; // two set formed by 1 char ({},{1})
    pos[str[1]] = 1;
    for(int i=2;i<=l;i++)
    {
        dp[i] = (dp[i-1]<<1)%MOD;
        if(pos[str[i]] != 0)
            dp[i] = (dp[i] - dp[pos[str[i]]-1] + MOD)%MOD;
        pos[str[i]] = i;
    }

    for(int i=1;i<=l;i++)
        pos[str[i]] = 0;
}
int main()
{
    int t,l,diff,n,prev, curr;
    t = scan_d();
    while(t--)
    {
        //memset(pos,0,sizeof(pos));
	    n = scan_d();
        prev = scan_d();
        for(int i=1;i<n;i++)
        {
            curr = scan_d();
            diff = curr - prev;
            if(diff <= 0)
                diff += 8*MAX;
            str[i] = diff;
            prev = curr;
        }
        l = n-1;
        compute(l);
        println_d((dp[l]+MOD-1)%MOD);   
    }
    return 0;
}
