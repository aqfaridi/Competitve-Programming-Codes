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
int arr[100010];
int main()
{
    int t,n,flight,sal,cases=0;
    LL sum,loss;
    scanf("%d",&t);
    while(t--)
    {
        cases++;
        scanf("%d %d %d",&n,&flight,&sal);
        //permissible_stay = (int)floor((2*flight) / sal);
        for(int i=0;i<n;i++)
            scanf("%d",&arr[i]);
        sum = 2*flight + sal;
        for(int i=0;i<n;i++)
        {
            if(i+1 < n)
            {
                loss = (arr[i+1] - arr[i]) * sal ;
                if(loss <= (2*flight))
                    sum += loss;
                else
                    sum += (2*flight + sal);
            }
        }
        cout<<"Case #"<<cases<<": "<<sum<<endl;
        
    }
    return 0;
}

