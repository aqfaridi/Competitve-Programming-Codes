import java.io.*;
import java.util.*;
class Main
{
    public static final int MAX = 1000010;
    public static final int MOD = 1000000007;
    static int c[],sit[],t[];
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
            int temp,n,k,p,x,y;
            
            sit = new int[MAX];
            t = new int[MAX];
            c = new int[MAX];


            str = br.readLine();
            s = str.split(" ");
            n = Integer.parseInt(s[0]); k = Integer.parseInt(s[1]); p = Integer.parseInt(s[2]);
            
            str = br.readLine();
            st = new StringTokenizer(str," "); 
            int i=1;
            while(st.hasMoreTokens())
            {
                sit[i] = Integer.parseInt(st.nextToken());
                t[i-1] = sit[i];
                i++;
            }


            Arrays.sort(t,0,n);
            int ptr = 0;
            for(i=1;i<n;i++)
                if(t[i] - t[i-1] > k) c[ptr++] = i;

            while(p>0)
            {
                str = br.readLine();
                s = str.split(" ");
                x = Integer.parseInt(s[0]);
                y = Integer.parseInt(s[1]);
                x = sit[x];   y = sit[y];
                
                int i1 = Arrays.binarySearch(t,0,n,x);
                int i2 = Arrays.binarySearch(t,0,n,y);
                if(i1 > i2) 
                {
                    temp = i1;
                    i1 = i2;
                    i2 = temp;
                }

                int idx = Arrays.binarySearch(c,0,ptr,i1);                
                if(idx < 0)
                    idx = -(idx+1);
                else
                    idx = idx + 1;

                if(idx == ptr)
                {
                    bos.write("Yes".toString().getBytes());
                    bos.write(eolb);
                    p -= 1;
                    continue;
                }

                if(c[idx] > i2)
                {
                    bos.write("Yes".toString().getBytes());
                    bos.write(eolb);
                }
                else
                {
                    bos.write("No".toString().getBytes());
                    bos.write(eolb);
                }
                p -= 1;
            }
            bos.flush();
        }
        catch(Exception e){e.printStackTrace();}
    }
}

