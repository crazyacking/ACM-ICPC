#include<stdio.h>
#include<string.h>
int main()
{
    // Ҳ���Ըĳ� char str[] = "http://see.xidian.edu.cn/cpp/u/xitong/";
    char *str = "http://see.xidian.edu.cn/cpp/u/xitong/";
    char *substr = "see";
    char *s = strstr(str, substr);
    printf("%s\n", s);
    return 0;
}
