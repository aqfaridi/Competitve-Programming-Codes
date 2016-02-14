#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <utility>
#include <map>
using namespace std;
typedef pair<int,int> my_pair;
 
bool sort_pred(const my_pair& left,const my_pair& right)
{
    return left.second < right.second;
}
int main() {
    long long t,n,band,length;
    long long sum,count,len;
    vector<my_pair> arr;
    map<int,bool> check;
    scanf("%lld",&t);
    while(t--)
    {
        sum = 0,count=0,len=0;
        arr.clear();
        check.clear();
        scanf("%lld",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%lld %lld",&band,&length);
            arr.push_back(my_pair(band,length));
        }
        sort(arr.begin(),arr.end(),sort_pred);
        for(int i=0;i<n;i++)
        {
            if(check[arr[i].first]) len += arr[i].second;
            else
            {
                check[arr[i].first] = true;
                count++;
                sum += (count*arr[i].second);
            }
        
        }
        sum += count*len;
        
        
        printf("%lld\n",sum);
    }
    return 0;
} 
