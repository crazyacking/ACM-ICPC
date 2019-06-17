#include <bits/stdc++.h>
using namespace std;

const int MAX_LEN=1000030;
char s[MAX_LEN];
int idx[200];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s",s);
        for(int i=0;i<200;++i)
            idx[i]=-1;
        int len=strlen(s);
        for(int i=0;i<len;++i)
        {
            if(idx[s[i]]==-1)
                idx[s[i]]=i;
            else idx[s[i]]=-2;
        }
        char ans='\0';
        for(int i=0;i<200;++i)
        {
            if(idx[i]>=0)
            {
                if(ans=='\0' || idx[i]<idx[ans])
                    ans=i;
            }
        }
        printf("%c\n",ans);
    }
    return 0;
}



/**<

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef long long ll;

const int MAXN=1000000;

int idx[256];
int T;
char str[MAXN+5];

int main()
{
    for(scanf("%d",&T); T--;)
    {
        scanf("%s",str+1);
        memset(idx,0,sizeof(idx));
        for(int i=1; str[i]; i++)
        {
            if(idx[str[i]]==0)
            {
                idx[str[i]]=i;
            }
            else
                idx[str[i]]=-1;
        }
        char ans='\0';
        for(int i=0x21; i<0x7F; i++)
        {
            if(idx[i]>0)
            {
                if(ans==0||idx[ans]>idx[i]) ans=i;
            }
        }
        printf("%c\n",ans);
    }
    return 0;
}


 */
