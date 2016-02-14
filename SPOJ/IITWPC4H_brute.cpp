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

#define MAX 30
#define MOD 1000000007    
int sarr[MAX],tarr[MAX];
void max_cons(string str,int arr[])
{
    int l1 = str.length(),cnt;
    for(int i=0;i<l1;i++)
    {
        cnt = 1;
        while((i+1<l1) && str[i]==str[i+1])
        {
            cnt++;
            i++;
        }
        if((str[i]-'a'<=25) && (str[i]-'a' >=0))
        {
            if(arr[str[i]-'a'] < cnt)
                arr[str[i]-'a'] = cnt;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    int test,n,maxx;
    string s,t;
    cin>>test;
    while(test--)
    {
        memset(sarr,0,sizeof(sarr));
        memset(tarr,0,sizeof(tarr));
        maxx = -1;
        cin>>s>>t;
        max_cons(s,sarr);
        max_cons(t,tarr);
        for(int i=0;i<26;i++)
            maxx = max(maxx,sarr[i]+tarr[i]);
        cout<<maxx<<endl;
    }
    return 0;
}

