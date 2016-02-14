import java.io.*;
import java.util.*;
class Main
{
    public static final int MAX = 1000010;
    public static final int MOD = 1000000007;
    static int v[][],ans[][],maxx,n;
    static int iter()
    {
        ans[0][0] = 1;
        for(int idx=1;idx<=maxx;idx++)
        {
            for(int prof = 0;prof < (1<<n);prof++){
                ans[idx][prof] = (ans[idx][prof] + ans[idx-1][prof])%MOD;
                for(int j=0;j<n;j++)
                    if(v[idx][j] == 1 && (prof&(1<<j)) == 0)
                        ans[idx][prof | (1<<j)] = (ans[idx][prof | (1<<j)] + ans[idx-1][prof])%MOD;
            }
        }
        return ans[maxx][(1<<n)-1];
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
            int t,id;

            v = new int[200][20];
            ans = new int[200][4096];

            str = br.readLine(); t = Integer.parseInt(str);
            while(t>0)
            {
                maxx = -1;
                for(int i=0;i<200;i++){                   
                    Arrays.fill(v[i],0);
                    Arrays.fill(ans[i],0);
                }
                str = br.readLine();  n = Integer.parseInt(str);
                for(int i=0;i<n;i++)
                {
                    str = br.readLine();
                    st = new StringTokenizer(str);
                    while(st.hasMoreTokens())
                    {
                        id = Integer.parseInt(st.nextToken());
                        v[id][i] = 1;
                        maxx = Math.max(maxx,id);
                    }
                }
                /*
                for(int i=0;i<=maxx;i++){
                    for(int j=0;j<n;j++)
                        System.out.print(v[i][j] + " ");
                    System.out.println();
                }*/
                int ret = iter();
                /*
                for(int i=0;i<=maxx;i++){
                    for(int j=0;j<(1<<n);j++)
                        System.out.print(ans[i][j] + " ");
                    System.out.println();
                }*/
                bos.write(new Integer(ret).toString().getBytes());
                bos.write(eolb);
                t-=1;             
            }
            bos.flush();
        }
        catch(Exception e){e.printStackTrace();}
    }
}

