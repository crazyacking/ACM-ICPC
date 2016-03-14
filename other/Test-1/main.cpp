#include<bits/stdc++.h>
using namespace std;
char input_file_dir[]="H:\\blog\\input.txt";
char output_file_dir[]="H:\\blog\\output.txt";
char s1[200];


bool Is_first_title(char str[])
{
    int a[10][2]=
    {
        {-46,-69},
        {-74,-2},
        {-56,-3},
        {-53,-60},
        {-50,-27},
        {-63,-7},
        {-58,-33},
        {-80,-53},
        {-66,-59},
        {-54,-82},
    };
    bool ret=false;
    for(int i=0; i<10; ++i)
    {
        if(str[0]==a[i][0] && str[1]==a[i][1])
        {
            ret=true;
            break;
        }
    }
    return ret;
}

void The_end()
{
      puts("<p><span style=\"font-family: 'courier new', courier; font-size: 16px; line-height: 28px; color: #000000;\">");
      printf("--------------------------------------------------------- End.");
      puts("</span></p>");

      puts("<p><span style=\"font-family: 'courier new', courier; font-size: 16px; line-height: 28px; color: #000000;\">");
      printf("转载请注明：http://www.cnblogs.com/crazyacking/");
      puts("</span></p>");
}

int main()
{
//      Is_first_title(s1);
    freopen(input_file_dir,"r",stdin);
    freopen(output_file_dir,"w",stdout);
    int line_cnt=0;
    int null_line=0;
    while(gets(s1))
    {
        int type=0;
        int len=strlen(s1);
        int kong_ge_shu=0;
        for(int i=0; i<len; ++i)
        {
            if(s1[i]==' ')
                kong_ge_shu++;
        }
        if(len==0 || kong_ge_shu==len)
        {
            null_line++;
            if(null_line>0)
                continue;
        }
        else null_line=0;
        for(int i=0; i<len; ++i)
        {
            if((i+1<len) && s1[i]==-95 && s1[i+1]==-94)  //、
            {
                s1[i]='.';
                s1[i+1]=' ';
            }

            if((i+1<len) && s1[i]==-95 && s1[i+1]==-93) //。
            {
                s1[i]='.';
                s1[i+1]='\n';
            }
        }
        if(Is_first_title(s1))
        {
            puts("<p><strong><span style=\"font-family: 'Microsoft YaHei'; font-size: 14pt; \">");
            printf("%s",s1);
            puts("</span></strong></p>");
        }
        else
        {
//            puts("<p style=\"line-height: 2em;\"><span style=\"font-size: 18px; font-family: 楷体;\">&nbsp;&nbsp;&nbsp;&nbsp;<span style=\"font-family: 黑体; font-size: 16px;\">");
            puts("<p><span style=\"font-family: 'courier new', courier; font-size: 16px; line-height: 28px; color: #000000;\">");
            printf("%s",s1);
            puts("</span></p>");
        }
    }
    The_end();
    return 0;
}
