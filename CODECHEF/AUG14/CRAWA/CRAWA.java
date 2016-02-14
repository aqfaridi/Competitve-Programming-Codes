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
            boolean b;
            int t,n,x,y;

            arr = new int[MAX];
            Arrays.fill(arr,0);

            str = br.readLine(); t = Integer.parseInt(str);
            while(t>0)
            {
                str = br.readLine();
                s = str.split(" ");
                x = Integer.parseInt(s[0]);
                y = Integer.parseInt(s[1]);
                b = false;

                if((x&1)==1 && x>0 && -(x-1) <= y && y <= (x+1))
                    b = true;
                if((x&1)==0 && x<0 && x <= y && y <= -x)
                    b = true;                                
                if((y&1)==0 && -Math.abs(y) <= x && x <= Math.abs(y-1))
                    b = true;

                if(b)
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

