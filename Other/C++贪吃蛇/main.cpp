#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<conio.h>
using namespace std;

typedef struct{ int x, y; }Point;

char map[22][22];                        //定义一个22*22的地图（含边界）
Point snake[400], food, Next;            //定义蛇、食物、下一步蛇头的位置
int head, tail;                            //用于储存蛇头和蛇尾的下标
int grade, length, autotime;            //游戏等级、蛇长、自动前进所需时间
char direction;                            //前进方向

//用inline定义内联函数节省程序运行时的调用开销
//刷新地图
inline void Update(char map[][22], int grade, int length, int autotime)
{
    system("cls");                        //清屏
    int i, j;
    printf("\n");
    for (i = 0; i < 22; i++)
    {
        printf("\t");
        for (j = 0; j < 22; j++)
            printf("%c ", map[i][j]);
        if (i == 0)
            printf("\t等级为：%d", grade);
        if (i == 2)
            printf("\t长度为：%d", length);
        if (i == 6)
            printf("\t自动前进时间");
        if (i == 8)
            printf("\t间隔为：%d ms", autotime);
        printf("\n");
    }
}

//欢迎界面
inline void hello()
{
    puts("\n\n\n\t\t\t贪吃蛇游戏即将开始！");                        //准备开始
    double start;
    for (int i = 3; i >= 0; i--)
    {
        start = (double)clock() / CLOCKS_PER_SEC;                //得到程序目前为止运行的时间
        while ((double)clock() / CLOCKS_PER_SEC - start <= 1);    //经过1秒之后
        if (i > 0)
        {
            system("cls");                                        //清屏
            printf("\n\n\n\t\t\t进入倒计时：%d\n", i);                //倒计时
        }
        else
            Update(map, grade, length, autotime);                //刷新地图
    }
}

//随机生成食物位置
inline void f()
{
    srand(int(time(0)));                                        //调用种子函数
    do{
        food.x = rand() % 20 + 1;
        food.y = rand() % 20 + 1;
    } while (map[food.x][food.y] != ' ');
    map[food.x][food.y] = '!';                                    //食物为“!”
}

//初始化
inline void init()
{
    int i, j;
    for (i = 1; i <= 20; i++)
        for (j = 1; j <= 20; j++)
            map[i][j] = ' ';
    for (i = 0; i <= 21; i++)
        map[0][i] = map[21][i] = map[i][0] = map[i][21] = '*';    //边界
    map[1][1] = map[1][2] = 'O';                                //蛇身（含蛇尾）
    map[1][3] = '@';                                            //蛇头
    head = 2; tail = 0;                                            //开始时头和尾的下标
    snake[head].x = 1; snake[head].y = 3;                        //开始时蛇头在地图上的下标
    snake[tail].x = 1; snake[tail].y = 1;                        //开始时蛇尾在地图上的下标
    snake[1].x = 1; snake[1].y = 2;                                //开始时蛇身在地图上的下标
    f();                                                        //随机生成食物位置
    grade = 1; length = 3; autotime = 500;                        //开始的等级、长度、自动前进时间
    direction = 77;                                                //初始的运动方向向右
}

//预前进
inline int GO()
{
    bool timeover = true;
    double start = (double)clock() / CLOCKS_PER_SEC;            //得到程序目前为止运行的时间

    //自动经过1秒或者等待1秒内的键盘输入
    while ((timeover = ((double)clock() / CLOCKS_PER_SEC - start <= autotime / 1000.0)) && !_kbhit());
    //键盘输入
    if (timeover)
    {
        _getch();
        direction = _getch();                                    //获取方向
    }
    switch (direction)
    {
    case 72:
        Next.x = snake[head].x - 1; Next.y = snake[head].y;        //向上
        break;
    case 80:
        Next.x = snake[head].x + 1; Next.y = snake[head].y;        //向下
        break;
    case 75:
        Next.x = snake[head].x; Next.y = snake[head].y - 1;        //向左
        break;
    case 77:
        Next.x = snake[head].x; Next.y = snake[head].y + 1;        //向右
        break;
    default:
        puts("\tGame over!");                                    //按下非方向键游戏失败
        return 0;
    }
    if (Next.x == 0 || Next.x == 21 || Next.y == 0 || Next.y == 21)            //撞到边界
    {
        puts("\tGame over!");
        return 0;
    }
    if (map[Next.x][Next.y] != ' '&&!(Next.x == food.x&&Next.y == food.y))    //吃到自己
    {
        puts("\tGame over!");
        return 0;
    }
    if (length == 400)                                                        //最长蛇长
    {
        puts("\tGood game!");
        return 0;
    }
    return 1;
}

//吃到食物
inline void EAT()
{
    length++;                                        //长度增加1
    int _grade = length / 10 + 1;                    //计算等级
    if (_grade != grade)
    {
        grade = _grade;
        if (autotime >= 100)
            autotime = 550 - grade * 50;            //增加一级自动时间减短50毫秒
    }
    map[Next.x][Next.y] = '@';                        //蛇头位置变化
    map[snake[head].x][snake[head].y] = 'O';        //原蛇头位置变化为蛇身
    head = (head + 1) % 400;                        //蛇头下标加1
    snake[head].x = Next.x; snake[head].y = Next.y;    //蛇头下标变化
    f();                                            //随机生成食物位置
    Update(map, grade, length, autotime);            //刷新地图
}

//没吃到食物
inline void FAILURE()
{
    map[snake[tail].x][snake[tail].y] = ' ';        //蛇尾原来的位置变成“ ”
    tail = (tail + 1) % 400;                        //蛇尾下标加1
    map[Next.x][Next.y] = '@';                        //蛇头位置变化
    map[snake[head].x][snake[head].y] = 'O';        //原蛇头位置变化为蛇身
    head = (head + 1) % 400;                        //蛇头下标加1
    snake[head].x = Next.x;                            //蛇头下标变化
    snake[head].y = Next.y;
    Update(map, grade, length, autotime);            //刷新地图
}

//main函数
int main()
{
    init();                    //初始化
    hello();                //欢迎界面
    while (1)
    {
        if (GO())            //预前进
        {
            if (Next.x == food.x&&Next.y == food.y)
                EAT();        //吃到食物
            else
                FAILURE();    //没吃到食物
        }
        else
            return 0;        //失败或者胜利，游戏结束
    }
    return 0;
}
//
