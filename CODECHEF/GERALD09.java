import java.io.*;
import java.util.*;
class Main
{
    public static final int MAX = 1000010;
    public static final int MOD = 1000000007;
    static char chars[];
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
            int t,n,m,k,p;

            chars = new char[]{'G','C','A','T'};

            str = br.readLine(); t = Integer.parseInt(str);
            while(t>0)
            {
                str = br.readLine();
                s = str.split(" ");
                n = Integer.parseInt(s[0]); m = Integer.parseInt(s[1]); k = Integer.parseInt(s[2]);

                if(k < n*m)
                {
                    p = 0; 
                    for(int i=0;i<n;i++){
                        for(int j=0;j<m;j++,p++)
                            bos.write(new Character(chars[p%1]).toString().getBytes());
                        bos.write(eolb);
                    }
                    t -= 1;
                    continue;
                }

                p = 0;
                for(int i=0;i<n;i++){
                    for(int j=0;j<m;j++,p++)
                        bos.write(new Character(chars[p%4]).toString().getBytes());
                    bos.write(eolb);
                }
                t-=1;            
            }
            bos.flush();
        }
        catch(Exception e){e.printStackTrace();}
    }
}

