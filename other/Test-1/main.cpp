/**
 * -----------------------------------------------------------------
 * Copyright (c) 2016 crazyacking.All rights reserved.
 * -----------------------------------------------------------------
 *       Author: crazyacking
 *       Date  : 2016-01-06-18.14
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
#include<ctime>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long(LL);
typedef unsigned long long(ULL);
const double eps(1e-8);

int a[5];
void work()
{
      int st=0;
      int cu=0;
      int en=4;
      while(cu<=en)
      {
            if(a[cu]==0)
            {
                  swap(a[cu],a[st]);
                  cu++;
                  st++;
            }
            else if(a[cu]==1)
            {
                  cu++;
            }
            else
            {
                  swap(a[cu],a[en]);
                  en--;
            }
      }
      for(int i=0;i<5;++i)
            cout<<a[i]<<" ";
      cout<<endl;
}
int main()
{
      srand((unsigned)time(NULL));
      for(int i=0;i<5;++i)
      {
            int tmp=rand()%3;
            a[i]=tmp;
            cout<<a[i]<< " ";
      }
      cout<<endl;
      work();
      for(int i=0;i<5;++i)
            cout<<a[i]<<" ";
      cout<<endl;
      return 0;
}
