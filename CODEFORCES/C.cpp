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
template<class T>
class BIT
{
    T *tree1,*tree2;
    int maxVal;
    public:
    BIT(int N)
    {
        tree1 = new T[N+1];
        tree2 = new T[N+1];
        memset(tree1,0,sizeof(T)*(N+1));
        memset(tree2,0,sizeof(T)*(N+1));
        maxVal = N;
    }
    void update(int idx,T val)
    {
        int var = idx - 1; // var can be a or b
        while(idx <= maxVal)
        {
            tree1[idx] += val;
            tree2[idx] += val*var;
            idx += (idx & -idx);
        }            
    }
    void update_range(int a,int b,T val)
    {
        update(a,val);
        update(b+1,-val);
    }
    T cumm_freq(int idx)
    {
        T sum1 = 0,sum2 = 0;
        int p = idx;
        while(idx > 0)
        {
            sum1 += tree1[idx];
            sum2 += tree2[idx];
            idx -= (idx & -idx);
        }
        return (sum1 * p - sum2);
    }
    T get_freq(int idx)
    {
        T freq = 0;
        while(idx > 0)
        {
            freq += tree1[idx];
            idx -= (idx & -idx);
        }
        return freq;
    }
};
int main()
{
    int n,m;
    cin>>n>>m;
    BIT<int> B(n+1);
    for(int i=1;i<=m;i++)
    {
        
    
    }
    return 0;
}
