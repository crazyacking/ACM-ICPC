import java.io.BufferedInputStream;
import java.util.ArrayList;
import java.util.Scanner;

/**
 * Created by crazyacking on 2016/6/9.
 */
// poj 1068 Parencodings
public class Main {
    public static void main(String[] args){
        Scanner in=new Scanner(new BufferedInputStream(System.in));
        int Cas;
        Cas=in.nextInt();
        while((Cas--)!=0){
            int n=in.nextInt();
            int[] p=new int[n];
            for(int i=0;i<n;++i){
                p[i]=in.nextInt();
            }
            StringBuilder sb=new StringBuilder();
            int l=0;
            for(int i=0;i<n;++i){
                int lNum=p[i]-l;
                while((lNum--)!=0){
                    sb.append('(');
                }
                sb.append(')');
                l=p[i];
            }
            n=sb.length();
            boolean[] use=new boolean[n];
            for(int i=0;i<n;++i)
                use[i]=false;
            ArrayList<Integer> arr=new ArrayList();
            for(int i=0;i<n;++i){
                if(sb.charAt(i)==')'){
                    int j=i-1,gap=1;
                    while(j>=0){
                        if(sb.charAt(j)=='(' && use[j]==false){
                            use[j]=true;
                            arr.add((gap));
                            break;
                        }
                        else if(sb.charAt(j)=='('){
                            ++gap;
                        }
                        --j;
                    }
                }
            }
            for(int i=0;i<arr.size();++i){
                System.out.print(arr.get(i)+" ");
            }
            System.out.println();
        }
    }
}
