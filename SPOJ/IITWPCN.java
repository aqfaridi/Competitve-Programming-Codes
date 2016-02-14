import java.util.*;
import java.io.*;
class Main
{
    public static void main(String[] args) throws IOException
    {
        Scanner sc = new Scanner(System.in);
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t,W,B;
        //t = sc.nextInt();
        t = Integer.parseInt(br.readLine());
        while(t>0)
        {
            //W = sc.nextInt();
            //B = sc.nextInt();
            String[] str = (br.readLine()).split(" ");
            B = Integer.parseInt(str[1]);
            if(B%2 == 1)
                System.out.println("1.000000");
            else
                System.out.println("0.000000");
            t--;
        }
    }
}
