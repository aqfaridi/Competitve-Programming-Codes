#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAX 1010
int permut[MAX],visited[MAX];
int ans[MAX][MAX];
vector<int> v;
int main()
{
    ios::sync_with_stdio(false);
    int t,n,m,trp,sz,give,prev;
    bool flag,ns;
    cin>>t;
    while(t--)
    {
        memset(visited,0,sizeof(visited));
        memset(ans,0,sizeof ans);
        cin>>n>>m;
        flag = ns = false;
        for(int i=0;i<n;i++)
        {
            cin>>permut[i];
            if(permut[i] == i)
                flag = false;
        }
        
        if(flag || n<2 ||  m<2){cout<<"No Solution"<<endl;continue;}
       
        give = 1;
        for(int i=0;i<n;i++)
        {
            trp = i;
            v.clear();
            if(!visited[i])
            {
                do{
                    v.push_back(trp);
                    visited[trp] = 1;
                    trp = permut[trp];
                }while(trp != i);
                reverse(v.begin(),v.end());
                sz = v.size();
                if(sz == 2) ns = true;
                for(int k=0;k<m;k++)
                {
                    int j = k%sz;
                    ans[v[j]][k] = give++;                        
                    if(k >=1) 
                        swap(ans[prev][k-1] , ans[v[j]][k]);
                    j++;
                    for(;;j++)
                    {
                        if(ans[v[j%sz]][k] != 0){ prev = v[(j-1+sz)%sz];  break;}
                        ans[v[j%sz]][k] = give;
                        give++;
                    }
                }
            }
        }
      

        if(ns){cout<<"No Solution"<<endl;continue;}

        for(int i=0;i<n;i++)
            sort(ans[i],ans[i]+m);
        
        for(int i=0;i<n;i++)
        {
            cout<<ans[i][0];
            for(int j=1;j<m;j++)
                    cout<<" "<<ans[i][j];
            cout<<endl;
        }
    }
    return 0; 
}
