import java.io.BufferedInputStream;
import java.util.HashMap;
import java.util.Scanner;
import java.util.TreeSet;

public class Main{
    public static void main(String[] argv){
        Scanner in=new Scanner(new BufferedInputStream(System.in));
        int n=in.nextInt();
        TreeSet<Integer> vals=new TreeSet<Integer>();
        vals.add(in.nextInt());
        HashMap<Integer,Integer> ind=new HashMap<Integer,Integer>();
        ind.put(vals.first(),0);
        StringBuilder sb=new StringBuilder();
        for(int i=1;i<n;++i){
            int val=in.nextInt();
            Integer hi=vals.higher(val),
                    lo=vals.lower(val);
            if(hi==null)
                sb.append(lo).append(' ');
            else if(lo==null)
                sb.append(hi).append(' ');
            else
                sb.append(ind.get(hi)<ind.get(lo)?lo:hi).append(' ');
            vals.add(val);
            ind.put(val,i);
        }
        System.out.print(sb);
    }
}




