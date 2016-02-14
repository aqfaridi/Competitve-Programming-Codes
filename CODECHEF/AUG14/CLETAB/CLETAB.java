import java.io.*;
import java.util.*;
class Main
{
    public static final int MAX = 500;
    public static final int MOD = 1000000007;
    static int o[],seat[],index[][],n,m;
    static void backtrace()
    {
        for(int i=m-1;i>=0;i--)
        {
            for(int j=450;j>=1;j--)
                index[i][j] = index[i+1][j];
            index[i][o[i]] = i;
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
            int t,cnt,mxx,location;

            o = new int[500];
            seat = new int[500];
            index = new int[500][500];
            boolean b;

            str = br.readLine(); t = Integer.parseInt(str);
            while(t>0)
            {
                for(int i=0;i<500;i++)
                    Arrays.fill(index[i],500);
                Arrays.fill(seat,0);

                str = br.readLine(); 
                s = str.split(" ");
                n = Integer.parseInt(s[0]);m = Integer.parseInt(s[1]);
                str = br.readLine();
                st = new StringTokenizer(str);
                int ii = 0;
                while(st.hasMoreTokens())
                {
                    o[ii] = Integer.parseInt(st.nextToken());
                    ii++;
                }
                backtrace();
                cnt = 0;
                for(int i=0;i<m;i++)
                {
                    b = false;
                    for(int j=0;j<n;j++)
                        if(seat[j] == o[i])
                        {
                            b = true;
                            break;
                        }
                    if(b)   continue;
                    
                    for(int j=0;j<n;j++)
                        if(seat[j] == 0){
                            seat[j] = o[i];
                            cnt++;
                            b = true;
                            break;
                        }
                    if(b)   continue;

                    mxx = -1; location = 0;
                    for(int j=0;j<n;j++)
                    {
                        if(index[i][seat[j]] > mxx){
                            mxx = index[i][seat[j]];
                            location = j;
                        }
                    }
                    cnt++;
                    seat[location] = o[i];                    
                }



                bos.write(new Integer(cnt).toString().getBytes());
                bos.write(eolb);
                t-=1;             
            }
            bos.flush();
        }
        catch(Exception e){e.printStackTrace();}
    }
}

