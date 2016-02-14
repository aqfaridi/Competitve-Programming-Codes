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
int age[10000];
struct node
{    
    string second;
    int first;
};
bool cmp(node  a,node b)
{
    if(a.first > b.first)
        return (a.first > b.first);
    
    else if (a.first == b.first)
        return ((a.second).compare(b.second) < 0) ;
   
    else return (a.first > b.first);
}

int main()
{
    int k=0;
    vector<node> v(10000);
    string input;
    while(getline(cin,input))
    {
        stringstream ss(input);
        //ss >> str[i] >> age[i] ; 
        //cout<<str[i]<<" "<<age[i]<<endl;
        //cout<<temp.first<<" "<<temp.second<<endl;
        //cout<<v[i].second;
        ss >> v[k].second >> v[k].first;
        
        //cout<<v[i].second<<" "<<v[i].first<<endl;;
        //v.push_back(make_node(str[i],age[i]));
        if((v[k].second).length() > 0)
                k++; 
    }
    v.resize(k);
    sort(v.begin(),v.end(),cmp);
    
    for(int i = 0 ; i < k ; i++)
    {
        cout<<v[i].second<<endl;
    }
    return 0;
}

