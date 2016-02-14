import java.io.*;
import java.util.*;
class Main
{
    public static final int MAX = 1000010;
    public static final int MOD = 1000000007;
    static int p[],m[];
    static HashMap<Integer,Integer> hm;
    static void pf(int n)
    {
        int c = 0 ;
        for(int i=2;i*i<=n;i++)
            if((n%i == 0)){
                c = 0; while((n%i == 0)){c++;n/=i;}
                if(hm.containsKey(i))
                    hm.put(i,Math.max((int)hm.get(i),c));
                else
                    hm.put(i,c);
            }
        if(n > 1)
        {
            if(hm.containsKey(n))
                hm.put(n,Math.max((int)hm.get(n),1));
            else
                hm.put(n,1);
        }
    }
    
    static long expo(int a,int n) { 
        long result = 1;
        while(n > 0)
        {
            if((n%2 == 1)) result = (result * a)%MOD;
            a = (a*a)%MOD;
            n >>= 1;
        }
        return result % MOD;
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
            int t,n,go,ct,x,y;

            Set set;
            Iterator it;

            m = new int[MAX];
            p = new int[MAX];
            hm = new HashMap< >();

            str = br.readLine(); t = Integer.parseInt(str);
            while(t>0)
            {
                Arrays.fill(m,0);
                hm.clear();

                str = br.readLine();  n = Integer.parseInt(str);
                str = br.readLine();
                st = new StringTokenizer(str," ");
                int i = 1;
                while(st.hasMoreTokens())
                    p[i++] = Integer.parseInt(st.nextToken());
                
                for(i=1;i<=n;i++){
                    if(m[i] == 0){
                        go = p[i];ct = 0;
                        do{
                            ct++;m[go] = 1;
                            go = p[go];
                        }while(go != p[i]);
                        pf(ct);
                    }
                }

                
                long ret = 1;
                set = hm.entrySet();
                it = set.iterator();
                while(it.hasNext()){
                        Map.Entry me = (Map.Entry)it.next();
                        x = (int)me.getKey(); y = (int)me.getValue();
                        ret = (ret%MOD * expo(x , y))%MOD;
                }

                bos.write(new Long(ret).toString().getBytes());
                bos.write(eolb);
                t-=1;            
            }
            bos.flush();
        }
        catch(Exception e){e.printStackTrace();}
    }
}

