import java.io.*;
import java.util.*;
class Main
{
    public static final int MAX = 10010;
    public static final int MOD = 1000000007;
    static int s[],p[],sp[];
    static int owner(int x)
    {
        if(p[x] == x)
            return x;
        else
        {
            return p[x] = owner(p[x]);
            //p[x] = var;
            //return p[x];
        }
    }
    public static void main(String[] aqf)
    {
        try
        {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            BufferedOutputStream bos = new BufferedOutputStream(System.out);
            BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
            String eol = System.getProperty("line.separator");
            byte[] eolb = eol.getBytes();
            byte[] spaceb = " ".getBytes();
            String str;
            StringTokenizer st;
            int t,n,q,c,x,y;

            p = new int[MAX];
            s = new int[MAX];
            sp = new int[3];

            str = br.readLine(); t = Integer.parseInt(str);
            while(t>0)
            {
                str = br.readLine();  n = Integer.parseInt(str);                
                str = br.readLine();
                st = new StringTokenizer(str," ");
                int i=1;
                while(st.hasMoreTokens())
                {
                    s[i] = Integer.parseInt(st.nextToken());
                    p[i] = i;
                    i++;
                }
                
                str = br.readLine();  q = Integer.parseInt(str);
                while(q > 0)
                {                    

                    str = br.readLine();
                    st = new StringTokenizer(str," ");
                    int k = 0;
                    while(st.hasMoreTokens())
                        sp[k++] = Integer.parseInt(st.nextToken());
                    
                    if(sp[0] == 0)
                    {
                        x = sp[1]; y = sp[2];
                        int ox = owner(x),oy = owner(y);
                        if(ox == oy) { q--;out.write("Invalid query!\n");out.flush();continue;}
                        if(s[ox] > s[oy])   p[oy] = ox;
                        else if(s[ox] < s[oy]) p[ox] = oy;     
                    }
                    else
                        out.write(""+owner(sp[1])+"\n");
                        out.flush();
                    q -= 1;
                }
                t-=1;            
            }
        }
        catch(Exception e){e.printStackTrace();}
    }
}
