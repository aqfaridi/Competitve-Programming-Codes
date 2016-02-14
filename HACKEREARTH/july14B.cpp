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
#include <climits>
#include <cassert>

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

map<string,int> my;
map<int,string> r;
void month()
{
    my["January"] = 1;
    my["February"] = 2;
    my["March"] = 3;
    my["April"] = 4;
    my["May"] = 5;        
    my["June"] = 6; 
    my["July"] = 7;
    my["August"] = 8;
    my["September"] = 9;
    my["October"] = 10;
    my["November"] = 11;
    my["December"] = 12;

    map<string,int>::iterator it;
    for(it = my.begin();it!=my.end();it++)
        r[it->second] =  it->first;    
}

int main()
{
    month();
    int t,l,dd,yy;
    string str,s,mm;
    cin>>t;
    getline(cin,str);
    while(t--)
    {
        getline(cin,str);
        l = str.length();
        stringstream ss(str);
        int i=0;
        while(ss >> s)
        {
            if(i == 0)
            {
                stringstream d(s);
                d >> dd;
            }
            else if(i == 1)
                mm = s; 
            else if(i == 2)
            {
                stringstream y(s);
                y >> yy;
            }
            i++;
        }
        dd -= 1;
        if(dd == 0)
        {
            //change the month

            if(my[mm] == 3)
            {
                dd = 28;
         
                if(((yy%4 == 0)&&(yy%100 != 0)) || (yy%400 == 0))
                    dd = 29;
            }
            else if(my[mm] == 5 || my[mm] == 7 || my[mm] == 10 || my[mm] == 12)
                dd = 30;
            else
                dd = 31;
            
            if(mm == "January")
            {
                dd = 31;
                mm = "December";
                yy -= 1;
            }
            else 
                mm = r[my[mm]-1];

        }

        cout<<dd<<" "<<mm<<" "<<yy<<endl;
    }
    return 0; 
}
