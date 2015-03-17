#include <cstdio>
#include <iostream>

using namespace std;

int N = 0;
bool CheckStoneNum(int x[][6])
{
    for(int k=0; k<6; k++)
    {
        int NumRow = 0;
        int NumCol = 0;
        for(int i=0; i<6; i++)
        {
            if(x[k][i]) NumRow++;
            if(x[i][k]) NumCol++;
        }
        if(NumRow!=3 || NumCol!=3)//填空
            return false;
    }
    return true;
}
int GetRowStoneNum(int x[][6], int r)
{
    int sum = 0;
    for(int i=0; i<6; i++)     if(x[r][i]) sum++;
    return sum;
}
int GetColStoneNum(int x[][6], int c)
{
    int sum = 0;
    for(int i=0; i<6; i++)     if(x[i][c]) sum++;
    return sum;
}
void show(int x[][6])
{
    for(int i=0; i<6; i++)
    {
        for(int j=0; j<6; j++) printf("%2d", x[i][j]);
        printf("\n");
    }
    printf("\n");
}
void f(int x[][6], int r, int c);
void GoNext(int x[][6],  int r,  int c)
{
    if(c<6)
       f(x,r,c+1);   //填空
    else
        f(x, r+1, 0);
}


void f(int x[][6], int r, int c)
{
    if(r==6)
    {
        if(CheckStoneNum(x))
        {
            N++;
            show(x);
        }
        return;
    }
    if(x[r][c])  // 填空------已经放有了棋子
    {
        GoNext(x,r,c);
        return;
    }
    int rr = GetRowStoneNum(x,r);
    int cc = GetColStoneNum(x,c);
    if(cc>=3)  // 本列已满
        GoNext(x,r,c);
    else if(rr>=3)  // 本行已满
        f(x, r+1, 0);
    else
    {
        x[r][c] = 1;
        GoNext(x,r,c);
        x[r][c] = 0;
        if(!(3-rr >= 6-c || 3-cc >= 6-r))  //本行或本列严重缺子，则本格不能空着！
            GoNext(x,r,c);
    }
}
int main(int argc, char* argv[])
{
    int x[6][6] = {
        {1,0,0,0,0,0},
        {0,0,1,0,1,0},
        {0,0,1,1,0,1},
        {0,1,0,0,1,0},
        {0,0,0,1,0,0},
        {1,0,1,0,0,1}
    };
    f(x, 0, 0);
    printf("%d\n", N);
    return 0;
}
