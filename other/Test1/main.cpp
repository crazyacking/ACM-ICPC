/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-08-24-16.08
* Time: 0MS
* Memory: 137KB
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
#define  LL long long
#define  ULL unsigned long long
using namespace std;

char* itoa(int num,char*str,int base)
{
      /*索引表*/
      char index[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
      unsigned unum;/*中间变量*/
      int i=0,j,k;
      /*确定unum的值*/
      if(base==10&&num<0)/*十进制负数*/
      {
            unum=(unsigned)-num;
            str[i++]='-';
      }
      else unum=(unsigned)num;/*其他情况*/
      /*转换*/
      do
      {
            str[i++]=index[unum%(unsigned)base];
            unum/=base;
      }while(unum);
      str[i]='\0';
      /*逆序*/
      if(str[0]=='-')k=1;/*十进制负数*/
      else k=0;
      char temp;
      for(j=k; j<=(i-1)/2; j++)
      {
            temp=str[j];
            str[j]=str[i-1+k-j];
            str[i-1+k-j]=temp;
      }
      return str;
}
int cnt[200];
void work(int x)
{
      char s[15233];
      itoa(x,s,2);
      for(int i=0;i<strlen(s);++i)
      {
            if(s[i]=='1') ++cnt[i];
      }
      puts(s);
}
int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int t;
      scanf("%d",&t);
      for(int Cas=1; Cas<=t; ++Cas)
      {
            LL A,B,N;
            memset(cnt,0,sizeof cnt);
            cin>>A>>B>>N;
            for(int i=1; i<=N; ++i)
            {
                  work(B+A*i);
            }
            for(int i=0;i<20;++i)
            {
                  printf("%d ",cnt[i]);
            }
            putchar(10);
      }
      return 0;
}
/*

*/
