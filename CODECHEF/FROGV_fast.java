import java.io.*;
import java.util.*;
class Main
{
    public static final int MAX = 1000010;
    public static final int MOD = 1000000007;
    static int c[],sit[];
    static class pair implements Comparable<pair>
    {
        int first,second;
        public pair(int a,int b)
        {
            first = a; second = b;
        }
        public int compareTo(pair b)
        {
            if(this.first == b.first)
                return new Integer(this.second).compareTo(b.second);
            else 
                return new Integer(this.first).compareTo(b.first);
        }
        
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
            int temp,n,k,p,x,y;
           
            ArrayList<pair> v = new ArrayList<pair>();
            sit = new int[MAX];
            c = new int[MAX];


            str = br.readLine();
            s = str.split(" ");
            n = Integer.parseInt(s[0]); k = Integer.parseInt(s[1]); p = Integer.parseInt(s[2]);
            
            str = br.readLine();
            st = new StringTokenizer(str," "); 
            int i=0;
            while(st.hasMoreTokens())
            {
                sit[i] = Integer.parseInt(st.nextToken());
                v.add(new pair(sit[i],i));
                i++;
            }            

            Collections.sort(v);

            pair[] pr = new pair[n];
            pr = v.toArray(pr);

            int ptr = 1;
            c[pr[0].second] = ptr;
            for(i=1;i<n;i++)
            {
                if(pr[i].first - pr[i-1].first > k){ptr+=1; c[pr[i].second] = ptr;}
                else c[pr[i].second] = ptr;
            }

            while(p>0)
            {
                str = br.readLine();
                s = str.split(" ");
                x = Integer.parseInt(s[0]);
                y = Integer.parseInt(s[1]);
                x -= 1; y -= 1;

                if(c[x] == c[y])
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

