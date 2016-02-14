#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <vector>
#include <iomanip>
#include <cmath> 
#include <map>
#include <sstream>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

int main()
{
    int t,n;
    string str,sub;
    getline(cin,str);
    stringstream(str) >> t;
    while(t--)
    {
        map<string,int> m;
        getline(cin,str);
        stringstream ss(str);
        while(ss >> sub)
            m[sub] = 1; 
        cout<<m.size()<<endl;
    }
    return 0;
}


