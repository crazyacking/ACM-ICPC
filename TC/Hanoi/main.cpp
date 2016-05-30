#include <bits/stdc++.h>
using namespace std;

int cnt=0;
int k=0;
void move(char x,char y)
{
    printf("%c%c ",x,y);
    k++;
    if(k%3==0)
        puts("");
}

void hanoi(int m,char a,char b,char c) // 将m个盘从a移动到c
{
    ++cnt;
    if(m==1)
        move(a,c);
    else
    {
        hanoi(m-1,a,c,b);
        move(a,c);
        hanoi(m-1,b,a,c);
    }
}

int main()
{
    k=cnt=0;
    int n;
    scanf("%d",&n);
    hanoi(n,'a','b','c');
    printf("%d\n",cnt);
    return 0;
}
/*

*/
