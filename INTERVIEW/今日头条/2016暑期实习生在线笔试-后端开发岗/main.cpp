/**<

<2016����ͷ����˿������߱���>

����n���ַ���������ö��ÿ���ַ�������������֣�ʹ����n���ַ��������������֮�����

˼·���򵥵�dfs

����д��̫��æ��һ��Сbug���˺þã�ע����ͷ����Ե :(

 */

/**
 * -----------------------------------------------------------------
 * Copyright (c) 2016 crazyacking.All rights reserved.
 * -----------------------------------------------------------------
 *       Author: crazyacking
 *       Date  : 2016-04-27-20.23
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

bool ff[10];
long long answer;
int ss_len,p[10],n;
char s[60][20],ss[10];

long long get_num(int x)
{
    int len=strlen(s[x]);
    long long res=0;
    for(int i=0;i<len;++i)
    {
        int idx=s[x][i]-'A';
        int cur=p[idx];
        res=res*10+cur;
    }
    return res;
}

long long solve()
{
    long long num;
    long long sum=0;
    for(int i=0;i<n;++i)
    {
        num=get_num(i);
        sum+=num;
    }
    return sum;
}


void dfs(int wei)
{
    if(wei==ss_len)
    {
        long long res=solve();
        answer=max(answer,res);
        return;
    }

    for(int i=0;i<10;++i)
    {
        if(!ff[i])
        {
            p[ss[wei]-'A']=i;
            ff[i]=true;
            dfs(wei+1);
            ff[i]=false;
        }
    }
}


void work()
{
    memset(ff,false,sizeof(ff));
    answer=LLONG_MIN;
    int len;
    bool has[10];
    memset(has,0,sizeof(has));
    for(int i=0;i<n;++i)
    {
        len=strlen(s[i]);
        for(int j=0;j<len;++j)
            has[s[i][j]-'A']=1;
    }
    int cnt=0;
    memset(ss,'\0',sizeof(ss));
    for(int i=0;i<10;++i)
    {
        if(has[i])
            ss[cnt++]=i+'A';
    }
    ss_len=strlen(ss);
    dfs(0);
    printf("%lld\n",answer);
}


int main()
{
    while(~scanf("%d",&n))
    {
        for(int i=0;i<n;++i)
            scanf("%s",s[i]);
        work();
    }
    return 0;
}
/*

*/
