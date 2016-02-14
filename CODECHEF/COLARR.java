import java.util.*;
class pair implements Comparable<pair>
{
    int first,second;
    public pair(int a,int b)
    {   first = a;second = b;   }

    public int compareTo(pair b)
    {
        if(this.first == b.first)
            return new Integer(b.second).compareTo(new Integer(this.second));
        else
            return new Integer(b.first).compareTo(new Integer(this.first));
    }
}
class Main
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        ArrayList< pair > v = new ArrayList< pair >();
        int t,size,n,m,k,idx,maxx,var,diff;
        long sum=0;
        t = sc.nextInt();
        while(t>0)
        {
            v.clear();
            sum = 0;
            n = sc.nextInt();
            m = sc.nextInt();
            k = sc.nextInt();
            
            int[] arr = new int[n+1];
            int[] visited = new int[n+1];
            Arrays.fill(visited,0);
            for(int i=1;i<=n;i++)
                arr[i] = sc.nextInt();
            
            int[][] B = new int[n+1][m+1];
            for(int i=1;i<=n;i++)
                for(int j=1;j<=m;j++)
                    B[i][j] = sc.nextInt();

            for(int i=1;i<=n;i++)
            {
                maxx = Integer.MIN_VALUE;
                for(int j=1;j<=m;j++)
                {
                    var = sc.nextInt();
                    B[i][j] -= var;
                    if(j == (arr[i]))
                        continue;
                    maxx = Math.max(maxx,B[i][j]);
                }
                if(maxx > B[i][arr[i]])
                {
                    diff = maxx - B[i][arr[i]];
                    v.add(new pair(diff,i));
                }
            }
            pair[] p = new pair[v.size()];
            Collections.sort(v); 
            p = v.toArray(p);
            size = v.size();
            for(int i=0;i<Math.min(size,k);i++)
            {
                //System.out.println(p[i].first+" "+p[i].second);
                idx = p[i].second;
                sum += (p[i].first + B[idx][arr[idx]]);
                visited[idx] = 1;
            }
           
            for(int i=1;i<=n;i++)
            {
                if(visited[i] == 0)
                    sum += B[i][arr[i]];
            }
            System.out.println(sum);

            t--;
        }
    }
}
