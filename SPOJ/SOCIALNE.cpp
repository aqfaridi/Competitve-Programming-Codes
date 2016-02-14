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

#define MAX 100010
#define MOD 1000000007    
vector<int> v[60],check;
int visited[60];
int matrix[60][60];
set<int> f,mutual;
int cnt,PP;
void DFS(int node,int dist)
{ 
    if(dist == 3 and !matrix[PP][node])
        cnt++;

    visited[node] = dist;
    int size = v[node].size(),u;
    for(int i=0;i<size;i++)
    {
        u = v[node][i];
        if(!visited[u] and dist < 3)
            DFS(u,dist+1);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    int t,size,l,n,maxx,frnd,person,setsize;
    string s[60];
    cin>>t;
    while(t--)
    {
        memset(matrix,0,sizeof matrix);
        maxx = 0;
        cin>>s[0];
        l = s[0].length();
        for(int i=0;i<l;i++)
            v[i].clear();

        for(int i=0;i<l;i++)
        {
            if(s[0][i] == 'Y')
            {
                v[0].push_back(i);
                v[i].push_back(0);
                matrix[0][i]=matrix[i][0]=1;
            }
        }
        
        for(int i=1;i<l;i++)
        {
            cin>>s[i];
            for(int j=0;j<l;j++)
            {
                if(s[i][j] == 'Y')
                {
                    v[i].push_back(j);
                    v[j].push_back(i);
                    matrix[i][j]=matrix[j][i]=1;
                }
            }
        }
        person=0;
        for(int i=0;i<l;i++)
        {
            PP=i;
            cnt = 0;
            memset(visited,0,sizeof(visited));
            DFS(i,1);
            if(cnt > maxx)
            {
                maxx = cnt;
                person = i;
            }
        }
        cout<<person<<" "<<maxx<<endl;
/*

        for(int i=0;i<l;i++)
        {
            size = v[i].size();
            mutual.clear();
            check.clear();
            f.clear();
            for(int j=0;j<size;j++)
            {
                //friends v[i][j];
                frnd = v[i][j];
                f.insert(frnd);
                n = v[frnd].size();
                for(int k=0;k<n;k++)
                {
                    //mutual friend v[frnd][k]
                    mutual.insert(v[frnd][k]);
                }
            }
            
            set_intersection(f.begin(),f.end(),mutual.begin(),mutual.end(),check.begin());
            setsize = check.size();
            //set<int>::iterator it = st.begin();
            //cout<<"he";
            //for(;it != st.end(); it++)
              //  cout<<(*it)<<" ";
            //cout<<endl;
            if(setsize > maxx)
            {
                maxx = setsize;
                person = i;
            }
        }
        cout<<person<<" "<<maxx<<endl;
*/        
    }
    return 0;
}
