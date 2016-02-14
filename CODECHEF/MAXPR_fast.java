import java.io.*;
import java.util.*;
import java.math.*;

class Main
{
    public static final int MAX = 200010;
    public static final int  MOD = 1000000007;
    static int[] arr;
    static int[] cnt;
    static int[] cumm;
    static int[] cumm2;
    static int expo(long a,long n)
    {
        long result = 1;
        while(n>0)
        {
            if(n%2 == 1)
                result = (result*a)%MOD;
            a = (a*a)%MOD;
            n >>= 1;
        }
        return ((int)result%MOD);
    }

    public static void main(String[] aqf)
    {
        try
        {
            cumm = new int[110];
            cumm2 = new int[110];
            cnt = new int[110];
            arr = new int[MAX];
            int t,n,minn,maxx,dmaxx,prev,next,ans;
            FastReader sc = new FastReader(System.in);
            BufferedOutputStream bos = new BufferedOutputStream(System.out);
            String eol = System.getProperty("line.separator");
            byte[] eolb = eol.getBytes();

            t = sc.nextInt();
            while(t>0)
            {
                minn = Integer.MAX_VALUE;
                maxx = Integer.MIN_VALUE;
                n = sc.nextInt();

                for(int i=0;i<n;i++)
                {
                    arr[i] = sc.nextInt();
                    minn = Math.min(minn,arr[i]);
                    maxx = Math.max(maxx,arr[i]);
                }
             
                dmaxx = (maxx-minn);
                ans = 1;
                for(int d=0;d<=dmaxx;d++)
                {
                    Arrays.fill(cumm,0);
                    Arrays.fill(cnt,0);
                    Arrays.fill(cumm2,0);
                    for(int i=0;i<n;i++)
                    {
                        prev = arr[i] - d;
                        next = arr[i] + d;
                        if(prev >= minn && prev <= maxx)
                            cumm[arr[i]] = ((cumm[arr[i]] + cumm[prev])%MOD + cnt[prev])%MOD;
                        if(next >= minn && next <= maxx)
                            cumm2[arr[i]] = ((cumm2[arr[i]] + cumm2[next])%MOD + cnt[next])%MOD;

                        cnt[arr[i]]++;
                    }
                    if(d == 0)  Arrays.fill(cumm2,0);
                    for(int i=minn;i<=maxx;i++)
                        ans = ((ans+cumm[i])%MOD + cumm2[i])%MOD;
                }
                ans = (ans + n)%MOD;
                ans =  (expo(2,n) - ans + MOD)%MOD;
                bos.write(new Integer(ans).toString().getBytes());
                bos.write(eolb);

                t -= 1;
            }
            bos.flush();
        }
        catch(Exception e){}
    }
}
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
