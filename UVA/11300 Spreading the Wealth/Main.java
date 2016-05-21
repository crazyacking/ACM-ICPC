import java.io.BufferedInputStream;
import java.util.Arrays;
import java.util.Scanner;

public class Main{
    public static void main(String[] argv){
        Scanner in = new Scanner(new BufferedInputStream(System.in));
        while(in.hasNext()){
            int n=in.nextInt();
            int[] a=new int[n];
            Long sum= Long.valueOf(0);
            for(int i=0;i<n;++i){
                a[i]=in.nextInt();
                sum+=a[i];
            }
            int ave=(int)(sum/n);
            int[] d=new int[n];
            d[0]=0;
            for(int i=1;i<n;++i){
                d[i]=d[i-1]+ave-a[i];
            }
            Arrays.sort(d,0,n);
            int mid=d[n/2];
            Long ans=Long.valueOf(0);
            for(int i=0;i<n;++i){
                ans+=Math.abs(mid-d[i]);
            }
            System.out.println(ans);
        }
    }
}