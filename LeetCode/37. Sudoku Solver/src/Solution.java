import java.io.BufferedInputStream;
import java.util.Scanner;

/**
 * Created by crazyacking on 2016/3/3.
 */
public class Solution {
    public void solveSudoku(char[][] board) {
        recursiveSoluve(board);
    }

    public boolean recursiveSoluve(char[][] board)
    {
        for(int i=0;i<9;++i)
        {
            for(int j=0;j<9;++j)
            {
                if(board[i][j]=='.')
                {
                    for(char c='1';c<='9';++c)
                    {
                        board[i][j]=c;
                        if(isValid(board,i,j) && recursiveSoluve(board))
                            return true;
                        board[i][j]='.';
                    }
                }
            }
            return false;
        }
        return true;
    }

    public boolean isValid(char[][] board,int r1,int c1)
    {
        for(int i=0;i<9;++i)
        {
            if(i!=r1 && board[i][c1]==board[r1][c1])
                return false;
            if(i!=c1 && board[r1][i]==board[r1][c1])
                return false;
        }
        int rowBegin=r1/3*3;
        int colBegin=c1/3*3;
        for(int i=rowBegin;i<rowBegin+3;++i)
        {
            for(int j=colBegin;j<colBegin+3;++j)
            {
                if(i!=r1 && j!=c1 && board[i][j]==board[r1][c1])
                    return false;
            }
        }
        return true;
    }
    public static void main()
    {
        Scanner cin=new Scanner(new BufferedInputStream(System.in));
        Solution solution=new Solution();
        char[][] ve;
        for(int i=0;i<9;++i)
        {
            for(int j=0;j<9;++j)
            {
                ve=new char[][];
                ve[i]=new char[9];
                ve[i][j]=cin.next();
            }
        }
        solution.solveSudoku(ve);
    }
}