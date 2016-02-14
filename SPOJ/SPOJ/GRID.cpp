#include <iostream>
#include <cstdio>
using namespace std;
int m,n,count,cnt=0;
void func(int x,int y)
{
    cnt++;
    /*
    cout<<count<<" ";
    cnt++;
    if(cnt==10)
        return ;
    cout<<x<<" "<<y<<" ";
    */
    if(x == m && y == n)
    {count++;return;}

    if(x < m)
        func(x+1,y);
    if(y < n)
        func(x,y+1);
}
int main()
{
    int t,k;
    scanf("%d",&t);
    while(t--)
    {
        count=0;
        scanf("%d %d %d",&m,&n,&k);
        func(0,0);
        printf("%d\n",count%k);
        cout<<cnt;
    }
    return 0;
}
