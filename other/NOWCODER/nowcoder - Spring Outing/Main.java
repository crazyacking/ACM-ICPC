import java.util.Scanner;
import java.io.*;

public class Main
{
    public static void main (String[] args)
    {
        Scanner in = new Scanner(System.in);
        while (in.hasNext())
        {
            int N = in.nextInt();
            int K = in.nextInt();
            int[][] priorityMaps = new int[N][K+1];

            for(int i=0; i<N; i++)
            {
                for(int j=0; j<=K; j++)
                {
                    int priorityIndex = in.nextInt();
                    priorityMaps[i][priorityIndex] = j;
                }
            }
            int candidate = 0;
            for(int i=K; i>0; i--)
            {
                int votes = 0;
                for(int j =0; j<N; j++)
                {
                    if(priorityMaps[j][i] < priorityMaps[j][candidate])
                    {
                        votes++;
                    }
                }
                if(votes > N/2)
                {
                    candidate = i;
                }
            }
            if(candidate == 0)
            {
                System.out.println("otaku");
            }
            else
            {
                System.out.println(candidate);
            }
        }
    }
}
