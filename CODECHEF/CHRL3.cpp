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
vector<int> v;
int main()
{
    ios::sync_with_stdio(false);
    int temp,n,var,cnt=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>var;
        v.push_back(var);
    }
    while(v.size())
    {
        temp=v[0];
        v.erase(v.begin());

        for(int i=0;i<v.size();i++)
        {
            if(v[i]>temp)
            {
                temp = v[i];
                v.erase(v.begin()+i);
                i--;
            }
        }
        cnt++;
     }

     cout<<cnt<<endl;
     return 0;
}
