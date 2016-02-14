#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main()
{
    int t,n,k,num;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&k);

        vector<int> v[n];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<k;j++)
            {
                scanf("%d",&num);
                v[i].push_back(num);
            }
        }

        for(int i=1;i<n;i++)
        {
            for(int j=1
        }

        vector<int> A;
        for(int j=0;j<k;j++)
        {
            scanf("%d",&num);
            A.push_back(num);
        }
        vector<int> sum(k,0),idx;
        bool flag,out=true;
        for(int i=0;i<n;i++)
        {
            flag = true;
            for(int j=0;j<k;j++)
            {
                if(sum[j]+v[i][j] > A[j])
                {
                    flag = false;
                    break;
                }              
                else
                {
                    sum[j] += v[i][j];        
                }
            }   
            if(flag)
                idx.push_back(i+1);
            
        }

        int sz=idx.size();
        if(sz)
        {
            printf("%d\n",sz);
            for(int i=0;i<sz;i++)
                printf("%d ",idx[i]);
            printf("\n");
        }
        else
            printf("0\n");
    }
    return 0;
}
