#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <set>
#include <map>
#include <queue>

using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

#define pb push_back
#define mp make_pair
#define sz size()
#define ln length()
#define forr(i,a,b)                 for(int i=a;i<b;i++)
#define rep(i,n)                    forr(i,0,n)
#define all(v)                      v.begin(),v.end()
#define uniq(v)                     sort(all(v));v.erase(unique(all(v)),v.end())
#define clr(a)                      memset(a,0,sizeof a)

#define debug                       if(1)
#define debugoff                    if(0)

#define print(x)                 cerr << x << " ";
#define pn()                     cerr << endl;
#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;

#define MAX 100010
#define MOD 1000000007
char st[100];
int tym[10];
int main()
{
    int tc,n,k,l,cases=0;
    string in;
    double t,D;
    cin>>tc;
    while(tc--)
    {
        cases++;
        t = 0.0;
        k = 0;
        cin>>D;
        scanf("%s",st);
        char *ch = strtok(st,":");
        while(ch != NULL)
        {
            tym[k++] = atoi(ch);
            ch = strtok(NULL,":");
        }
        cin>>in;
        l = in.length();
        for(int i=0;i<l;i++)
        {
            if(in[i] == 'R')
                t += 0.5;
            else
                t += 0.625;
        }

        int ti = (int)(t);
        double tm = t - ti;
        int sec = tm * 3600;
        int min = sec/60;
        int sc = sec - min*60;
        //trace3(ti,min,sc);
        //tym[0] = (tym[0]+ti)%24;
        tym[2] += sc;
        tym[1] += min;
        tym[0] += ti;

        tym[1] += (tym[2]/60);
        tym[2] = (tym[2])%60;

        tym[0] += (tym[1]/60);
        tym[1] = (tym[1]%60);

        tym[0] = (tym[0]%24);

        cout<<"Case #"<<cases<<": ";
        if(tym[0]/10 == 0)
            cout<<"0";
        cout<<tym[0]<<":";
        if(tym[1]/10 == 0)
            cout<<"0";
        cout<<tym[1]<<":";
        if(tym[2]/10 == 0)
            cout<<"0";
        cout<<tym[2]<<endl;
    }
    return 0;
}
