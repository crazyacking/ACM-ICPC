//1004
#include<stdio.h>
#include<iostream>
#include<map>
#include<set>
#include<algorithm>
#include<string.h>
#include<stdlib.h>
using namespace std;
const long long MOD=1000000007;
const long long MOD2=222222224;
const long long MOD3=183120;
const int MAXN=10;
struct Matrix
{
    long long mat[MAXN][MAXN];
    int n,m;
};
Matrix mul(Matrix a,Matrix b,long long m)
{
    Matrix ret;
    ret.n=a.n;
    ret.m=b.m;
    for(int i=0;i<a.n;i++)
       for(int j=0;j<b.m;j++)
       {
           ret.mat[i][j]=0;
           for(int k=0;k<a.m;k++)
           {
               ret.mat[i][j]+=(a.mat[i][k]*b.mat[k][j]%m);
               ret.mat[i][j]%=m;
           }
       }
    return ret;
}
Matrix pow(Matrix a,long long n,long long m)
{
    if(n==1)return a;
    Matrix ret=a;
    Matrix temp=a;
    for(int i=0;i<a.n;i++)
      for(int j=0;j<a.n;j++)
      {
          if(i==j)ret.mat[i][j]=1;
          else ret.mat[i][j]=0;
      }
    while(n)
    {
        if(n&1)ret=mul(ret,temp,m);
        temp=mul(temp,temp,m);
        n>>=1;
    }
    return ret;
}

int main()
{
    //freopen("D.in","r",stdin);
   // freopen("D.out","w",stdout);
    Matrix A;
    A.n=A.m=2;
    A.mat[0][0]=3;
    A.mat[0][1]=1;
    A.mat[1][0]=1;
    A.mat[1][1]=0;
    Matrix f0;
    f0.n=2;
    f0.m=1;
    f0.mat[0][0]=1;
    f0.mat[1][0]=0;


    long long n;
    Matrix tmp;
    Matrix temp;
    while(scanf("%I64d\n",&n)!=EOF)
    {
        temp=pow(A,n,MOD3);
        tmp=mul(temp,f0,MOD3);
        long long tt=tmp.mat[1][0];

        temp=pow(A,tt,MOD2);
        tmp=mul(temp,f0,MOD2);
        tt=tmp.mat[1][0];

        temp=pow(A,tt,MOD);
        tmp=mul(temp,f0,MOD);
        tt=tmp.mat[1][0];

        printf("%I64d\n",tt);
    }

    return 0;
}
