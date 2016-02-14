#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <vector>
#include <iomanip>
#include <cmath> 
#include <map>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

int main()
{
    ios::sync_with_stdio(false);
    int t,n,num;
    cin>>t;
    while(t--)
    {
        cin>>n;
        map<int,int> m;
        for(int i=0;i<n;i++)
        {
            cin>>num;
            m[num]++;
        }
        
        map<int,int>::iterator it;
        int element,maxx = -1;
        for(it = m.begin() ; it != m.end() ; it++)        
        {
            //cout<<it->first << " " << it-> second<<endl;
            if(it->second  > maxx)
            {
                maxx = it->second;
                element = it->first;
            }
        }
        cout<<element<<endl;
        
    }
    return 0;
}


