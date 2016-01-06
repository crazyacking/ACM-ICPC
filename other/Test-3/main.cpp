import java.util.*;

public class Solution
{
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        if (n == 2)
        {
            System.out.println("3 1");
            System.out.println("5 2 3");
        }
        else
        {
            System.out.print(n);
            for (int i = 0; i < n; ++i)
            {
                for (int j = Math.max(0, n + 1 - i); j < n; ++j)
                {
                    System.out.print(" " + (i * n + j + 1));
                }
            }
            System.out.println();
            for (int k = 0; k < n; ++k)
            {
                System.out.print(((n + 1) / 2 + k) * 2 + 1);
                for (int i = Math.max(0, 1 - k); i < Math.min(n, n + 1 - k); ++i)
                {
                    System.out.print(" " + (i * n + (n - k - i) + 1));
                }
                System.out.println();
            }
        }
    }
}
