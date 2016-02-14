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

#define MAX 1000100
#define MOD 1000000007    
int sarr[30],tarr[30];
void max_cons(char* str,int arr[])
{
    int l1 = strlen(str),cnt;
    char temp;
    temp = str[0];arr[temp-'a'] = 1;cnt = 1;
    for(int i=1;i<l1;i++)
    {
        if(str[i] == temp)
            cnt++;
        else
        {
            if(cnt > arr[temp-'a'])
                arr[temp-'a'] = cnt;
            temp = str[i];
            cnt = 1;
        }
    }
    if(cnt > arr[temp -'a'])
        arr[temp-'a'] = cnt;
   /* 
    for(int i=0;i<=25;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    */
}
char s[MAX],t[MAX];
int main()
{
    //ios::sync_with_stdio(false);
    int test,n,maxx;
  
    scanf("%d",&test);
    while(test--)
    {
        memset(sarr,0,sizeof(sarr));
        memset(tarr,0,sizeof(tarr));
        maxx = -1;
        scanf("%s",s);
        scanf("%s",t);
        max_cons(s,sarr);
        max_cons(t,tarr);
        for(int i=0;i<26;i++)
            maxx = max(maxx,sarr[i]+tarr[i]);
        printf("%d\n",maxx);
    }
    return 0;
}
