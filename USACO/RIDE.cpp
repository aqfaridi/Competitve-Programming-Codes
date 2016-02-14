/*
ID: aqfari1
PROG: ride
LANG: C++
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <vector>
#include <iomanip>
#include <cmath> 
#include <fstream>

using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

#define MAX 100010
#define MOD 1000000007    
int main()
{
    ofstream fout("ride.out");
    ifstream fin("ride.in");
    string group,comet;
    int l1,l2;
    LL sumc=1,sumg=1;
    fin>>group;
    fin>>comet;
    l1 = group.length();l2 = comet.length();
    for(int i=0;i<l1;i++)
        sumg *= (group[i]-'A'+1);
    sumg %= 47;
    for(int i=0;i<l2;i++)
        sumc *= (comet[i]-'A'+1);
    sumc %= 47;

    if(sumg == sumc)
        fout<<"GO"<<endl;
    else
        fout<<"STAY"<<endl;
    return 0;
}
