/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-10-21-21.28
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

double D;

// 各自的角速度
double v_shi=360./(12*60*60),v_fen=360./(60*60),v_miao=360./60;

// 相对角速度
double v_shi_fen=fabs(360./(12*60*60)-360./(60*60));
double v_shi_miao=fabs(360./(12*60*60)-360./60);
double v_fen_miao=fabs(360./(60*60)-360./60);

// 相遇周期
double T_shi_fen=360/v_shi_fen;
double T_shi_miao=360/v_shi_miao;
double T_fen_miao=360/v_fen_miao;

// 计算第一次满足/不满足的时间
double bg_shi_fen;
double bg_shi_miao;
double bg_fen_miao;

double en_shi_fen;
double en_shi_miao;
double en_fen_miao;
void calc_first_time()
{
      bg_shi_fen=D/v_shi_fen;
      bg_shi_miao=D/v_shi_miao;
      bg_fen_miao=D/v_fen_miao;

      en_shi_fen=(360-D)/v_shi_fen;
      en_shi_miao=(360-D)/v_shi_miao;
      en_fen_miao=(360-D)/v_fen_miao;
}

double half_day=12*60*60+0.000001;
void work()
{
      double l,r,sum=0;
      for(double bg1=bg_shi_fen,en1=en_shi_fen; en1<=half_day; bg1+=T_shi_fen,en1+=T_shi_fen)
      {
            for(double bg2=bg_shi_miao,en2=en_shi_miao; en2<=half_day; bg2+=T_shi_miao,en2+=T_shi_miao)
            {
                  if(en2<bg1) continue;
                  if(bg2>en1) break;
                  for(double bg3=bg_fen_miao,en3=en_fen_miao; en3<=half_day; bg3+=T_fen_miao,en3+=T_fen_miao)
                  {
                        if(en3<bg1 || en3<bg2) continue;
                        if(bg3>en1 ||bg3>en2) break;
                        l=max(bg1,max(bg2,bg3));
                        r=min(en1,min(en2,en3));
                        sum+=r-l>0?r-l:0;
                  }
            }
      }
      printf("%.3f\n",sum/half_day*100.);
}


int main()
{
      while(scanf("%lf",&D),D!=-1)
      {
            calc_first_time();
            work();
      }
      return 0;
}
/*

*/
