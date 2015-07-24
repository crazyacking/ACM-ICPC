#include <iostream>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <cstdlib>
#define Coord_x 15
#define Coord_y 15
#define Height  20
#define Width  16

using namespace std;

class Block{

    public:

        int x;
        int y;
        int flag;
        int next_flag;
	int block_speed;
	int block_speed_temp;
        int block_num;
        int score;
        int level;
        int patten_mark[80][80];
        int block[4];

    public:

        void get_flag();

        void make_block();

        void output_block(HANDLE hOutk);

        void clear_Block(HANDLE hOut);

        bool if_move();

        void if_full(HANDLE hOut);

	Block(int bs = 300, int bst = 300, int bn = 0, int s = 0, int l = 1);
}B;


class Console{
    public:

        void gotoxy(HANDLE hOut, int x, int y);

        void enter_game();

        void initialize_window();

        void start_game();

        void end_game();

        friend class Block;
}C;


Block::Block(int bs,int bst,int bn,int s,int l)
{
    block_speed = bs;
    block_speed_temp = bst;
    block_num = bn;
    score = s;
    level = l;
}


void Console::gotoxy(HANDLE hOut, int x, int y)
{
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(hOut, pos);
}


void Console::enter_game()
{
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    system("title 俄罗斯方块 by Tc");
    gotoxy(hOut,Coord_x+Width+1,Coord_y-10);
    SetConsoleTextAttribute(handle,FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
    cout<<"欢迎进入俄罗斯方块";
    for(int i = 8; i > 0; i--)
    {
        gotoxy(hOut,Coord_x+Width-2,Coord_y-i);
        SetConsoleTextAttribute(handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);
        cout << "■■■■■■■■■■■■";
    }
    gotoxy(hOut,Coord_x+Width+2,Coord_y+2);
    SetConsoleTextAttribute(handle,FOREGROUND_INTENSITY | FOREGROUND_RED);
    cout << "按回车键进入游戏\n"<< endl;;
    while(1)
    {
        char c;
        if(kbhit())
        {  //监控键盘是否被按下，并显示按下的字符
            c = getch();
            if(c == 13)
            {
                system("CLS");
                C.initialize_window();
                C.start_game();
            }
        }
        cout << "■" ;
        Sleep(200);
    }
    if(getch() == 27)
    {
        C.end_game();
    }
    else
    {
        C.enter_game();
    }

}


void Console::end_game()
{
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    system("CLS");
    gotoxy(hOut,Coord_x+Width+5,Coord_y-10);
    cout << "游戏结束";
    gotoxy(hOut,Coord_x+Width+5,Coord_y-7);
    cout << "最终得分 : " << B.score << endl;
    exit(0);
}



void Console::initialize_window()
{
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    system("title 俄罗斯方块 by Tc");
    system("color 0C");
    gotoxy(hOut,Coord_x+Width-5,Coord_y-1);
    cout << "**********";
    gotoxy(hOut,Coord_x+Width-5,Coord_y-2);
    cout << "俄罗斯方块";
    gotoxy(hOut,Coord_x+Width-5,Coord_y-3);
    cout << "**********";
    gotoxy(hOut,Coord_x+2*Width+3,Coord_y+6);
    SetConsoleTextAttribute(handle,FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
    cout << "***********";
    gotoxy(hOut,Coord_x+2*Width+3,Coord_y+7);
    cout << "下一个方块:";
    gotoxy(hOut,Coord_x+2*Width+3,Coord_y+12);
    cout << "***********";
    gotoxy(hOut,Coord_x+2*Width+3,Coord_y+Height-4);
    cout << "w键 : 旋转  " << "s键 : 沉底";
    gotoxy(hOut,Coord_x+2*Width+3,Coord_y+Height-2);
    cout << "a键 : 左移  " << "d键 : 右移";
    gotoxy(hOut,Coord_x+2*Width+3,Coord_y+Height);
    cout << "空格键 ：暂停";
    gotoxy(hOut,Coord_x+2*Width+3,Coord_y+Height-6);
    cout << "Esc ：退出";
    SetConsoleTextAttribute(handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);
    for(int i = 0;i < 2 * Width - 1; i += 2)
    {
        gotoxy(hOut,Coord_x+i,Coord_y);
        cout << "*";
    }
    for(int i = 0;i < 2 * Width - 1; i += 2)
    {
        gotoxy(hOut,Coord_x+i,Coord_y+Height);
        cout << "*";
        B.patten_mark[Coord_x+i][Coord_y+Height] = 2;
    }
    for(int i = 0;i < Height;i++)
    {
        gotoxy(hOut,Coord_x,Coord_y+i);
        cout << "*";
        B.patten_mark[Coord_x][Coord_y+i] = 2;
    }
    for(int i = 0;i < Height;i ++)
    {
        gotoxy(hOut,Coord_x+2*Width-2,Coord_y+i);
        cout << "*";
        B.patten_mark[Coord_x+2*Width-2][Coord_y+i] = 2;
    }
 }



void Block::make_block()
{
    B.patten_mark[B.x][B.y] = block[0];
    switch(B.flag)
    {
        case 1:         //田
        {
            B.patten_mark[B.x][B.y-1] = block[1];
            B.patten_mark[B.x+2][B.y-1] = block[2];
            B.patten_mark[B.x+2][B.y] = block[3];
            break;
        }
        case 2:         //横直线
        {
            B.patten_mark[B.x-2][B.y] = block[1];
            B.patten_mark[B.x+2][B.y] = block[2];
            B.patten_mark[B.x+4][B.y] = block[3];
            break;
        }
        case 3:         //竖直线
        {
            B.patten_mark[B.x][B.y-1] = block[1];
            B.patten_mark[B.x][B.y-2] = block[2];
            B.patten_mark[B.x][B.y+1] = block[3];
            break;
        }
        case 4:         //T
        {
            B.patten_mark[B.x-2][B.y] = block[1];
            B.patten_mark[B.x+2][B.y] = block[2];
            B.patten_mark[B.x][B.y+1] = block[3];
            break;
        }
        case 5:         //T顺时针转90度
        {
            B.patten_mark[B.x][B.y-1] = block[1];
            B.patten_mark[B.x][B.y+1] = block[2];
            B.patten_mark[B.x-2][B.y] = block[3];
            break;
        }
        case 6:         //T顺时针转180度
        {
            B.patten_mark[B.x][B.y-1] = block[1];
            B.patten_mark[B.x-2][B.y] = block[2];
            B.patten_mark[B.x+2][B.y] = block[3];
            break;
        }
        case 7:         //T顺时针转270度
        {
            B.patten_mark[B.x][B.y-1] = block[1];
            B.patten_mark[B.x][B.y+1] = block[2];
            B.patten_mark[B.x+2][B.y] = block[3];
            break;
        }
        case 8:         //Z
        {
            B.patten_mark[B.x][B.y+1] = block[1];
            B.patten_mark[B.x-2][B.y] = block[2];
            B.patten_mark[B.x+2][B.y+1] = block[3];
            break;
        }
        case 9:         //Z顺时针转90度
        {
            B.patten_mark[B.x][B.y-1] = block[1];
            B.patten_mark[B.x-2][B.y] = block[2];
            B.patten_mark[B.x-2][B.y+1] = block[3];
            break;
        }
        case 10:        //Z顺时针转180度
        {
            B.patten_mark[B.x][B.y-1] = block[1];
            B.patten_mark[B.x-2][B.y-1] = block[2];
            B.patten_mark[B.x+2][B.y] = block[3];
            break;
        }
        case 11:        //Z顺时针转270度
        {
            B.patten_mark[B.x][B.y+1] = block[1];
            B.patten_mark[B.x+2][B.y-1] = block[2];
            B.patten_mark[B.x+2][B.y] = block[3];
            break;
        }
        case 12:      //倒Z
        {
            B.patten_mark[B.x][B.y+1] = block[1];
            B.patten_mark[B.x+2][B.y] = block[2];
            B.patten_mark[B.x-2][B.y+1] = block[3];
            break;
        }
        case 13:      //倒Z顺时针转90度
        {
            B.patten_mark[B.x-2][B.y] = block[1];
            B.patten_mark[B.x-2][B.y-1] = block[2];
            B.patten_mark[B.x][B.y+1] = block[3];
            break;
        }
        case 14:      //倒Z顺时针转180度
        {
            B.patten_mark[B.x-2][B.y] = block[1];
            B.patten_mark[B.x][B.y-1] = block[2];
            B.patten_mark[B.x+2][B.y-1] = block[3];
            break;
        }
        case 15:      //倒Z顺时针转270度
        {
            B.patten_mark[B.x+2][B.y] = block[1];
            B.patten_mark[B.x][B.y-1] = block[2];
            B.patten_mark[B.x+2][B.y+1] = block[3];
            break;
        }
        case 16:        //7
        {
            B.patten_mark[B.x][B.y-1] = block[1];
            B.patten_mark[B.x][B.y+1] = block[2];
            B.patten_mark[B.x-2][B.y-1] = block[3];
            break;
        }
        case 17:        //7顺时针转90度
        {
            B.patten_mark[B.x-2][B.y]=block[1];
            B.patten_mark[B.x+2][B.y-1]=block[2];
            B.patten_mark[B.x+2][B.y]=block[3];
            break;
        }
        case 18:        //7顺时针转180度
        {
            B.patten_mark[B.x][B.y-1] = block[1];
            B.patten_mark[B.x][B.y+1] = block[2];
            B.patten_mark[B.x+2][B.y+1] = block[3];
            break;
        }
        case 19:        //7顺时针转270度
        {
            B.patten_mark[B.x-2][B.y+1] = block[1];
            B.patten_mark[B.x+2][B.y] = block[2];
            B.patten_mark[B.x-2][B.y] = block[3];
            break;
        }
        case 20:        //倒7
        {
            B.patten_mark[B.x][B.y+1] = block[1];
            B.patten_mark[B.x][B.y-1] = block[2];
            B.patten_mark[B.x+2][B.y-1] = block[3];
            break;
        }
        case 21:        //倒7顺指针转90度
        {
            B.patten_mark[B.x-2][B.y] = block[1];
            B.patten_mark[B.x+2][B.y+1] = block[2];
            B.patten_mark[B.x+2][B.y] = block[3];
            break;
        }
        case 22:        //倒7顺时针转180度
        {
            B.patten_mark[B.x][B.y-1] = block[1];
            B.patten_mark[B.x][B.y+1] = block[2];
            B.patten_mark[B.x-2][B.y+1] = block[3];
            break;
        }
        case 23:        //倒7顺时针转270度
        {
            B.patten_mark[B.x-2][B.y] = block[1];
            B.patten_mark[B.x-2][B.y-1] = block[2];
            B.patten_mark[B.x+2][B.y] = block[3];
            break;
        }
    }
}



bool Block::if_move()
{
    if(B.patten_mark[B.x][B.y] != 0)
    {
        return 0;
    }
    else
    {
        if( (B.flag == 1 && (B.patten_mark[B.x][B.y-1] == 0 && B.patten_mark[B.x+2][B.y-1] == 0 && B.patten_mark[B.x+2][B.y] == 0))
            ||
            (B.flag == 2 && (B.patten_mark[B.x-2][B.y] == 0 && B.patten_mark[B.x+2][B.y] == 0 && B.patten_mark[B.x+4][B.y] == 0))
            ||
            (B.flag == 3 && (B.patten_mark[B.x][B.y-1] == 0 && B.patten_mark[B.x][B.y-2] == 0 && B.patten_mark[B.x][B.y+1] == 0))
            ||
            (B.flag == 4 && (B.patten_mark[B.x-2][B.y] == 0 && B.patten_mark[B.x+2][B.y] == 0 && B.patten_mark[B.x][B.y+1] == 0))
            ||
            (B.flag == 5 && (B.patten_mark[B.x][B.y-1] == 0 && B.patten_mark[B.x][B.y+1] == 0 && B.patten_mark[B.x-2][B.y] == 0))
            ||
            (B.flag == 6 && (B.patten_mark[B.x][B.y-1] == 0 && B.patten_mark[B.x-2][B.y] == 0 && B.patten_mark[B.x+2][B.y] == 0))
            ||
            (B.flag == 7 && (B.patten_mark[B.x][B.y-1] == 0 && B.patten_mark[B.x][B.y+1] == 0 && B.patten_mark[B.x+2][B.y] == 0))
            ||
            (B.flag == 8 && (B.patten_mark[B.x][B.y+1] == 0 && B.patten_mark[B.x-2][B.y] == 0 && B.patten_mark[B.x+2][B.y+1] == 0))
            ||
            (B.flag == 9 && (B.patten_mark[B.x][B.y-1] == 0 && B.patten_mark[B.x-2][B.y] == 0 && B.patten_mark[B.x-2][B.y+1] == 0))
            ||
            (B.flag == 10 && (B.patten_mark[B.x][B.y-1] == 0 && B.patten_mark[B.x-2][B.y-1] == 0 && B.patten_mark[B.x+2][B.y] == 0))
            ||
            (B.flag == 11 && (B.patten_mark[B.x][B.y+1] == 0 && B.patten_mark[B.x+2][B.y-1] == 0 && B.patten_mark[B.x+2][B.y] == 0))
            ||
            (B.flag == 12 && (B.patten_mark[B.x][B.y+1] == 0 && B.patten_mark[B.x+2][B.y] == 0 && B.patten_mark[B.x-2][B.y+1] == 0))
            ||
            (B.flag == 13 && (B.patten_mark[B.x-2][B.y] == 0 && B.patten_mark[B.x-2][B.y-1] == 0 && B.patten_mark[B.x][B.y+1] == 0))
            ||
            (B.flag == 14 && (B.patten_mark[B.x-2][B.y] == 0 && B.patten_mark[B.x][B.y-1] == 0 && B.patten_mark[B.x+2][B.y-1] == 0))
            ||
            (B.flag == 15 && (B.patten_mark[B.x+2][B.y] == 0 && B.patten_mark[B.x][B.y-1] == 0 && B.patten_mark[B.x+2][B.y+1] == 0))
            ||
            (B.flag == 16 && (B.patten_mark[B.x][B.y-1] == 0 && B.patten_mark[B.x][B.y+1] == 0 && B.patten_mark[B.x-2][B.y-1] == 0))
            ||
            (B.flag == 17 && (B.patten_mark[B.x-2][B.y] == 0 && B.patten_mark[B.x+2][B.y-1] == 0 && B.patten_mark[B.x+2][B.y] == 0))
            ||
            (B.flag == 18 && (B.patten_mark[B.x][B.y-1] == 0 && B.patten_mark[B.x][B.y+1] == 0 && B.patten_mark[B.x+2][B.y+1] == 0))
            ||
            (B.flag == 19 && (B.patten_mark[B.x-2][B.y+1] == 0 && B.patten_mark[B.x+2][B.y] == 0 && B.patten_mark[B.x-2][B.y] == 0))
            ||
            (B.flag == 20 && (B.patten_mark[B.x][B.y+1] == 0 && B.patten_mark[B.x][B.y-1] == 0 && B.patten_mark[B.x+2][B.y-1] == 0))
            ||
            (B.flag == 21 && (B.patten_mark[B.x-2][B.y] == 0 && B.patten_mark[B.x+2][B.y+1] == 0 && B.patten_mark[B.x+2][B.y] == 0))
            ||
            (B.flag == 22 && (B.patten_mark[B.x][B.y-1] == 0 && B.patten_mark[B.x][B.y+1] == 0 && B.patten_mark[B.x-2][B.y+1] == 0))
            ||
            (B.flag == 23 && (B.patten_mark[B.x-2][B.y] == 0 && B.patten_mark[B.x-2][B.y-1] == 0 && B.patten_mark[B.x+2][B.y] == 0))
            )
        {
            return 1;
        }
    }
    return 0;
 }



void Block::get_flag()
{
    B.block_num ++;
    srand((unsigned)time(NULL));
    if(B.block_num == 1)
    {
        B.flag = rand()%23+1;
    }
    B.next_flag = rand()%23+1;
}



void Block::output_block(HANDLE hOut)
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    for(int i = 0;i < 4; i++)
    {
        B.block[i] = 1;
    }
    B.make_block();
    for(int i = B.x-2;i <= B.x+4; i += 2)   //打印方块，4*4
    {
        for(int j = B.y-2;j <= B.y+1; j++)
        {
            if(B.patten_mark[i][j] == 1 && j > Coord_y && j < Coord_y + Height)
            {
                C.gotoxy(hOut,i,j);
                SetConsoleTextAttribute(handle,FOREGROUND_INTENSITY |FOREGROUND_GREEN);
                cout << "■";
            }
        }
    }
    SetConsoleTextAttribute(handle,FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
    C.gotoxy(hOut,Coord_x+2*Width+3,Coord_y);
    cout << "等级 : " << B.level;
    C.gotoxy(hOut,Coord_x+2*Width+3,Coord_y+2);
    cout << "分数 : " << B.score;
    C.gotoxy(hOut,Coord_x+2*Width+3,Coord_y+4);
    cout << "速度 : " << B.block_speed << "ms";
}


void Block::clear_Block(HANDLE hOut)
{
    for(int i = 0;i < 4; i++)
    {
        block[i] = 0;
    }
    B.make_block();
    for(int i = B.x-2; i <= B.x+4; i +=2)
    {
        for(int j = B.y-2;j <= B.y+1; j++)
        {
            if(B.patten_mark[i][j] == 0 && j > Coord_y && j < Coord_y + Height)
            {
                C.gotoxy(hOut,i,j);
                cout << "  ";
            }
        }
    }
}


void Block::if_full(HANDLE hOut)
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    int block_count, delete_block_num = 0;  //block_count记录某行方块的个数,delete_block_num记录删除方块的行数的变量
    for(int j = Coord_y+Height-1;j >= Coord_y+1; j--)
    {
        block_count = 0;
        for(int i = Coord_x+2;i < Coord_x+2*Width-2; i += 2)
        {
            if(B.patten_mark[i][j] == 1)
            {
                block_count++;
                if(block_count == Width-2)
                {
                    for(block_count = Coord_x+2; block_count < Coord_x+2*Width-2; block_count += 2)
                    {
                        B.patten_mark[block_count][j] = 0;
                        C.gotoxy(hOut,block_count,j);
                        cout << "  ";
                        Sleep(0);
                    }
                    for(block_count = j-1;block_count > Coord_y; block_count--)
                    {
                        for(i = Coord_x+2;i < Coord_x+2*Width-2; i += 2)
                        {
                            if(B.patten_mark[i][block_count] == 1)
                                {
                                    B.patten_mark[i][block_count]=0;
                                    C.gotoxy(hOut,i,block_count);
                                    cout << "  ";
                                    B.patten_mark[i][block_count+1]=1;
                                    C.gotoxy(hOut,i,block_count+1);
                                    SetConsoleTextAttribute(handle,FOREGROUND_INTENSITY |FOREGROUND_GREEN);
                                    cout << "■";
                                }
                        }
                    }
                    j++;
                    delete_block_num++;
                }
            }
        }
    }
    B.score += 100 * delete_block_num;
    if(delete_block_num > 0 && (B.score%1000 == 0 || B.score / 1000 > B.level - 1 ))
    {
        block_speed_temp -= 20;
        B.level++;
    }
}



void Console::start_game()
{
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    int temp,temp1,temp2;
    char ch;
    while(1)
    {
        B.get_flag();
        temp = B.flag;
        B.x = Coord_x + 2 * Width + 6;
        B.y = Coord_y + 10;
        B.flag = B.next_flag;
        B.output_block(hOut);
        B.x = Coord_x + Width;
        B.y = Coord_y - 1;
        B.flag = temp;
        while(1)
        {
            Loop:
                B.output_block(hOut);
                Sleep(B.block_speed);
                B.clear_Block(hOut);
                temp1 = B.x;
                temp2 = B.flag;
                if(kbhit())
                {
                    ch = getch();
                    if(ch == 97)
                    {
                        B.x -= 2;
                    }
                    if(ch == 100)
                    {
                        B.x += 2;
                    }
                    if(ch == 115)
                    {
                        B.block_speed = 0;
                    }
                    if(ch == 119) //加一取余实现旋转
                    {
                        if(B.flag >= 2 && B.flag <= 3)
                        {
                            B.flag++;
                            B.flag %= 2;
                            B.flag += 2;
                        }
                        if(B.flag >= 4 && B.flag <= 7)
                        {
                            B.flag++;
                            B.flag %= 4;
                            B.flag += 4;
                        }
                        if(B.flag >= 8 && B.flag <= 11)
                        {
                            B.flag++;
                            B.flag %= 4;
                            B.flag += 8;
                        }
                        if(B.flag >= 12 && B.flag <= 15)
                        {
                            B.flag++;
                            B.flag %= 4;
                            B.flag += 12;
                        }
                        if(B.flag >= 16 && B.flag <= 19)
                        {
                            B.flag++;
                            B.flag %= 4;
                            B.flag += 16;
                        }
                        if(B.flag >= 20 && B.flag <= 23)
                        {
                            B.flag++;
                            B.flag %= 4;
                            B.flag += 20;
                        }
                    }
                    if(ch == 27)
                    {
                        C.end_game();
                    }
                    if(ch == ' ')
                    {
                        B.output_block(hOut);
                        while(1)
                        {
                            if(kbhit())
                            {
                                ch = getch();
                                if(ch == 32)
                                {
                                    goto Loop;
                                }
                            }
                        }
                    }
                    if(B.if_move() == 0)
                    {
                        B.x = temp1;
                        B.flag = temp2;
                    }
                    else
                    {
                        goto Loop;
                    }
                }
            B.y++;
            if(B.if_move() == 0)
            {
                B.y--;
                B.output_block(hOut);
                B.if_full(hOut);
                B.block_speed = B.block_speed_temp;
                break;
            }
        }
        for(int i = B.y-2;i < B.y+2; i++)
        {
            if(i == Coord_y)
            {

                C.end_game();
            }
        }
        B.flag = B.next_flag;
        B.x = Coord_x + 2 * Width + 6;
        B.y = Coord_y + 10;
        B.clear_Block(hOut);
    }
}


int main()
{
    C.enter_game();
	return 0;
}
