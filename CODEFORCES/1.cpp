#include<bits/stdc++.h>
using namespace std;
int main(){
    int y , k , n,j=2;
    bool b = false;
    cin>>y>>k>>n;

    if(k == 1)
    {
        for(int i=1;i<=n-y;i++) 
        {
            cout<<i<<" ";
            b = true;
        }
    }
    else
        for(int i=k;i<=n;i+=k)
        {
            if(i-y>0)
            {
                cout<<i-y<<" " ;
                b = true;
            }
        }

    if(!b)
           cout<<-1<<endl;
    return 0;
}

