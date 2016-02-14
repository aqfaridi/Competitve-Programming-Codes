import java.io.*;
import java.util.*;
class Pair implements Comparable<Pair>
{
    int first,second;
    public Pair(int a,int b)
    {
        first = a; second = b;
    }
    public int compareTo(Pair b)
    {
        if(this.first == b.first)
            return new Integer(this.second).compareTo(b.second);//asc
        else 
            return new Integer(this.first).compareTo(b.first);
    }
}

class Main
{
    public static final int MAX = 100010;
    public static final int MOD = 1000000007;
    static int path[];
    static boolean visited[];
    static ArrayList<ArrayList<Pair> > adjList;

    static void dijkstra(int s,int d)
    {
        PriorityQueue<Pair> q = new PriorityQueue<Pair>();
        q.add(new Pair(0,s));
        int u,v,w,size;
        path[s] = 0;
        while(!q.isEmpty())
        {
            Pair p  = q.poll();
            u = p.second;                
                                                                
            if(visited[u])  continue;
            if(u == d)  break;
            size = adjList.get(u).size();
            for(int i=0;i<size;i++)
            {
                v = adjList.get(u).get(i).first;
                w = adjList.get(u).get(i).second;
                if(!visited[v] && path[v] > path[u] + w){
                    path[v] = path[u] + w;
                    q.add(new Pair(path[v],v));
                }
            }
            visited[u] = true;
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
            int n,m,u,v;

            path = new int[MAX];
            visited = new boolean[MAX];
            adjList = new ArrayList<ArrayList<Pair> >();
            for(int i=0;i<MAX;i++)
                adjList.add(new ArrayList<Pair>());

            Arrays.fill(path,MAX*10);
            Arrays.fill(visited,false);

            str = br.readLine(); 
            s = str.split(" ");
            n = Integer.parseInt(s[0]);
            m = Integer.parseInt(s[1]);
            for(int i=0;i<m;i++)
            {
                str = br.readLine(); 
                s = str.split(" ");
                u = Integer.parseInt(s[0]);
                v = Integer.parseInt(s[1]);
                adjList.get(u).add(new Pair(v,0));
                adjList.get(v).add(new Pair(u,1));
            }
            dijkstra(1,n);

            if(path[n] > m)
                bos.write(new Integer(-1).toString().getBytes());
            else                             
                bos.write(new Integer(path[n]).toString().getBytes());
            bos.write(eolb);
            bos.flush();
        }
        catch(Exception e){e.printStackTrace();}
    }
}

