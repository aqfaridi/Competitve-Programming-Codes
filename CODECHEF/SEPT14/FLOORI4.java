import java.io.*;
import java.util.*;
import java.math.*;
class Main
{
    public static final int MAX = 1000010;
    public static final int MOD = 1000000007;
    static long n,M;
    static int[] ar,f;
    static BigInteger m,b0,b1,b2,b3,b4,one,div,b;
    static BigInteger tsum(long i){
	    Arrays.fill(f,0);
	    long I = i,I1 = i+1 , I2 = 2*i+1;
	    for(int j=0;j<=2;j++)
	    {
		    if(i%ar[j] == 0){
		        I = I/ar[j];
		        f[ar[j]] = 1;
		    }
		    else if((i+1)%ar[j] == 0){
		        I1 = I1/ar[j];
		        f[ar[j]] = 1;
		    }
		    else if((2*i+1)%ar[j] == 0){
		        I2 = I2/ar[j];
		        f[ar[j]] = 1;
		    }
	    }

	    int x = 0,pro = 1;
	    for(int j=1;j<=5;j++){
		    if(j == ar[x]){
		        if(f[ar[x]] == 0)
		            pro *= ar[x];
		        x += 1;
		    }
	    }

        b = BigInteger.valueOf(i);
        b0 = BigInteger.valueOf(I);
        b1 = BigInteger.valueOf(I1);
        b2 = BigInteger.valueOf(I2);
        one = BigInteger.valueOf(1);
        b3 = BigInteger.valueOf(3*i);
        b4 = b3.multiply(b).add(b3).subtract(one);
        div = BigInteger.valueOf(pro);
        b4 = b4.divide(div);

        return b0.multiply(b1).mod(m).multiply(b2).mod(m).multiply(b4).mod(m);
    }
    static BigInteger psum(long prev,long idx){
        return tsum(idx).subtract(tsum(prev)).mod(m);
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
            int t;
            long prev,idx;
            BigInteger b,ans,id;
            ar = new int[3]; ar[0] = 2; ar[1] = 3;ar[2] = 5;
            f = new int[10];
            str = br.readLine(); t = Integer.parseInt(str);
            while(t>0)
            {
                str = br.readLine();
                s = str.split(" ");
                n = Long.parseLong(s[0]);M = Long.parseLong(s[1]);
                m = BigInteger.valueOf(M);
                prev = (long)Math.sqrt(n); 
                ans = BigInteger.valueOf(0);
                for(long i=(long)Math.sqrt(n);i>=1;i--){
                    idx = n/i;
                    id = BigInteger.valueOf(idx);
                    b = BigInteger.valueOf(i);
                    ans = ans.add(b.pow(4).multiply(id).mod(m).add( b.multiply(psum(prev,idx)).mod(m))).mod(m);
                    prev = idx;
                }
                System.out.println(ans);
                bos.write(ans.toString().getBytes());
                bos.write(eolb);
                t-=1;             
            }
            bos.flush();
        }
        catch(Exception e){e.printStackTrace();}
    }
}

