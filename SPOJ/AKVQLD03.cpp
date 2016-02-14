#include <iostream>
#include <cstring> 
using namespace std;
#define MAXX 4000000
int tree[MAXX],MAX;
void update(int idx,int val)
{
    while(idx<=MAX)
    {
        tree[idx] += val;
        idx += (idx & -idx);
    }
}
int sum(int idx)
{
    int sum = 0;
    while(idx>0)
    {
        sum += tree[idx];
        idx -= (idx & -idx);
    }
    return sum;
}
int main()
{
    ios::sync_with_stdio(false);
    int n,q,a,b;
    string str;    
    cin>>n>>q;
    MAX = n;
    while(q--)
    {
        cin>>str>>a>>b;
        if(!str.compare("find"))
            cout<<sum(b) - sum(a-1)<<endl;
        else     
            update(a,b);        
    }
}




