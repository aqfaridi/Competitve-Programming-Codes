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
long long cnt;
int power10[]={1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
void calculate(int num,int d,int fzero)
{
    // first digit in num
    int i,n = num / power10[d];
    cnt = power10[d]; //effect of n
    cnt[n] = num % power10[d] + 1;//effect of remaining digits
    if(fzero)
        cnt -= power10[d];  //extra effect once (effect of n)
    if(d==0)
        return ;    //base case

    cnt += n*d*power10[d-1];//everytime performed
    
    if(fzero)
        cnt -= (power10[d]-1)/9; //extra zero once effect of everytime
    

}
int main()
{
    int t,a,b;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&a,&b);
        a -= 1;
        cnt = 1;
        d = (int)floor(log10(a));  //(nod - 1)  in a 
        calculate(a,d,1);
        
    }
    return 0;
}

