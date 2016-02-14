#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
long long fact(int n)
{
    long long  f = 1LL;
    for(int i=1;i<=n;i++)
        f *= i;

    return f;
}
int frequencyCummulative(long long int* count,string str,int l)
{
    for(int i=0;i<l;i++)
        count[str[i]-'a']++;  //frequency

    for(int i=1;i<26;i++)
        count[i] += count[i-1]; //cummulative     
}
void update(long long int* count,char ch)
{
    int index = ch-'a';
    for(int i=index;i<26;i++)
        count[i]--;
}
long long findrank(string str)
{
    int i ,smaller, l = str.length();
    long long mul = fact(l);
    long long rank = 1LL ,count[26]={0};  // initial rank is 1
    frequencyCummulative(count,str,l);
    /**
    for(int i=0;i<26;i++)
        cout<<count[i]<<" ";
    cout<<endl;
    **/
    for(int i=0;i<l;i++)
    {
        mul /= (l-i);// 5! 4! 3!  and so on

        // multiply with no of smaller char than str[i]
        smaller = (str[i]-'a' - 1)>=0?count[(str[i]-'a'-1)]:0;
        rank += (smaller * mul);
        //reduce cummulative count of str[i] since it is removed
        update(count,str[i]);
    }
    return rank;
}

void requiredstring(long long rank,string str)
{
    int k=0,index,l = str.length();
    sort(str.begin(),str.end());
    char req[l];
    //str.erase(str.begin()+1);
    //cout<<str;
    
    for(int i=0;i<l;i++)
    {
        index = rank / fact(l-i-1);
        //cout<<index<<" ";
        //remove used char
        //req[k++] = str[index];
        cout<<str[index];
        str.erase(str.begin()+index);
        rank = rank % fact(l-i-1);
        //cout<<rank<<endl;
    }
    //req[k] = '\0';
    //cout<<req<<endl;
    cout<<endl;
}
int main()
{
   
    long long t,real_rank,partial_rank,given_rank;
    string str;
    scanf("%lld",&t);
    while(t--)
    {
        cin>>str>>partial_rank;
        //cout<<str<<" "<<partial_rank;        
        real_rank = findrank(str) + partial_rank;
        requiredstring(real_rank-1,str);
    }
    return 0;
}

