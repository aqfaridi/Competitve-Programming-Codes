#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <vector>
#include <iomanip>
#include <cmath> 
#include <map>
#include <set>

using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

#define MAX 100010
#define MOD 1000000007    
int arr[MAX];
map<int,int> mp;
set<int> s;
int main()
{
    ios::sync_with_stdio(false);
    int t,n,q,a,b,k;
    cin>>t;
    while(t--)
    {
        mp.clear();
        s.clear();
        cin>>n>>q;
        k = 0;
        int prev = 0;
        set<int>::iterator it;
        for(int i=0;i<q;i++)
        {
            cin>>a>>b;
            if(a == 1)
            {
                it = s.find(b);
                if(it == s.end())
                   k++;
                if(prev != b)
                    k++;
                mp[b] = k;
                s.insert(b);
            }
            else if(a==2)
            {
                //cout<<k<<" "<<n<<endl;
                //cout<<mp[b]<<" "<<k-n<<endl;
                if(mp[b]>0 && mp[b] > k-n)
                    cout<<"YES"<<endl;
                else
                    cout<<"NO"<<endl;
            }
            prev = b;
        }
    }
    return 0;
}
