array(int) dp = allocate(65);
void precalc()
{
    dp[0] = dp[1] = 0;
    dp[2] = 1;dp[3] = 3;
    for(int i=4;i<64;i++)
        dp[i] = (1<<(i-2)) + dp[i-1] + dp[i-2];
}
int get_cuts(int n)
{
   int cuts = 0,prev = -5;

   for(int i = 63;n>0;i--)
   {
        if((1<<i) & n)
        {
            cuts += dp[i];
            prev = i;
            n ^= (1 << i);
            if(n != 0)
            {
                i--;
                if( (1<<i) & n)
                {
                    if( i + 1 == prev)
                    {
                        cuts += dp[i];
                        n ^= (1<< i);
                        cuts += (n+1); 
                        break;
                    }
                }   
            }
        }
   }
   return cuts;
}
int main()
{
    precalc();
    int t;
    string str;
    int n,low,high,cuts,mid;
    sscanf(Stdio.stdin->gets(),"%d",t);
    while(t--)
    {
        str = "";
        sscanf(Stdio.stdin->gets(),"%d",n);
        low = 0;
        high = 1000*n;
        while(low <= high)
        {
            mid = (low + high)/2;
            cuts = get_cuts(mid);
            if(mid-cuts == n)
            {
                cuts = get_cuts(mid-1);
                if((mid - 1) - cuts != n)
                    break;
                else 
                    high = mid - 1;
            }
            else if(mid - cuts < n)
                low = mid + 1;
            else if(mid - cuts > n)
                high = mid - 1;
        }
        //cout<<mid<<endl;
        while(mid)
        {
            if(mid & 1)
                str += "1";
            else 
                str += "0";
            mid /= 2;
        }
        int l = strlen(str);
        for(int i=l-1;i>=0;i--)
            write("%c",str[i]);
        write("\n");
    }
    return 0; 
}

