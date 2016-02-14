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
    long long x,y,m,step,num;
    cin>>x>>y>>m;
    if(x>=m || y>=m)
        cout<<0<<endl;
    else if(x<=0 && y<=0)
        cout<<-1<<endl;
    else if(x<m && y<m)
    {
        if(m>=0)
        {
            if((x < 0 && y>0))
            {
                step = (long long int)ceil((-1.0*x)/y);
                num = (step*y)+x;
                cout<< step + (long long int)ceil(((m-num)*(1.0))/y) <<endl;

            }
            else if (y<0 && x>0)
            {
                                
                step = (long long int)ceil((-1.0*y)/x);
                num = (step*x)+y;
                cout<< step + (long long int)ceil(((m-num)*(1.0))/x) <<endl;
            }
            else if (x>=0 && y>=0)
            {
                if(x<y)
                {
                    cout<<(long long int)ceil(((m-x)*1.0) / y) << endl;
                }
                else
                {
                                        
                    cout<<(long long int)ceil(((m-y)*1.0) / x) << endl;
                }
            }
        }
    }
    return 0;
}

