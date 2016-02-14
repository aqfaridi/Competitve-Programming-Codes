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

#define MAX 200
#define MOD 1000000007    
double W[MAX][MAX],A[MAX][MAX],B[MAX][MAX];
int main()
{
    //ios::sync_with_stdio(false);
    int t,n;
    t = 1;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>W[i][j];

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                A[i][j] = (W[i][j]+W[j][i])/2.0;
                printf("%.8lf ",A[i][j]);
            }
            printf("\n");
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                B[i][j] = (W[i][j] - A[i][j]);
                printf("%.8lf ",B[i][j]);
            }
            cout<<endl;
        }
    }
    return 0;
}
