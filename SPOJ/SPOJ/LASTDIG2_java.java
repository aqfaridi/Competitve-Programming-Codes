import java.util.*;

class Main
{
    public static void main(String args[])
    {
try{
        Scanner sc=new Scanner(System.in);
        int t;
        double   a,b,pwr;
        String str;
        
        t=sc.nextInt();
        while(t>0)
        {
            str=sc.next();
            b=sc.nextDouble();
            a=str.charAt(str.length()-1)-48.0;
         
            if(b==0)
            {System.out.println("1");continue;}

            b=(b%100)%4;

            if(b==0)
                b=4;

            pwr=Math.pow(a,b);
         
            System.out.printf("%.0f\n",pwr%10);
            t--;
        }
} 
catch(Exception e)
{return ;}
    }

}
