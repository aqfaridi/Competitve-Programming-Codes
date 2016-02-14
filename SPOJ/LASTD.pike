#define MAX 1010
array(int) arr = allocate(MAX);
int main()
{
    int t,l,num,k,result;
    string str;
    sscanf(Stdio.stdin->gets(),"%d",t);
    while(t>0)
    {
        k = 0;
        sscanf(Stdio.stdin->gets(),"%s",str);
        l = strlen(str);
        if(l==0)
            continue;
        for(int i=0;i<l;i++)
        {
            if(str[i]>=48 && str[i]<=57)//digit
            {
                num = 0;
                while(i<l && str[i] >= 48 && str[i] <= 57)
                {
                    num = num*10 + (str[i]-'0');
                    i++;
                }
                arr[k++] = num;
            }
        }
        /*
        for(int i=0;i<k;i++)
        {
            write(arr[i] + "\n");
        }
        */
        result = arr[0];
        k = 1;
        for(int i=0;i<l;i++)
        {
           if(str[i]=='+')
                result += arr[k++];
           else if(str[i] == '-')
                result -= arr[k++];
           else if(str[i] == '*')
                result *= arr[k++];
           else if(str[i] == '/')
                result /= arr[k++];        
        }
        
        write(result%10 + "\n");

        t--;
    }
    return 0;
}
