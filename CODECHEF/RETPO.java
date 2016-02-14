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
            BufferedReader br = new BufferedReader(new
InputStreamReader(System.in));
            BufferedOutputStream bos = new
BufferedOutputStream(System.out);
            String eol = System.getProperty("line.separator");
            byte[] eolb = eol.getBytes();
            byte[] spaceb = " ".getBytes();
            String str;
            String[] s;
            int t;
            long a,b,ret;

            arr = new int[MAX];
            Arrays.fill(arr,0);

            str = br.readLine(); t = Integer.parseInt(str);
            while(t>0)
            {
                str = br.readLine();  
                s = str.split(" ");
                a = Long.parseLong(s[0]);
                b = Long.parseLong(s[1]);
                a = Math.abs(a);
                b = Math.abs(b);
                if(a >= b)
                    ret = (a + b) + (((a-b)+1)/2)*2;
                else
                    ret = (a + b) + ((b-a)/2)*2;
                bos.write(new Long(ret).toString().getBytes());
                bos.write(eolb);
                t-=1;            
            }
            bos.flush();
        }
        catch(Exception e){e.printStackTrace();}
    }
}

