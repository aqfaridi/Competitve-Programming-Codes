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
int arr1[26],arr2[26];
int main()
{
    int t,n,l1,l2,cnt1,cnt2,cnt3,cnt4,idx;
    string s1,s2;
    cin>>t;
    string str,sub;
    char ch = getchar();
    while(t--)
    {
        sub = str = "";
        memset(arr1,0,sizeof(arr1));
        memset(arr2,0,sizeof(arr2));
        getline(cin,s1);
        getline(cin,s2);
        l1 = s1.length();
        l2 = s2.length();
        for(int i=0;i<l1;i++)
            if(isalpha(s1[i]))
                arr1[tolower(s1[i])-'a']++;
        for(int i=0;i<l2;i++)
            if(isalpha(s2[i]))
                arr2[tolower(s2[i])-'a']++;
       /* 
        for(int i=0;i<26;i++)
            cout<<arr1[i]<<" ";
        cout<<endl;
        for(int i=0;i<26;i++)
            cout<<arr2[i]<<" ";
        cout<<endl;
        */
        for(int i=0;i<26;i++)
            arr1[i] -= arr2[i];

        cnt1 = cnt2 = cnt3 = cnt4 = idx = 0;
        for(int i=0;i<26;i++)
        {
            if(arr1[i]>=0)
                cnt1++;
            if(arr1[i]<=0)
                cnt2++;
            if(arr1[i]==0)
                cnt3++;
            if(arr1[i]&1)
            {
                cnt4++;
                idx = i;
            }
        }
        if(cnt4 >=2)
        {
            cout<<"NO LUCK"<<endl;
            continue;
        }
        if(cnt3==26)
        {
            cout<<"YES"<<endl;
            continue;
        }
        if(cnt1 == 26 || cnt2 == 26)
        {            
            char c;
            if(cnt4!=0)
            {
                c = 'a'+idx;
                arr1[idx] += (arr1[idx]<0)?(1):(-1);
            }
            for(int i=0;i<26;i++)
            {
                arr1[i] = abs(arr1[i]);
                for(int j=1;j<=arr1[i]/2;j++)
                {
                    str += ('a' + i );
                }
            }
            sub = str;
            reverse(sub.begin(),sub.end());

            if(cnt4 != 0)
                str += c;
            str += sub;
            cout<<str<<endl;
        }
        else if(cnt2 == 26)
        {
        
        }
        else
        {
            cout<<"NO LUCK"<<endl;
        }
    }
    return 0;
}
