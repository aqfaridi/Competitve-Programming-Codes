import java.io.*;
import java.util.*;
class Main
{
    static double prob[][];
    static int ct[];
    public static void main(String[] args)
    {
        try
        {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            BufferedOutputStream bos = new BufferedOutputStream(System.out);
            String eol = System.getProperty("line.separator");
            byte[] eolb = eol.getBytes();
            byte[] spaceb = " ".getBytes();
            int t,n,c,kk,L,R; String[] s; String str;
            prob = new double[80][120];
            ct = new int[80];

            str = br.readLine();   t  = Integer.parseInt(str);
            while(t>0)
            {
                Arrays.fill(ct,0);
                for(int i=1;i<60;i++)
                    Arrays.fill(prob[i],0);
                
                str = br.readLine();   s = str.split(" ");
                n = Integer.parseInt(s[0]);  c = Integer.parseInt(s[1]);  kk = Integer.parseInt(s[2]);
                for(int i=1;i<=kk;i++)
                {
                    str = br.readLine();    s = str.split(" ");
                    L = Integer.parseInt(s[0]);     R = Integer.parseInt(s[1]);
                    for(int j=L;j<=R;j++)   ct[j]++;
                }
              

                prob[0][1] = 1;
                for(int i=1;i<=kk;i++)
                    for(int j=0;j<=c;j++)
                    {
                        prob[i][j] += prob[i-1][j]/2.0;
                        for(int k=0;k<=c;k++)
                            prob[i][(j*k)%c] += (1.0/(2.0*c))*prob[i-1][j];
                    }

                double ret = 0;
                for(int i=1;i<=n;i++)   for(int j=0;j<=c;j++)   ret += j*prob[ct[i]][j];
                bos.write(new Double(ret).toString().getBytes());
                bos.write(eolb);
                t-=1;
            }
            bos.flush();
        }
        catch(Exception e){}
    }
}
