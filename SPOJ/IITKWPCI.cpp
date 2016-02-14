#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <vector>
#include <iomanip>
#include <cmath> 
#include <set>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
set<int> s;
vector<int> v;
int arr[100010];
int main()
{
    int t,n,m,a,b;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        v.clear();
        s.clear();
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int i=0;i<m;i++)
        {
            cin>>a>>b;
            a-=1;b-=1;
            s.insert(a);
            s.insert(b);
        }

        set<int>::iterator it=s.begin();
        for(;it!=s.end();it++)
            v.push_back(arr[(*it)]);
        
        sort(v.begin(),v.end());

        it=s.begin();
        int k=0;
        for(int i=0;i<n;i++)
        {
            if(i == (*it))
            {
                arr[i] = v[k++];
                it++;
            }
        }

        for(int i=0;i<=n-2;i++)
            cout<<arr[i]<<" ";
        cout<<arr[n-1]<<endl;
    }
    return 0;
}
