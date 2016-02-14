import java.io.*;
import java.util.*;
class Main
{
    public static final int MAX = 1000010;
    public static final int MOD = 1000000007;
    static int arr[];
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
            int t,n,var,k,cnt;

            arr = new int[MAX];
            Arrays.fill(arr,0);

            str = br.readLine(); t = Integer.parseInt(str);
            while(t>0)
            {
                cnt = 0;
                str = br.readLine();
                s = str.split(" ");
                n = Integer.parseInt(s[0]); k = Integer.parseInt(s[1]);
                str = br.readLine();
                st = new StringTokenizer(str);
                while(st.hasMoreTokens())
                {
                    var = Integer.parseInt(st.nextToken());
                    if(var % 2 == 0)
                        cnt++;
                }
                
                if(k == 0 && cnt == n)
                    bos.write("NO".getBytes());
                else if(cnt >= k)
                    bos.write("YES".getBytes());
                else
                    bos.write("NO".getBytes());

                bos.write(eolb);
                t-=1;             
            }
            bos.flush();
        }
        catch(Exception e){e.printStackTrace();}
    }
}

