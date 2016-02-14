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

#define MAX 100010
vector< pii > a(MAX),b(MAX),c(2*MAX);
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i].first>>b[i].first;
        a[i].second = i;
        b[i].second = n+i;
    }
    
    int i=0,j=0,k=0;
    while(i<n && j<n)
    {
        if(a[i].first < b[j].first)
        {
            c[k].first = a[i].first;
            c[k].second = a[i].second;
            k++;i++;
        }
        else
        {
            c[k].first = b[j].first;
            c[k].second = b[j].second;            
            k++;j++;
        }
    }
    while(i<n)
    {
            c[k].first = a[i].first;
            c[k].second = a[i].second;
            k++;i++;
    }
    while(j<n)
    {

            c[k].first = b[j].first;
            c[k].second = b[j].second;            
            k++;j++;
    }

    vector<char> str1(n,'0'),str2(n,'0');
    for(int i=0;i<n;i++)
    {
        if(c[i].second>=n)
            str2[c[i].second-n] = '1';
        else 
            str1[c[i].second] = '1';        
    }
    for(int i=0;i<n/2;i++)
    {
        str1[a[i].second] = '1';
        str2[b[i].second-n] = '1';
    }

    for(int i=0;i<n;i++)
        cout<<str1[i];
    cout<<endl;
    for(int i=0;i<n;i++)
        cout<<str2[i];
    cout<<endl;
    return 0;
}
