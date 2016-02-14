#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <vector>
#include <iomanip>
#include <cmath> 
#include <climits>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
typedef pair< pii , int > tri;
#define MAX 1010
#define MOD 1000000007    
int B[MAX][MAX];
int arr[MAX],visited[MAX];
vector< pii > v;
void display()
{
    for(int i=0;i<v.size();i++)
        cout<<v[i].first<<" "<<v[i].second<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    int maxx,diff,t,n,m,idx,k,var,size;
    LL sum;
    cin>>t;
    while(t--)
    {
        v.clear();
        memset(visited,0,sizeof(visited));
        sum = 0;
        cin>>n>>m>>k;
        for(int i=1;i<=n;i++)        
            cin>>arr[i];
        
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                cin>>B[i][j];
        for(int i=1;i<=n;i++)
        {
            maxx = -INT_MAX;
            for(int j=1;j<=m;j++)                
            {
                cin>>var;
                B[i][j] -= var;
                if(j==(arr[i]))
                    continue;
                maxx = max(maxx,B[i][j]);
            }
            if(maxx > B[i][arr[i]])
            {
                diff = maxx - B[i][arr[i]];
                v.push_back(make_pair(diff,i));
            }
        }
        sort(v.begin(),v.end(),greater< pii >());
        //display();
        size = v.size();
        for(int i=0;i<min(size,k);i++)
        {
            idx = v[i].second;
            sum += (v[i].first + B[idx][arr[idx]]);
            visited[idx] = 1;
        }
       
        for(int i=1;i<=n;i++)
        {
            if(!visited[i])
                sum += B[i][arr[i]];
        }
        cout<<sum<<endl;
    }
    return 0;
}
