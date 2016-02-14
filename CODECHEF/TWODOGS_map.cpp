#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <vector>
#include <iomanip>
#include <cmath> 
#include <map>
#include <climits>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

#define MAX 1000010
#define MOD 1000000007  
map<int,int> m;
void display()
{
    map<int,int>::iterator it = m.begin();
    while(it != m.end())
    {
        cout<<it->first<<" "<<it->second<<endl;
        it++;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    int var,t,n,k,idx1,idx2,minn;
    t = 1;
    while(t--)
    {
        minn = INT_MAX;
        cin>>n>>k;
        for(int i=0;i<n;i++)
        {
            cin>>var;
            if(m[var])
                m[var] = min(m[var],min(i+1,n-i));
            else
                m[var] = min(i+1,n-i);
        }
        //display();
        for(int i=k;i>=k/2;i--)
        {
            if(i != (k-i))
            {
                idx1 = m[i];
                idx2 = m[k-i];
                if(idx1 !=0 && idx2 != 0)
                    minn = min(minn,max(idx1,idx2));
            }
        }
        if(minn != INT_MAX)
            cout<<minn<<endl;
        else
            cout<<-1<<endl;
    }
    return 0;
}
