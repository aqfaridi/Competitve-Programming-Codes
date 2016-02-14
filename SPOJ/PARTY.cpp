#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define MAX 2010
typedef unsigned long long int LL;
using namespace std;
int w[MAX],v[MAX];
int main()
{
    int W,n,K;
    while(1)
    {
    scanf("%d %d",&W,&n);
    if(W==0 && n==0)
        break;
    for(int i=1;i<=n;i++)
        scanf("%d %d",&w[i],&v[i]);
     
    
    LL V[n+1][W+1],sum;
    bool keep[n+1][W+1];
    for(int j=0;j<=W;j++)
        V[0][j] = 0;
    for(int i=0;i<=n;i++)
        V[i][0] = 0;

    for(int i=1;i<=n;i++)//choosing i items for capacity j
    {
        for(int j=1;j<=W;j++)
        {
            
            if((w[i] <= j) && (v[i]+V[i-1][j-w[i]] >= V[i-1][j]))// w[i]<=j we choose ith item   :::: j is subproblem limit
            {
                V[i][j] = v[i] + V[i-1][j-w[i]];
                keep[i][j] = 1;
            }
            else 
            {
                V[i][j] = V[i-1][j];
                keep[i][j] = 0;
            }
            //cout<<V[i][j]<<" ";
        }
        //cout<<endl;
    }
    /**
    K = W ;
    sum = 0;
    for(int i=n;i>=1;i--)
    {
        if(keep[i][K]==1)
        {
            sum += w[i] ;
            K = K - w[i] ;
        }
    }**/
    //dont need to keep track of all the choosen items 
    //in this question we have to only find out the minimum budget
    //which give maximum fun
    int i,best;
    for( i=W,best=V[n][W];i>0;i--)
        if(V[n][i] < best)
            break;
    cout<<i+1<<" "<<V[n][W]<<endl;
    }
    return 0;
}

