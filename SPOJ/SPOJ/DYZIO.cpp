#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define MAX 20010
using namespace std;
char str[MAX];
int cut;
void build(int b,int e)
{
    int mid;
    if(b==e)
        return;
    if(str[b]=='1')
    {
        cut++;
        mid = (b+e)/2;
        build(b,mid);
        build(mid+1,e);
    }
}
int main()
{
    int n;
    ios::sync_with_stdio(false);
    while(scanf("%d",&n) != EOF)
    {
        cut = 0; 
        scanf("%s",str+1);
        build(1,n);
        cout<<cut<<endl;
    }
    return 0;
}

