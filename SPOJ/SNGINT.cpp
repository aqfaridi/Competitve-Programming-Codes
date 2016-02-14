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

int main()
{
    ios::sync_with_stdio(false);
    int t,n,pro,N;
    string str;
    cin>>t;
    while(t--)
    {
        cin>>n;
        N = n;
        if(n==1)
        { cout<<n<<endl;continue; }
        if(n==0)
        { cout<<10<<endl;continue;}
        str = "";
        pro = 1;
        for(int i=9;i>=2;i--)
        {
            while(n % i ==0)
            {
                n/=i;
                str += (i+'0');
                pro *= i;
            }
        
        }
        reverse(str.begin(),str.end());
        if(pro == N)
        	cout<<str<<endl;
        else
        	cout<<-1<<endl;
    }
    return 0;
}

