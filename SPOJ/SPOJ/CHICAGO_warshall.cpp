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
#define MAX 110
#define MOD 1000000007
using namespace std;
typedef long long LL;
typedef unsigned long long uLL;
double prob[MAX][MAX];
int main()
{
    int N,M,u,v,cost;
    while(1)
    {
        scanf("%d",&N);
        if(N==0)    break;
        memset(prob,0.0,sizeof prob);
        scanf("%d",&M);
        for(int i=0;i<M;i++)
        {
            scanf("%d %d %d",&u,&v,&cost);
            //undirected
            prob[u][v] = prob[v][u] = cost/100.0 ;
        }
        //warshall algo
        for(int k=1;k<=N;k++)
            for(int i=1;i<=N;i++)
                for(int j=1;j<=N;j++)
                    prob[i][j] = max(prob[i][j],prob[i][k]*prob[k][j]);

        printf("%.6lf percent\n",prob[1][N]*100.0 + 1e-10);
    }
    return 0;
}

