#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define MAX 100010
using namespace std;
char input[MAX];
int cnt[26];
char vowel[]={'a','e','i','o','u'};
char consonant[]={'b','c','d','f','g','h','j','k','l','m','n','p','q','r','s','t','v','w','x','y','z'};
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        memset(cnt,0,sizeof(cnt));
        scanf("%s",input);
        for(int i=0;input[i];i++)
        {
            cnt[input[i]-97]++;
            if(input[i]=='a' || input[i]=='e' || input[i]=='i' || input[i]=='o' || input[i]=='u')
            {
                char *location = lower_bound(vowel,vowel+5,input[i]);
                int index = location - vowel;
                printf("%c",consonant[( (cnt[input[i]-97]-1)*5 + index )%21]);
            }
            else  //consonant
            {
                char *location = lower_bound(consonant,consonant+21,input[i]);
                int index = location - consonant;
                printf("%c",vowel[( (cnt[input[i]-97]-1)*21 +index )%5]);
            }
        }
        printf("\n");

    }
    return 0;
}

