#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <climits>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <numeric>
#include <sstream>
#include <algorithm>
#define mp                          make_pair
#define pb                          push_back
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

#define MAX 1000010
#define MOD 1000000007
    
int main()
{
    int t;
    int n,l,cnt;
    string str;
    cin>>t;
    while(t--)
    {
        cnt =0;
        cin>>str;
        l = str.length();
        for(int i=0;i<l-1;i++)
        {
            if(islower(str[i]) && isupper(str[i+1]))
                cnt++;
        }
        cout<<cnt<<endl;
    }
    return  0;
}
