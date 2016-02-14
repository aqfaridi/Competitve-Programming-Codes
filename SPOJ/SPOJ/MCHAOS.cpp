#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define MAX 100010
using namespace std;
string a[MAX],b[MAX];
bool cmp(int x,int y)
{
    return (a[x] < a[y]);
}
bool cmp1(int x,int y)
{
    return (b[x] < b[y]);
}
int tree[MAX];
void update(int idx)
{
    // finding any greater number before idx
    while(idx>0)
    {
        tree[idx] += 1;
        idx -= (idx & -idx);
    }
}
int query(int idx)
{
    int sum = 0 ;
    while(idx<MAX)
    {
        sum += tree[idx];
        idx += (idx & -idx);
    }
    return sum;
}
int main()
{
    int n,cnt = 0;
    int pos1[MAX],pos2[MAX],pos3[MAX];
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        b[i] = string(a[i].rbegin(),a[i].rend());  // reverse string of a[i] in b[i]   
       // cout<<a[i]<<" "<<b[i]<<endl;
        pos1[i] = pos2[i] = i;
  
    }
    sort(pos1,pos1+n,cmp);
    sort(pos2,pos2+n,cmp1);//positioning according to string lexo order
    for(int i=0;i<n;i++)
    {
        cout<<pos1[i]<<" "<<pos2[i]<<endl;
    }
    for(int i=0;i<n;i++)
    {
        pos3[i] = pos1[pos2[i]];
        pos3[i] += 1; // since 0 is not used for binary indexing 
        cout<<pos3[i]<<endl;
    }
    for(int i=0;i<n;i++)
    {
        cnt += query(pos3[i]);
        update(pos3[i]);
    }
    printf("%d\n",cnt);
    return 0;
}

