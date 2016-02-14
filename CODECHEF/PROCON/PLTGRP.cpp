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

#define MAX 100010
int arr[MAX];
int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>arr[i];

    multiset<int> s;
    multiset<int>::iterator it;
    for(int i=0;i<n;i++)
    {
        it = s.insert(arr[i]);
        it++;
        if(it != s.end())
            s.erase(it);
        
    }
    cout<<s.size()<<endl;
    return 0; 
}
