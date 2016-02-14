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

#define MAX 100010
#define MOD 1000000007    
char arr[1010][1010];
int main()
{
    ios::sync_with_stdio(false);
    int t,n,m;
    string str;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(int i=0;i<n;i++)
        {
            cin>>str;
            for(int j=0;j<m;j++)
               arr[i][m-1-j] = str[j]; 
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                cout<<arr[i][j];
            cout<<endl;
        }
    }
    return 0;
}
