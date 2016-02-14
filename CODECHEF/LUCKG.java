import java.io.*;
import java.util.*;
class Main
{
    public static final int MAX = 1010;
    public static final int MOD = 1000000007;
    static int permut[],visited[];
    static int ans[][];
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
            boolean flag,ns;
            StringTokenizer st;
            ArrayList<Integer> v = new ArrayList<Integer>();
            int t,n,m,give,prev,sz,trp,temp;

            permut = new int[MAX];
            visited = new int[MAX];
            ans = new int[MAX][MAX];
            Arrays.fill(visited,0);

            str = br.readLine(); t = Integer.parseInt(str);
            while(t>0)
            {
                str = br.readLine(); s = str.split(" ");
                n = Integer.parseInt(s[0]); m = Integer.parseInt(s[1]);
                
                Arrays.fill(visited,0);
                for(int i=0;i<n;i++)
                    Arrays.fill(ans[i],0);
                
                str = br.readLine();
                st = new StringTokenizer(str," ");
                int i = 0;
                flag = ns = false;
                while(st.hasMoreTokens())
                {
                    permut[i] = Integer.parseInt(st.nextToken());
                    if(permut[i] == i)
                        flag = true;
                    i++;
                }

                if(flag || m <= 2 || n <= 2)
                {
                    bos.write("No Solution".getBytes());
                    bos.write(eolb);
                    t -= 1;
                    continue;
                }

                give = 1;
                prev = 0;
                for(i=0;i<n;i++)
                {
                    trp = i;
                    v.clear();
                    if(visited[i] == 0)
                    {
                        do{
                            v.add(trp);
                            visited[trp] = 1;
                            trp = permut[trp];
                        }while(trp != i);
                        Collections.reverse(v);
                        sz = v.size();
                        if(sz == 2)   ns = true;
                        for(int k=0;k<m;k++)
                        {
                            int j = k%sz;
                            ans[v.get(j)][k] = give++;
                            if(k >= 1){
                                temp = ans[prev][k-1];
                                ans[prev][k-1] = ans[v.get(j)][k];
                                ans[v.get(j)][k] = temp;
                            }
                            j++;
                            for(;;j++)
                            {
                                if(ans[v.get(j%sz)][k] != 0) { prev = v.get((j-1+sz)%sz);break;}
                                ans[v.get(j%sz)][k] = give;
                                give++;
                            }
                        }
                    }
                }
                if(ns)
                {
                    bos.write("No Solution".getBytes());
                    bos.write(eolb);
                    t -= 1;
                    continue;
                }

                for(i=0;i<n;i++)
                    Arrays.sort(ans[i],0,m);
                
                for(i=0;i<n;i++)
                {
                    bos.write(new Integer(ans[i][0]).toString().getBytes());
                    for(int j=1;j<m;j++)
                    {
                        bos.write(spaceb);
                        bos.write(new Integer(ans[i][j]).toString().getBytes());
                    }
                    bos.write(eolb);
                }
                t-=1;             
            }
            bos.flush();
        }
        catch(Exception e){e.printStackTrace();}
    }
}

