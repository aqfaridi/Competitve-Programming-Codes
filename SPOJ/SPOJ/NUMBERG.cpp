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
#define MAX 1000010
#define MOD 1000000007
using namespace std;
typedef long long LL;
typedef unsigned long long uLL;
int main()
{
    int t,n,num,numm,nof5,nof2;
    scanf("%d",&t);
    while(t--)
    {
        nof5 = nof2 = 0;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&num);
            numm = num;
            while(num % 2 == 0)
            {
                num /= 2;
                nof2++;
            }
            while(numm %5 == 0)
            {
                numm /= 5;
                nof5++;
            }
        }
        printf("%d\n",min(nof2,nof5));
    }
    return 0;
}

