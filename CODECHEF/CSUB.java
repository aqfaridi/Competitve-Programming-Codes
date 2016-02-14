import java.io.*;
import java.util.*;
class Main
{
    public static final int MAX = 100010;
    public static final int MOD = 1000000007;
    static int back[];
    public static void main(String[] aqf)
    {
        try
        {
            BufferedReader br = new BufferedReader(new
InputStreamReader(System.in));
            BufferedOutputStream bos = new
BufferedOutputStream(System.out);
            String eol = System.getProperty("line.separator");
            byte[] eolb = eol.getBytes();
            byte[] spaceb = " ".getBytes();
            String s;
            int t,n;
            long ret;

            back = new int[MAX];

            s = br.readLine(); t = Integer.parseInt(s);
            while(t>0)
            {
                s = br.readLine();  n = Integer.parseInt(s);
                s = br.readLine();
                back[n] = 0;
                for(int i=n-1;i>=0;i--)
                {
                    if(s.charAt(i) == '1')
                        back[i] = 1 + back[i+1];
                    else
                        back[i] = back[i+1];
                }

                ret = 0;

                for(int i=0;i<n;i++)
                    if(s.charAt(i) == '1')
                        ret += back[i];

                
                bos.write(new Long(ret).toString().getBytes());
                bos.write(eolb);
                t-=1;            
            }
            bos.flush();
        }
        catch(Exception e){e.printStackTrace();}
    }
}

