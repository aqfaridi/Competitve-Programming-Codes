#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define min(a,b) (a<b)?a:b
using namespace std;
int main()
{
    
    int t,n,m,k,minimum;
    scanf("%d",&t);
    while(t--)
    {
        minimum=1000000;
        scanf("%d %d %d",&n,&m,&k);
        int **p=new int*[n];
        for(int i=0;i<n;i++)
            p[i]=new int[m];



        int **q=new int*[n];
        int *count =new int[n];
        
        for(int i=0;i<n;i++)
        {
            q[i]=&p[i][m-1];
            count[i]=0;
        }

        

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                scanf("%d",&p[i][j]);
            }
        }
        int z;

        for(int gift=0;gift<k;gift++)
        {
            for(int i=0;i<n;i++)
            {
                minumum=min(p[i][0],p[i][m-1]);
                if(min(p[i][0],p[i][m-1]) < minimum )
                {z=i;count[i]++;}
            }

            if(minimum==p[z][count[z]])
                p[z]++;
            else if(minimum==p[z][])

            
        }
    }
    return 0;
}

