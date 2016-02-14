#include <iostream>
using namespace std;
int score[10010];
int p[10010];
int owner(int x)
{
    if(p[x] == x)
        return x;
    else
        return p[x] = owner(p[x]);
}
int main()
{
    ios::sync_with_stdio(false);
    int t,x,y,n,query,c;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>score[i];
            p[i] = i;
        }
        cin>>query;
        while(query--)
        {
            cin>>c;
            if(c == 0)
            {
                cin>>x>>y;
                int ox = owner(x);int oy = owner(y);
                if(ox == oy){cout<<"Invalid query!"<<endl;continue;}
                if(score[ox] > score[oy])          
                    p[oy] = ox;
                else if(score[ox] < score[oy])     
                    p[ox] = oy;
            }
            else
            {
                cin>>x;
                cout<<owner(x)<<endl;
            }
        }
    }
    return 0; 
}
