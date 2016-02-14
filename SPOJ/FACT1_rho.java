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
        factor(d); // since rho give all divisors (not only prime divisors)
        factor(N.divide(d)); // d and N/d are both divisors of N
    }
    
    public static void main(String args[])
    {

    try{

        String input="";
        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(isr);
        
        //int t = Integer.parseInt(br.readLine());
        input = br.readLine();
        while(true)
        {
            BigInteger N = new BigInteger(input);
            if(N.compareTo(BigInteger.ZERO) == 0)
                break;

            v.clear();
            factor(N);
            Collections.sort(v);
            int count = 1;
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
                    System.out.print(v.get(i-1)+"^"+count+" ");


                }
                else
                {
                    System.out.print(v.get(i)+"^"+count+" ");
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
            System.out.println();
            input = br.readLine();
        }
    
        }catch(Exception e){}

    }
}
