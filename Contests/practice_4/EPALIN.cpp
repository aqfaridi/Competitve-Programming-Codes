#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

#define pb push_back
#define mp make_pair
#define mt make_tuple
#define eb emplace_back
#define em push
#define X first
#define Y second
#define all(v)                      v.begin(),v.end()    
#define uniq(v)                     sort(all(v));v.erase(unique(all(v)),v.end())
#define _ ios::sync_with_stdio(false);cin.tie(0);

#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;

#define endl '\n'
#define MAX 1000010
#define MOD 1000000007
namespace KMP
{
    int b[MAX],m,n;
    void LPS(string pat)
    {
        int i=0,j=-1;//j => border
        m = pat.length();
        b[i] = j;
        while(i<m)
        {
            while(j>=0 && pat[i]!=pat[j]) j=b[j];//next widest border
            i++;j++;
            b[i] = j;
        }
    }
    void kmpSearch(string txt,string pat)
    {    
        int i=0,j=0;
        n = txt.length();
        while(i<n)
        {
            while(j>=0 && txt[i]!=pat[j]) j=b[j];//next widest border of some prefix of pat
            i++;j++;
            if(j==m)
            {
                printf("%d\n",(i-j));
                j = b[j]; //widest border of pat
            }
        }            
    }
}
using namespace KMP;
bool ispalin(string str){
    string r = str;
    reverse(all(r));
    return r == str;
}
int main()
{_
    string str,rev;
    while(getline(cin,str))
    {
        if(ispalin(str)){
            cout<<str<<endl;
            continue;
        }
        rev = str;
        reverse(all(rev));
        string temp = rev + str;
        int l = temp.length();
        LPS(temp);
        cout<<str + rev.substr(b[l])<<endl;
    }

    return 0; 
}