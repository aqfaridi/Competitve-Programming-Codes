#define MAX 100010
#define MOD 1000000007
array(int) arr = allocate(MAX);
array(int) cumm1 = allocate(MAX);
array(int) cumm2 = allocate(MAX);
array(string) s;
int main()
{
    int t,n,q,w,x,y,z,r,l;
    string str;
    sscanf(Stdio.stdin->gets(),"%d",t);
    while(t--)
    {
        sscanf(Stdio.stdin->gets(),"%d %d",n,q);
        cumm1[0] = cumm2[0] = 0;
        sscanf(Stdio.stdin->gets(),"%s",str);
        s = str/" ";
        for(int i=1;i<=n;i++)
        {
            l = strlen(s[i-1]);
            r = 0;
            for(int j=0;j<l;j++)
                r = r*10 + (int)(s[i-1]-'0');
            write(r);
            //arr[i] = int(s[i-1]);
            //write(arr[i]+"\n");
            //cumm1[i] = (i*arr[i] + cumm1[i-1]);
            //cumm2[i] = (arr[i] + cumm2[i-1]);
        }

        while(q--)
        {
            sscanf(Stdio.stdin->gets(),"%d %d %d %d",w,x,y,z);
            write( ((cumm1[z+x]-cumm1[y+x-1] + MOD)%MOD + ((w-x)%MOD * (cumm2[z+x]-cumm2[y+x-1]+MOD))%MOD)%MOD + "\n");
        }
    }

    return 0; 
}
