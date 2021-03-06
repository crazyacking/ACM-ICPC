/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-09-19-21.35
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
#define max(a,b) (a>b?a:b)
using namespace std;
typedef long long(LL);
typedef unsigned long long(ULL);
const double eps(1e-8);

const LL MOD3=1000000007;
const LL MOD2=222222224;
const LL MOD1=183120;

const int MAXM=10;
struct Matrix
{
      int n,m;
      LL mat[MAXM][MAXM];
};


Matrix mat_mul(Matrix a,Matrix b,LL M)
{
      Matrix ret;
      ret.n=a.n;
      ret.m=b.m;
      for(int i=0; i<a.n; ++i)
      {
            for(int j=0; j<b.m; ++j)
            {
                  ret.mat[i][j]=0;
                  for(int k=0; k<a.m; ++k)
                  {
                        ret.mat[i][j]+=(a.mat[i][k]*b.mat[k][j]%M);
                        ret.mat[i][j]%=M;
                  }
            }
      }
      return ret;
}


Matrix mat_pow(Matrix a,LL n,LL M)
{
      if(n==1) return a;
      Matrix ret=a;
      Matrix tmp=a;
      for(int i=0; i<a.n; ++i)
      {
            for(int j=0; j<a.n; ++j)
            {
                  if(i==j) ret.mat[i][j]=1;
                  else ret.mat[i][j]=0;
            }
      }
      while(n)
      {
            if(n&1)
                  ret=mat_mul(ret,tmp,M);
            tmp=mat_mul(tmp,tmp,M);
            n>>=1;
      }
      return ret;
}

int main()
{
      Matrix A;
      A.n=2;
      A.m=2;
      A.mat[0][0]=3;
      A.mat[0][1]=1;
      A.mat[1][0]=1;
      A.mat[1][1]=0;
      Matrix f0;
      f0.n=2;
      f0.m=1;
      f0.mat[0][0]=1;
      f0.mat[1][0]=0;
      Matrix tmp1,tmp2;
      LL n;
      while(~scanf("%I64d",&n))
      {
            tmp1=mat_pow(A,n,MOD1);
            tmp2=mat_mul(tmp1,f0,MOD1);
            LL N=tmp2.mat[1][0];
            tmp1=mat_pow(A,N,MOD2);
            tmp2=mat_mul(tmp1,f0,MOD2);
            N=tmp2.mat[1][0];
            tmp1=mat_pow(A,N,MOD3);
            tmp2=mat_mul(tmp1,f0,MOD3);
            N=tmp2.mat[1][0];
            printf("%I64d\n",N);
      }
      return 0;
}
/*

暴力求解循环节：

const int MOD=1000000007;
int main()
{
      int a=1,b=3,c;
      for(int i=1;;++i)
      {
            if(a==0 && b==1)
            {
                  printf("%d\n",i);
                  break;
            }
            c=(3*b+a)%MOD;
            a=b;
            b=c;
      }
      return 0;
}

*/
