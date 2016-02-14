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
bool flag;
int arr[MAX];
namespace KMP
{
    int b[MAX],m,n;
    void LPS(string pat)
    {
        int i=0,j=-1;//j => border
        m = pat.length();
        b[i] = j;
        while(i<m)
        {
            while(j>=0 && pat[i]!=pat[j]) j=b[j];//next widest border
            i++;j++;
            b[i] = j;
        }
    }
    void kmpSearch(string pat,int len)
    {    
        int i=1,j=0,z;
        n = len;
        while(i<n)
        {
            while((j>=0) && ( (pat[j]=='G')?(arr[i]<arr[i-1]):(arr[i]>arr[i-1]) ) && ((pat[j]=='E')?(arr[i]!=arr[i-1]):1) ){ j=b[j];}
            i++;j++;
            if(j==m)
            {
                //printf("%d\n",(i-j));
                flag = true;
                break;
                //j = b[j]; //widest border of pat
            }
            b[i] = j;
        }

    }
}
using namespace KMP;
int main()
{
    int t,n,hell,var;
    string str;
    cin>>t;
    while(t--)
    {
        flag = false;
        cin>>n;
       
        for(int i=0;i<n;i++)
            cin>>arr[i];        
        cin>>str;
        if(n==1 && str.length()==1)            
        {
            cout<<"YES"<<endl;
            continue;
        }
        LPS(str);
        kmpSearch(str,n);
        if(flag)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
