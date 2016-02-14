#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

int main() {
    int t;
    long long red,black,W,L;
    scanf("%lld %lld",&red,&black);
    W = ((red + 4) - sqrt((red+4)*(red+4) - 16*(red+black)) ) / 4; 
    L = (red+black )/W;
    if(L>W)
        printf("%lld %lld\n",L,W);
    else
        printf("%lld %lld\n",W,L);


    return 0;
}
