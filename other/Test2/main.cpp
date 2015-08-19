/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-08-19-22.24
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



/*
  Miller_Rabin 算法进行素数测试
  可以判断 <2^63的数
*/
const int S=20;//随机算法判定次数，S越大，判错概率越小
//计算 (a*b)%c.   a,b都是long long的数，直接相乘可能溢出
//  a,b,c <2^63
long long mult_mod(long long a,long long b,long long c)
{
      a%=c;
      b%=c;
      long long ret=0;
      while(b)
      {
            if(b&1) {ret+=a; ret%=c;}
            a<<=1;
            if(a>=c)a%=c;
            b>>=1;
      }
      return ret;
}

//计算  x^n %c
long long pow_mod(long long x,long long n,long long mod)//x^n%c
{
      if(n==1)return x%mod;
      x%=mod;
      long long tmp=x;
      long long ret=1;
      while(n)
      {
            if(n&1) ret=mult_mod(ret,tmp,mod);
            tmp=mult_mod(tmp,tmp,mod);
            n>>=1;
      }
      return ret;
}

//以a为基,n-1=x*2^t      a^(n-1)=1(mod n)  验证n是不是合数
//一定是合数返回true,不一定返回false
bool check(long long a,long long n,long long x,long long t)
{
      long long ret=pow_mod(a,x,n);
      long long last=ret;
      for(int i=1; i<=t; i++)
      {
            ret=mult_mod(ret,ret,n);
            if(ret==1&&last!=1&&last!=n-1) return true;//合数
            last=ret;
      }
      if(ret!=1) return true;
      return false;
}
// Miller_Rabin()算法素数判定
//是素数返回true.(可能是伪素数，但概率极小)
//合数返回false;
bool Miller_Rabin(long long n)
{
      if(n<2)return false;
      if(n==2)return true;
      if((n&1)==0) return false;//偶数
      long long x=n-1;
      long long t=0;
      while((x&1)==0) {x>>=1; t++;}
      for(int i=0; i<S; i++)
      {
            long long a=rand()%(n-1)+1;//rand()需要stdlib.h头文件
            if(check(a,n,x,t))
                  return false;//合数
      }
      return true;
}
//************************************************
//pollard_rho 算法进行质因数分解
//************************************************
long long factor[100];//质因数分解结果（刚返回时是无序的）
int tol;//质因数的个数。数组小标从0开始

long long gcd(long long a,long long b)
{
      if(a==0)return 1;
      if(a<0) return gcd(-a,b);
      while(b)
      {
            long long t=a%b;
            a=b;
            b=t;
      }
      return a;
}

long long Pollard_rho(long long x,long long c)
{
      long long i=1,k=2;
      long long x0=rand()%x;
      long long y=x0;
      while(1)
      {
            i++;
            x0=(mult_mod(x0,x0,x)+c)%x;
            long long d=gcd(y-x0,x);
            if(d!=1&&d!=x) return d;
            if(y==x0) return x;
            if(i==k) {y=x0; k+=k;}
      }
}
//对n进行素因子分解
void findfac(long long n)
{
      if(Miller_Rabin(n))//素数
      {
            factor[tol++]=n;
            return;
      }
      long long p=n;
      while(p>=n)p=Pollard_rho(p,rand()%(n-1)+1);
      findfac(p);
      findfac(n/p);
}

int main()
{
      long long n;
      while(scanf("%I64d",&n)!=EOF)
      {
            if(Miller_Rabin(n))
            {
                  printf("Prime\n");
                  continue;
            }
            tol=0;
            findfac(n);
            for(int i=0; i<tol; i++)printf("%I64d ",factor[i]);
            printf("\n");
      }
      return 0;
}
