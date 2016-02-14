import java.util.*;
import java.math.*;
class Main
{
    public static void main(String args[])
    {
        int t;
        Boolean b;
        Scanner sc = new Scanner(System.in);
        t=sc.nextInt();
        while(t>0)
        {
            b=false;
            BigInteger bi = sc.nextBigInteger();
            BigInteger i;
            for(i = bi ; i.compareTo(BigInteger.ONE) > 0;i = i.subtract(BigInteger.ONE))
            {
                //System.out.println(i);
                b = i.isProbablePrime(1000);
                if(b)
                    break;
            }
            System.out.println(i);

            t=t-1;
        }
        
    }
}
