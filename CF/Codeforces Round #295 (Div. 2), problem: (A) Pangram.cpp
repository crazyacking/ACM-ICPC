#include<cstdio>
#include<cstring>
#include<cctype>
int main()
{
    char s[105];
    bool f[26];
    memset(f,0,sizeof(f));
    int n;
    scanf("%d",&n);
    scanf("%s",s);
    for(int i=0;i<n;i++) f[tolower(s[i])-97]=1;
    for(int i=0;i<26;i++) if(!f[i])
    {
        puts("NO");
        return 0;
    }
    puts("YES");
    return 0;
}
