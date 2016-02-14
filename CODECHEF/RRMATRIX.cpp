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
int rowmajor[1010][1010],colmajor[1010][1010];
int main()
{
    long long t,n,m,cnt;
    cin>>t;
    while(t--)
    {
        cnt = 0;
        cin>>n>>m;
  n = 26;    
  for(m=1 ;m<=n;m++)
  {
        int num = 1;
        cnt = 0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                rowmajor[i][j] = num++;
            }
        }
        num=1;
        for(int j=1;j<=m;j++)
        {
            for(int i=1;i<=n;i++)
            {
                colmajor[i][j] = num++;
            }
        }
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(rowmajor[i][j] == colmajor[i][j])
                {
                    cnt++;
                    //cout<<rowmajor[i][j]<<" ";
                }
            }
        }
        cout<<"  "<<cnt<<"  ";
/*
        if(n==m)
            cout<<n<<endl;
        else if(n==1 && m!=1)
            cout<<m<<endl;
        else if(m==1 && n!=1)
            cout<<n<<endl;
        else if(m>=n && m%(n-1)==1)
            cout<<n<<endl;           
        else    
            cout<<2<<endl;
 */ }     
    }
    return 0;
}


