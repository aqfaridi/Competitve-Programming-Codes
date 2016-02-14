#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <climits>
#include <cassert>
#include <iomanip>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>
#include <complex>
#include <numeric>
#include <functional>
#include <sstream>
#include <algorithm>
#define MAX 10010
#define MOD 1000000000
using namespace std;
typedef long long LL;
typedef unsigned long long uLL;
int input[MAX];
int fibo[]={1,1,2 , 3 , 5 , 8 , 13 , 21 , 34 , 55 , 89 , 144 , 233 , 377 , 610 , 987 , 1597 , 2584 , 4181 , 6765 , 10946 , 17711 , 28657 , 46368 , 75025 , 121393 , 196418 , 317811 , 514229 , 832040 , 1346269 , 2178309 , 3524578 , 5702887 , 9227465 , 14930352 , 24157817 , 39088169 , 63245986 , 102334155 , 165580141 , 267914296 , 433494437 , 701408733 , 134903170 , 836311903 , 971215073 , 807526976 , 778742049 , 586269025 , 365011074 , 951280099 , 316291173 , 267571272 , 583862445 , 851433717 , 435296162 , 286729879 , 722026041 , 8755920 , 730781961 , 739537881 , 470319842 , 209857723 , 680177565 , 890035288 , 570212853 , 460248141 , 30460994 , 490709135 , 521170129 , 11879264 , 533049393 , 544928657 , 77978050 , 622906707 , 700884757 , 323791464 , 24676221 , 348467685 , 373143906 , 721611591 , 94755497 , 816367088 , 911122585 , 727489673 , 638612258 , 366101931 , 4714189 , 370816120 , 375530309 , 746346429 , 121876738 , 868223167 , 990099905 , 858323072 , 848422977 , 706746049 , 555169026 , 261915075 , 817084101 , 78999176 };
int main()
{
    int t,n,m;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n,&m);
        for(int i=1;i<=n;i++)
            scanf("%d",&input[i]);
        
        for(int i=0;i<m;i++)
        {
            long long ans = 0LL;
            scanf("%d %d %d",&t,&l,&r);
            if(t==1)
                input[l] = r;
            else if(t==2)
            {
                int k=0;
                for(int x=l;x<=r;x++)
                    ans += ((fib[k++]*arr[x])%MOD);
                printf("%lld\n",ans);
            }
            

        }
    }
    return 0;
}
