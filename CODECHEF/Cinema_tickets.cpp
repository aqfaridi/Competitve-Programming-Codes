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
#define MAX 1010
#define MOD 1000000007
int arr[MAX][MAX];
int main()
{
    ios::sync_with_stdio(false);
    int t,n,m,p,q,cnt=0;
    string str;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        cin>>p>>q;
        for(int i=0;i<n;i++)
        {    cin>>str;
            for(int j=0;j<str.length();j++)
            {
                arr[i+1][j+1]=0;
                if(str[j]=='#')
                    arr[i+1][j+1]=arr[i+1][j]+1;
            }
        }
        vector< pii > v;
        v.clear();
        for(int j=m;j>=1;j--)
        {
            cnt=0;
            for(int i=n;i>=1;i--)
            {
                if(arr[i][j]>=q)
                    cnt++;
                else
                    cnt=0;
                if(cnt==p)
                {
                       v.push_back(make_pair((i-1),(j-q)));
                       cnt--;
                }
            }
        }
         
        int size=v.size();
        sort(v.begin(),v.end());
        cout<<size<<endl;
        for(int i=0;i<size;i++)
        {
            cout<<v[i].first<<" "<<v[i].second<<endl;
        
        }

    }
    return 0;
}
