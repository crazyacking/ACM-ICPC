/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-08-20-20.24
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



int fun(vector<int> bx,int *cnt,int num) // num =1 : dan   num =2 : duizi
{
      int bx_si=bx.size();
      vector<int> type;
      for(int i=0;i<bx_si;++i)
      {
            if(cnt[bx[i]]>=3)
                  type.push_back(bx[i]);
      }
      int type_si=type.size();
      int ret=-1;
      for(int i=0;i<type_si;++i)
      {
            int diff=0;
            if(num==1)
            {
                  for(int j=0;j<bx_si;++j)
                  {
                        if(bx[j]!=type[i]&&cnt[bx[i]]>=1) ++diff;
                  }
            }
            else if(num==2)
            {
                  for(int j=0;j<bx_si;++j)
                        if(bx[j]!=type[i] && cnt[bx[i]]>=2)++diff;
            }
            if(diff>=2)
            {
                 ret=max(ret,type[i]);
            }
      }
      return ret;
}


int airCraft(vector<int>ax,vector<int>bx,int *cnt1,int cnt2)
{
      bool Is_A_have_airCraft=false;
      vector<int>Thd;
      for(int i=0;i<ax.size();++i)
      {
            if(cnt[ax[i]]==3)
            {
                  Thd.push_back(ax[i]);
            }
      }
      int conti=0;
      int Max_conti=-1;
      set<int> continue_ax_back;
      set<int> continue_ax;
      for(int i=0;i<Thd.size();++i)
      {
            if(Thd[i]==Thd[i+1])
            {
                  contine_ax_back.clear();
                  while(Thd[i]==Thd[i+1])
                  {
                        continue_ax_back.insert(Thd[i]);
                        continue_ax_back.insert(Thd[i+1]);
                        ++i;
                        ++conti;

                  }
                  --i;
            }
            if(Max_conti>conti)
            {
                  Max_conti=max(Max_conti,conti);
                  set<int>::iterator set_it;
                  for(set_it)
                  {
                        continue_ax.insert()
                  }
            }
            Max_conti=max(Max_conti,conti);
      }



}

int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(0);

      return 0;
}
/*

*/
