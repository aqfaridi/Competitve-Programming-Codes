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

#define MAX 10010
#define MOD 1000000007    
char str[MAX];
int main()
{
    ios::sync_with_stdio(false);
    int t,num,l;
    string src,ans;
    cin>>t;
    while(t--)
    {
        num = 0;
        src ="";
        ans ="";
        gets(str);
        //scanf("%[^\n]s",str);
        char *p = strtok(str,"\"");
        char *q;
        int i=1;
        while(p != NULL)
        {
            //cout<<p<<endl;
            if(i==2)
                src = p;
            if(i==4)
            {
                q = strtok(p,";");
                while(q != NULL)
                {
                    num = 0;
                    //cout<<q<<endl;
                    l = strlen(q);
                    for(int i=2;i<l;i++)
                        num = num*10 + (q[i]-'0');
                    ans += (char)num;
                    q = strtok(NULL,";");
                }
            }
            p = strtok(NULL,"\"");
            i++;
        }
        cout<<"Source = "<<src<<endl;
        cout<<"Alt = "<<ans<<endl;
    }
    return 0;
}
