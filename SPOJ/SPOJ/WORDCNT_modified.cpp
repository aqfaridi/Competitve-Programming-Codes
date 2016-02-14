#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <sstream>
#include <algorithm>
using namespace std;
int main()
{
    string str,s;
    int t,best,len,parent,cnt;
    ios::sync_with_stdio(false);//to make fast io
    cin>>t;
    getline(cin,s); //  \n
    while(t--)
    {
        getline(cin,str);
        best = parent = cnt = 0;
        stringstream mystr(str);
        while(mystr >> s)  // stream give one by one to s
        {
            len = s.size();
            if(len==parent)
                cnt++;
            else
            {
                if(cnt > best)
                    best = cnt;
                cnt = 1;
                parent = len;
            }
        }
        if(cnt > best) 
            best = cnt;
        cout<<best<<endl;

    }
    return 0;
}

