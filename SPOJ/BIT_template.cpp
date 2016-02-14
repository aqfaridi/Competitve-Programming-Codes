#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
template<class T>
class simpleBIT
{
    T *tree;
    int maxVal;
    public:
    simpleBIT(int N)
    {
        tree = new T[N+1];
        memset(tree,0,sizeof(T)*(N+1));
        maxVal = N;
    }
    void update(int idx,T val)
    {
        while(idx <= maxVal)
        {
            tree[idx] += val;
            idx += (idx & -idx);
        }
    }
    
    T query(int idx)
    {
        T sum = 0;
        while(idx > 0)
        {
            sum += tree[idx];
            idx -= (idx & -idx);
        }
        return sum;
    }
    
    T readSingle(int idx)
    {
        T sum = tree[idx];
        if(idx > 0)
        {
            int z = idx - (idx & -idx);
            idx--;
            while(idx != z)
            {
                sum -= tree[idx];
                idx -= (idx & -idx);
            }
        }
        return sum;
    }
};

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
    int t,ch,N,C,a,b,val;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&N,&C);
        BIT<long long> bit(N);
        for(int i=0;i<C;i++)
        {
            scanf("%d",&ch);
            if(ch == 0)
            {
                scanf("%d %d %d",&a,&b,&val);
                //cout<<a<<" "<<b<<" "<<val<<endl;
                bit.update_range(a,b,val);
            }
            else
            {
                scanf("%d %d",&a,&b);
                //cout<<a<<" "<<b<<endl;
                printf("%lld\n",bit.cumm_freq(b) - bit.cumm_freq(a-1));
            }
        }
    }

    return 0;
}
