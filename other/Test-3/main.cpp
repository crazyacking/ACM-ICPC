/**
 * -----------------------------------------------------------------
 * Copyright (c) 2016 crazyacking.All rights reserved.
 * -----------------------------------------------------------------
 *       Author: crazyacking
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

const int MAXN=1000010;
char s1[MAXN],s2[MAXN],tmp[MAXN];
int main()
{
      while(~scanf("%s %s",s1,s2))
      {
            memset(tmp,'\0',sizeof tmp);
            int l1=strlen(s1);
            int l2=strlen(s2);
            if(l1==l2)
            {
                  int ret=strcmp(s1,s2);
                  if(ret<0)
                        printf("<");
                  else if(ret==0)
                        printf("=");
                  else
                        printf(">");
            }
            else if(l1<l2)
            {
                  int cnt=l2-1;
                  for(int i=l1-1;i>=0;--i)
                  {
                        tmp[cnt]=s1[i];
                        cnt--;
                  }
                  for(int i=cnt;i>=0;--i)
                        tmp[i]='0';
//                  puts(tmp);
                  int ret=strcmp(tmp,s2);
                  if(ret<0)
                        printf("<");
                  else if(ret==0)
                        printf("=");
                  else
                        printf(">");
            }
            else
            {
                  int cnt=l1-1;
                  tmp[l1]='\0';
                  for(int i=l2-1;i>=0;)
                        tmp[cnt--]=s2[i--];
                  for(int i=cnt;i>=0;--i)
                        tmp[i]='0';
//                  puts(tmp);
                  int ret=strcmp(s1,tmp);
                  if(ret<0)
                        printf("<");
                  else if(ret==0)
                        printf("=");
                  else
                        printf(">");
            }
      }
      return 0;
}
