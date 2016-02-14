#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <utility>
using namespace std;
bool array1[10000001];
typedef pair<int,int> my_pair;

bool sort_pred(const my_pair& left,const my_pair& right)
{
    return left.second < right.second;
}
int main() {
    long long t,n,band,length,cnt;
    long long sum;
    int array[100010];
    
    bool b;
    my_pair display,temp;
    scanf("%lld",&t);
    while(t--)
    {
        sum = 0;
        memset(array,0,sizeof(array));
        memset(array1,0,sizeof(array1));
        vector<my_pair> arr;
        scanf("%lld",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%lld %lld",&band,&length);
            arr.push_back(my_pair(band,length));
        }
        sort(arr.begin(),arr.end(),sort_pred);
        //display = arr[0];
        cnt = 0;
        b=false;
        //sum = display.second * cnt;
        /*
        for(int i=0;i<n;i++)
        {
            display = arr[i];
            printf("%d %d\n",display.first,display.second); 
        }*/
       int k=0;
        for(int i=0 ; i<n ; i++)
        {
            display = arr[i];
            /*
            temp = arr[i-1];
            
            if(display.first == temp.first)
                sum += (display.second * cnt);
            else
            {
                cnt ++;
                sum += (display.second * cnt);
            }*/
            if(display.first < 10000001)
            {
                if(array1[display.first])
                {
                    sum += (display.second * cnt);
                }
                else
                {
                    cnt++;
                    sum += (display.second * cnt);
                    array1[display.first]=1;
                }
            }
            else
            {    
                sort(array,array + k);
                b = binary_search(array,array+k,display.first);
                //cout<<b<<endl;
                if(b)
                    sum += (display.second * cnt);
                else
                {
                    cnt++;
                    sum += (display.second * cnt);                
                }
                k++;
                array[k] = display.first;
            }
     
        }
        printf("%lld\n",sum);
    }
    return 0;
} 
