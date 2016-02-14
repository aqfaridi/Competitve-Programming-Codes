import java.util.*;
import java.math.*;
import java.io.*;
class FastReader{
	private boolean finished = false;

	private InputStream stream;
	private byte[] buf = new byte[1024];
	private int curChar;
	private int numChars;
	private SpaceCharFilter filter;

	public FastReader(InputStream stream){
		this.stream = stream;
	}

	public int read(){
		if (numChars == -1){
			throw new InputMismatchException ();
		}
		if (curChar >= numChars){
			curChar = 0;
			try{
				numChars = stream.read (buf);
			} catch (IOException e){
				throw new InputMismatchException ();
			}
			if (numChars <= 0){
				return -1;
			}
		}
		return buf[curChar++];
	}

	public int peek(){
		if (numChars == -1){
			return -1;
		}
		if (curChar >= numChars){
			curChar = 0;
			try{
				numChars = stream.read (buf);
			} catch (IOException e){
				return -1;
			}
			if (numChars <= 0){
				return -1;
			}
		}
		return buf[curChar];
	}

	public int nextInt(){
		int c = read ();
		while (isSpaceChar (c))
			c = read ();
		int sgn = 1;
		if (c == '-'){
			sgn = -1;
			c = read ();
		}
		int res = 0;
		do{
			if(c==','){
				c = read();
			}
			if (c < '0' || c > '9'){
				throw new InputMismatchException ();
			}
			res *= 10;
			res += c - '0';
			c = read ();
		} while (!isSpaceChar (c));
		return res * sgn;
	}

	public long nextLong(){
		int c = read ();
		while (isSpaceChar (c))
			c = read ();
		int sgn = 1;
		if (c == '-'){
			sgn = -1;
			c = read ();
		}
		long res = 0;
		do{
			if (c < '0' || c > '9'){
				throw new InputMismatchException ();
			}
			res *= 10;
			res += c - '0';
			c = read ();
		} while (!isSpaceChar (c));
		return res * sgn;
	}

	public String nextString(){
		int c = read ();
		while (isSpaceChar (c))
			c = read ();
		StringBuilder res = new StringBuilder ();
		do{
			res.appendCodePoint (c);
			c = read ();
		} while (!isSpaceChar (c));
		return res.toString ();
	}

	public boolean isSpaceChar(int c){
		if (filter != null){
			return filter.isSpaceChar (c);
		}
		return isWhitespace (c);
	}

	public static boolean isWhitespace(int c){
		return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
	}

	private String readLine0(){
		StringBuilder buf = new StringBuilder ();
		int c = read ();
		while (c != '\n' && c != -1){
			if (c != '\r'){
				buf.appendCodePoint (c);
			}
			c = read ();
		}
		return buf.toString ();
	}

	public String nextLine(){
		String s = readLine0 ();
		while (s.trim ().length () == 0)
			s = readLine0 ();
		return s;
	}

	public String nextLine(boolean ignoreEmptyLines){
		if (ignoreEmptyLines){
			return nextLine ();
		}else{
			return readLine0 ();
		}
	}

	public BigInteger nextBigInteger(){
		try{
			return new BigInteger (nextString ());
		} catch (NumberFormatException e){
			throw new InputMismatchException ();
		}
	}

	public char nextCharacter(){
		int c = read ();
		while (isSpaceChar (c))
			c = read ();
		return (char) c;
	}

	public double nextDouble(){
		int c = read ();
		while (isSpaceChar (c))
			c = read ();
		int sgn = 1;
		if (c == '-'){
			sgn = -1;
			c = read ();
		}
		double res = 0;
		while (!isSpaceChar (c) && c != '.'){
			if (c == 'e' || c == 'E'){
				return res * Math.pow (10, nextInt ());
			}
			if (c < '0' || c > '9'){
				throw new InputMismatchException ();
			}
			res *= 10;
			res += c - '0';
			c = read ();
		}
		if (c == '.'){
			c = read ();
			double m = 1;
			while (!isSpaceChar (c)){
				if (c == 'e' || c == 'E'){
					return res * Math.pow (10, nextInt ());
				}
				if (c < '0' || c > '9'){
					throw new InputMismatchException ();
				}
				m /= 10;
				res += (c - '0') * m;
				c = read ();
			}
		}
		return res * sgn;
	}

	public boolean isExhausted(){
		int value;
		while (isSpaceChar (value = peek ()) && value != -1)
			read ();
		return value == -1;
	}

	public String next(){
		return nextString ();
	}

	public SpaceCharFilter getFilter(){
		return filter;
	}

	public void setFilter(SpaceCharFilter filter){
		this.filter = filter;
	}

	public interface SpaceCharFilter{
		public boolean isSpaceChar(int ch);
	}
}

class pair implements Comparable<pair>
{
    int first,second;
    public pair(int a,int b)
    {   first = a;second = b;   }

    public int compareTo(pair b)
    {
        if(this.first == b.first)
            return new Integer(b.second).compareTo(this.second);
        else
            return new Integer(b.first).compareTo(this.first);
    }
}
class Main
{
    public static void main(String[] args)
    {
        FastReader sc = new FastReader(System.in);
        PrintWriter out = new PrintWriter(System.out);
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
            out.println(sum);
            t--;
        }
        out.flush();
    }
}

