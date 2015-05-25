import java.math.BigInteger;
import java.util.Scanner;

public class Main
{
    static Scanner in=new Scanner(System.in);
    public static void main(String[] args)
    {
        BigInteger k,n,w;
        long a,b,c;
        while(in.hasNext())
        {
            a=in.nextLong();
            b=in.nextLong();
            c=in.nextLong();
            k=BigInteger.valueOf(a);
            n=BigInteger.valueOf(b);
            w=BigInteger.valueOf(c);
            BigInteger ans=(w.multiply(k).add(w.multiply((w.subtract(BigInteger.valueOf(1))).multiply(k)).divide(BigInteger.valueOf(2)))).subtract(n);
            int flag=ans.compareTo(BigInteger.valueOf(0));
            if(flag<0)
                System.out.println(0);
            else
                System.out.println(ans);
        }
    }
}
