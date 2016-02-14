#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <vector>
#include <iomanip>
#include <cmath> 

using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
bool ans = true;
void recursion(LL pos)
{
    if(pos == 1) return;    
    if(!(pos&1))
        ans = (!ans);
    recursion(pos/2);   
}
int main()
{
    LL y,pos;
    scanf("%lld %lld",&y,&pos);
    pos += (1LL<<y);
    recursion(pos);
    if(ans)
        printf("red");
    else
        printf("blue");
    
    return 0;
}
