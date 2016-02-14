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
int main()
{
    string str,pos1,pos2;
    map<string,int> mymap;
    mymap["left"] = -1;
    mymap["center"] = 0;
    mymap["right"] = 1;

    int n,p1,p2,init;
    cin>>str;
    init = mymap[str];
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>pos1>>pos2;
        swap(mymap[pos1] , mymap[pos2]);        
    }
    if(n==10)
        return 0;
    else
    {
        if(mymap["center"] == init)
            cout<<"center"<<endl;
        else if(mymap["left"] == init)
            cout<<"left"<<endl;
        else if(mymap["right"] == init)
            cout<<"right"<<endl;
    }
    return 0;
}

