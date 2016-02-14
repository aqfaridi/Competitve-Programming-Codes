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
vector<int> arr;
int main()
{
    int t,n,cnt,num;
    cin>>t;
    while(t--)
    {
        arr.clear();
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>num;
            arr.push_back(num);
        }
        sort(arr.begin(),arr.end());
       // for(int i=0;i<n;i++)
         //   cout<<arr[i]<<" ";
        //cout<<endl;
        
        cnt = 0;
        for(int i=0;i<arr.size();i++)
        {
                int index = lower_bound(arr.begin()+i,arr.end(),2*arr[i]) - arr.begin();
                //int index = location - arr;
                if(index == n)
                    continue;
                if(arr[index] != 2*arr[i])
                    continue;
                if(arr[index]==2*arr[i])
                {
      //              cout<<i<<" "<<index<<" "<<arr.size()<<endl;
                    arr.erase(arr.begin()+index);
                    arr.erase(arr.begin()+i);
                    i--;
//        for(int i=0;i<arr.size();i++)
  //          cout<<arr[i]<<" ";
    //    cout<<endl;
               
                    cnt++;
                }
        }
        cout<<cnt<<endl;
    }
    return 0;
}


