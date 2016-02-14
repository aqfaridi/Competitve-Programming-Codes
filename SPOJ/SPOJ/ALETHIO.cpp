#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <climits>
#include <cassert>
#include <iomanip>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>
#include <complex>
#include <numeric>
#include <functional>
#include <sstream>
#include <algorithm>
#define MAX 1000010
#define MOD 1000000007
using namespace std;
typedef long long LL;
typedef unsigned long long uLL;
vector<string> store;
bool cmp(string a,string b)
{
    return a.compare(b) < 0;
}
int main()
{
    //char str[1010],copy[1010];
    string numstr,str,cpy;
    int k=0;
    int index[1010];
    int kk=0;
    cin>>str;
    //scanf("%s",str);
    int l = str.length();
    int zeros = 0;
    for(int i=0;i<l;i++)
    {
        if(str[i]=='0')
            zeros++;

        if(str[i]>=65 && str[i]<=90)
            index[kk++] = i;
    }
    if(kk==0)
    {
        if(zeros == l)
            cout<<0<<endl;
        else
        {
            while(str[kk]=='0')
                kk++;
            cout<<str.substr(kk)<<endl;
        }
    }
    else
    {

        //special case
        string maxx = "0";
        string number = "";
        for(int i=0;i<l;i++)
        {
            if(str[i]>=48 && str[i]<=57)
                number += str[i];

            if(str[i]>=65 && str[i]<=90)
            {
                if(number.compare(maxx) > 0)
                    maxx = number;
                number = "";
            }
        }
        store.push_back(maxx);
        //cout<<maxx<<endl;

        for(int i=0;i<kk;i++)
        {
            cpy = str.substr(0);
            cpy[index[i]] = '9';      
            int x,y;
            for(x=index[i];x<l;x++)
                if(cpy[x]>=65 && cpy[x]<=90)
                    break;

            for(y=index[i];y>=0;y--)
                if(cpy[y]>=65 && cpy[y]<=90)
                    break;
                     
            y++; x--;
            numstr = cpy.substr(y,x-y+1);
            if(str[y]=='0')
            {
                int ind = y;
                while(numstr[ind]=='0')
                    ind++;
                y = ind;
                numstr = cpy.substr(y,x-y+1);
            }
            store.push_back(numstr);
        }
        
        maxx = "0";
        for(int i=0;i<store.size();i++)
        {
            if(store[i].length()  > maxx.length())
                maxx = store[i];
            else if(store[i].length() == maxx.length())
            {
                if(store[i].compare(maxx) > 0)
                    maxx = store[i];
            }
        }
        cout<<maxx<<endl;
    }
    return 0;
}

