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
vector<LL> v;
int visited[MAX];
int main()
{
    ios::sync_with_stdio(false);
    int start,t,n,cnt;
    LL num;
    bool found;
    cin>>t;
    while(t--)
    {
        memset(visited,0,sizeof(visited));
        cin>>n;
        v.clear();
        for(int i=0;i<n;i++)
        {
            cin>>num;
            v.push_back(num);
        }
        sort(v.begin(),v.end(),greater<LL>());
        
        start = cnt = 0;
        for(int i=0;i<n;i++)
        {
            if(visited[i]) continue;
            found = false;
            for(int j=start;j<n;j++)
            {
                if((!visited[j]) && ((v[i] == 2*v[j]) || (v[i] == (2*v[j]+1))))
                {
                    found = true;
                    visited[j] = true;
                    start = j+1;
                    cnt++;
                    break;
                }
            }
            if(!found)  break;
        }
        cout<<cnt<<endl;
    }
    return 0;
}






