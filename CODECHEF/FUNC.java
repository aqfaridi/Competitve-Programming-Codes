import java.util.*;
import java.io.*;

class Main
{
    static final int MAX = 10010;
    static final int MOD = 1000000007;
    static long[] arr,cumm;
    //static long[][] v;
    static int[] size;
    static ArrayList< ArrayList<Long> > v;
    static void precompute()
    {
        long pwr;
        size = new int[61];
        v = new ArrayList< ArrayList<Long> >() ;
        for(int i=0;i<=60;i++)
            v.add( new ArrayList<Long>() );
        //v = new long[61][1000010];
        for(int j=1;j<1000010;j++)
        {
            pwr = j;
            for(int i=1;i<=60;i++)
            {
                v.get(i).add(pwr);
                //v[i][j-1] = pwr;
                //size[i]++;
                if(pwr > (1L<<60)/j)
                    break;
                pwr *= j;
            }
        }

    }
    public static void main(String[] aqf)
    {
        try
        {
            precompute();
            arr = new long[MAX];
            cumm = new long[MAX];
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            BufferedOutputStream bos = new BufferedOutputStream(System.out);
            String eol = System.getProperty("line.separator");
            byte[] eolb = eol.getBytes(); 
            byte[] spaceb = " ".getBytes();
            int n,q,t;
            long ans,root,x;

            String str = br.readLine();
            t = Integer.parseInt(str);
            while(t>0)
            {
                str = br.readLine();
                String[] s = str.split(" ");
                n = Integer.parseInt(s[0]);
                q = Integer.parseInt(s[1]);
                str = br.readLine();
                StringTokenizer st = new StringTokenizer(str," ");
                int k = 1;
                while(st.hasMoreTokens())
                    arr[k++] = Integer.parseInt(st.nextToken());
                
                cumm[n] = (arr[n]+MOD)%MOD;
                for(int i=n-1;i>=1;i--)
                    cumm[i] = (cumm[i+1] + arr[i] + MOD)%MOD;
                
                str = br.readLine();
                st = new StringTokenizer(str," ");
                while(st.hasMoreTokens())
                {
  
                    x = Long.parseLong(st.nextToken());
                    ans = 0;
                    int i = 1;
                    for(;i<=n;i++)
                    {
                        if(i == 1)
                            root = x;
                        else if(i == 2)
                            root = (long)Math.sqrt(x);
                        else 
                        {
                            //binary search
                            int idx = Collections.binarySearch(v.get(i),x);                            
                            if(idx < 0)
                                idx = -(idx+1);
                            else 
                                idx += 1;
                            root = idx;
                        }
                        //System.out.println("root="+root+" i="+i);
                        ans = (ans + ((root%MOD)*arr[i])%MOD)%MOD;
                        if(root == 1)   break;
                    }
                    if(i < n)
                        ans = (ans + cumm[i+1] + MOD)%MOD;
                    bos.write(new Long(ans).toString().getBytes());
                    bos.write(spaceb);
                    q -= 1;
                }
                bos.write(eolb);
                t-=1;
            }
            bos.flush();
        }catch(Exception e){}
    }
}
