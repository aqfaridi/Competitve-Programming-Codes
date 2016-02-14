import java.io.*;
import java.util.*;
class Main
{
    public static final int MAX = 1000010;
    public static final int MOD = 1000000009;
    static int arr[],ans[],ls[],n;
    static int solve(int n)
    {
        ans[0] = 1;
        ans[1] = 2;
        ls[arr[1]] = 1;
        for(int i=2;i<=n;i++)
        {
            ans[i] = (2*ans[i-1])%MOD;
            if(ls[arr[i]] != 0)
                ans[i] = (ans[i] - ans[ls[arr[i]]-1])%MOD;
            ls[arr[i]] = i;
        }
        for(int i=1;i<=n;i++)
            ls[arr[i]] = 0;
        return (ans[n]-1+MOD)%MOD;
    }
    public static void main(String[] aqf)
    {
        try
        {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            BufferedOutputStream bos = new BufferedOutputStream(System.out);
            String eol = System.getProperty("line.separator");
            byte[] eolb = eol.getBytes();
            byte[] spaceb = " ".getBytes();
            String str;
            String[] s;
            StringTokenizer st;
            int t,pr,nx,df;

            arr = new int[MAX];
            ls = new int[9*MAX];
            ans  = new int[MAX];

            str = br.readLine(); t = Integer.parseInt(str);
            while(t>0)
            {
                str = br.readLine();  n = Integer.parseInt(str);
                str = br.readLine();
                st = new StringTokenizer(str);
                pr = Integer.parseInt(st.nextToken());
                int i = 1;
                while(st.hasMoreTokens())
                {
                    nx = Integer.parseInt(st.nextToken());
                    df = nx-pr;
                    if(df <= 0)
                        df += 8*MAX;
                    arr[i] = df;
                    i++;
                    pr = nx;
                }
                int ret = solve(n-1);
                bos.write(new Integer(ret).toString().getBytes());
                bos.write(eolb);
                t-=1;             
            }
            bos.flush();
        }
        catch(Exception e){e.printStackTrace();}
    }
}

