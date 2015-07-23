/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-07-22-22.45
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
#define NN 200000+50
char A[NN],B[NN];
int cmp(char x[] , char y[] , int len)
{
      for(int i=0;i<len;++i)
      {
            if(x[i]<y[i])
            {
                  return -1;
            }
            else if(x[i]>y[i])
            {
                  return 1;
            }
      }

//      bool isok =true;
//      for(int i=0;i<len;++i)
//            if(x[i]!=y[i]) isok=false;
//      return isok;
}


void work(int len,char x[])
{
      if(len%2==1) return ;
      work(len/2,x);
      work(len/2,x+len/2);
      if(cmp(x,x+len/2,len/2)>0)
      {
            for(int i=0;i<len/2;++i)
            {
                  swap(x[i],x[i+len/2]);
            }
      }
}
//
//bool equ(char x[] , char y[] , int len)
//{
//      if(cmp(x,y,len))
//            return true;
//      if(len%2==0)
//            return (equ(x,y+len/2,len/2) && equ(x+len/2,y,len/2))||(equ(x,y,len/2) && equ(x+len/2,y+len/2,len/2));
//      return false;
//}
int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      scanf("%s %s",A,B);
      int len=strlen(A);
      work(len,B);
      work(len,A);
      if(strcmp(A,B)==0)
      {
            puts("YES");
      }
      else
      {
            puts("NO");
      }
      return 0;
}
/*

*/
