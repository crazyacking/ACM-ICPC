/**
 * -----------------------------------------------------------------
 * Copyright (c) 2016 crazyacking.All rights reserved.
 * -----------------------------------------------------------------
 *       Author: crazyacking
 *       Date  : 2016-03-28-20.03
 */
#include <queue>
#include <cstdio>
#include <set>
#include <string>
#include <stack>
#include <cmath>
#include <climits>
#include <map>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long(LL);
typedef unsigned long long(ULL);
const double eps(1e-8);
const int MAXN=300010;

int n,m;
char str[MAXN];

int a[MAXN];
char b[MAXN];

int get_init_ans()
{
    int res=0,len=strlen(str),cnt;
    for(int i=0; i<len; ++i)
    {
        if(str[i]=='.')
        {
            cnt=0;
            while(i<len && str[i]=='.')
            {
                ++i,++cnt;
            }
            res+=cnt-1;
        }
    }
    return res;
}

int main()
{
    while(~scanf("%d %d",&n,&m))
    {
        scanf("%s",str);
        for(int i=0; i<m; ++i)
            scanf("%d %c",&a[i],&b[i]);

        int res=get_init_ans();
        int cnt=0,len=strlen(str);
        for(int i=0; i<m; ++i)
        {
            if(b[i]==str[a[i]-1] || (str[a[i]-1]>='a' && str[a[i]-1]<='z' && b[i]>='a' && b[i]<='z'))
            {
                printf("%d\n",res);
                continue;
            }
            if(b[i]=='.') // 把字母换为.
            {
                cnt=0;
                for(int j=i-1; j>=0; --j) //往前统计
                {
                    if(str[j]=='.')
                    {
                        ++cnt;
                        if(cnt>=1)
                            break;
                    }
                    else break;
                }
                for(int j=i+1; j<len; ++j)
                {
                    if(str[j]=='.')
                    {
                        ++cnt;
                        if(cnt>=1)
                            break;
                    }
                    else break;
                }

                if(cnt>=1)
                {
                    if(((a[i]-2>0)&&str[a[i]-2]!='.') || ((a[i]<len &&str[a[i]]!='.'))) //处于两端
                        res+=1;
                    else res+=2;
                }

            }
            else //把.换为字母
            {
                cnt=0;
                for(int j=i; j>=0; --j) //往前统计
                {
                    if(str[j]=='.')
                    {
                        ++cnt;
                        if(cnt>1)
                            break;
                    }
                    else break;
                }
                for(int j=i+1; j<len; ++j)
                {
                    if(str[j]=='.')
                    {
                        ++cnt;
                        if(cnt>1)
                            break;
                    }
                    else break;
                }

                if(cnt>1)
                {
                    if(((a[i]-2>0)&&str[a[i]-2]!='.') || ((a[i]<len &&str[a[i]]!='.'))) //处于两端
                        res-=1;
                    else res-=2;
                }
            }
            str[a[i]-1]=b[i];
            puts(str);
            printf("%d\n",res);
        }
    }
    return 0;
}

/*

8 4
ab..c...
1 .
2 .
5 .
5 a

*/
