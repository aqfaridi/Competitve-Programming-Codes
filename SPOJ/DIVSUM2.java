import java.math.*;
import java.security.SecureRandom;
import java.io.*;
import java.util.*;
class Main
{
    static BigInteger TWO = new BigInteger("2");
    static SecureRandom random = new SecureRandom();
    static Vector<BigInteger> v = new Vector<BigInteger>();
    
    static BigInteger rho(BigInteger N)
    {
        // f(x) = x*x + c  mod N ;
        BigInteger d = new BigInteger("1");
        BigInteger x = new BigInteger(N.bitLength(),random);
        BigInteger c = new BigInteger(N.bitLength(),random);
        BigInteger y = x;
        
        if(N.mod(TWO).compareTo(BigInteger.ZERO) == 0)
            return TWO;
    
        // initially d = 1
        // while d == 1  :::coprime random number
        // 1 and N are trivial divisors of N
        while(d.compareTo(BigInteger.ONE)==0)
        {
            //searching for divisors
            // x = f(x) 
            // y = f(f(y))
            x = x.multiply(x).mod(N).add(c).mod(N);
            y = y.multiply(y).mod(N).add(c).mod(N);
            y = y.multiply(y).mod(N).add(c).mod(N);

            // both x and y are random
            // since f(x) is pseudo random function
            d = (x.subtract(y).abs()).gcd(N); // d = gcd(|x-y|,N);
        }
        //while terminated when d is divisor of n other than 1
        return d;
    }
    static void factor(BigInteger N)
    {
        if(N.compareTo(BigInteger.ONE) == 0)
            return ;
        if(N.isProbablePrime(20))// if prime factor is coming from recursion
        {
            v.add(N);
            return ;
        }
        BigInteger d = rho(N);
        factor(d); // since who give all divisors (not only prime divisors)
        factor(N.divide(d)); // d and N/d are both divisors of N
    }
    static BigInteger expo(BigInteger a,BigInteger n)
    {
        
        BigInteger result = new BigInteger("1");
        while(n.compareTo(BigInteger.ZERO) > 0)
        {
            if((n.mod(TWO)).compareTo(BigInteger.ZERO) ==1)
                result = result.multiply(a);
            a = a.multiply(a);
            n = n.divide(TWO) ;
        
        }
        return result;
    }
    public static void main(String args[])
    {

    try{

        String input="";
        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(isr);
        
        int t = Integer.parseInt(br.readLine());
        //input = br.readLine();
        while(t>0)
        {
            input = br.readLine();
            BigInteger N = new BigInteger(input);
            v.clear();
            factor(N);
            Collections.sort(v);
            int count = 1;
            
            BigInteger pro = new BigInteger("1");
            //BigInteger temp = v.get(0);
            for(int i=0;i<v.size();i++)
            {
                count = 1;
                if((i+1)<v.size() && v.get(i).compareTo(v.get(i+1))==0 )
                {
                    while((i+1)<v.size() && v.get(i).compareTo(v.get(i+1))==0 )
                    {
                        count++;
                        i++;
                    }
                    pro = pro.multiply( (expo(v.get(i-1),BigInteger.valueOf(count+1)).subtract(BigInteger.ONE)).divide((v.get(i-1)).subtract(BigInteger.ONE))  )  ;
                   // System.out.print(v.get(i-1)+"^"+count+" ");



                }
                else
                {
                    
                    pro = pro.multiply( (expo(v.get(i),BigInteger.valueOf(1+1)).subtract(BigInteger.ONE)).divide((v.get(i)).subtract(BigInteger.ONE))  )  ;
                    //pro = pro.multiply( (expo(v.get(i-1),BigInteger.valueOf(1+1)).subtract(BigInteger.ONE)).divide(BigInteger.valueOf(count-1))  )  ;
                    //System.out.print(v.get(i)+"^"+count+" ");
                }

                /**
                System.out.print(v.get(i)+" ");
                if(temp.compareTo(v.get(i)) == 0)
                {
                    
                    while(temp.compareTo(v.get(i)) == 0)
                    {
                        count++;
                        temp = v.get(i);
                        i++;
                    }
                    System.out.print(temp+"^"+count+" ");
                    count = 1;
                    temp = v.get(i);
                }
                else
                {
                    count = 1;
                    System.out.print(temp+"^"+count);
                    temp = v.get(i);
                }
                **/
            }
            System.out.print(pro.subtract(N));
            System.out.println();
            t=t-1;
        }
    
        }catch(Exception e){}

    }
}
