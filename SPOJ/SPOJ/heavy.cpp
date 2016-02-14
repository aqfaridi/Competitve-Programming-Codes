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
    int index,i,k;
    int arr[MAX];
    int metal[MAX];
    string str;
    cin>>str;
    index = str.find("heavy");
    i = 0;
    while(index != -1)
    {
        arr[i++] = index;
        index = str.find("heavy",index+1);
    }
    k = 0; 
    index = str.find("metal");
  
    while(index != -1)
    {
        metal[k++] = index;
        index = str.find("metal",index+1);                    
    }
    /*
    for(int x=0;x<i;x++)
        cout<<arr[x]<<" ";
    cout<<endl;
    for(int x=0;x<k;x++)
        cout<<metal[x]<<" ";
    cout<<endl;
    */
    sort(arr,arr+i);
    sort(metal,metal+k);
    long long sum = 0LL;
    for(int x=0;x<i;x++)
    {
        int* location = upper_bound(metal,metal+k,arr[x]);
        int ind = location - metal;
        //cout<<ind<<endl;
        //cout<<k+1 - ind<<endl;
        sum += (k - ind);
    }
    cout<<sum<<endl;
    return 0;
}

