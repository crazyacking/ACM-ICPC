#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
bool isok[13];
void create()
{
      isok[1]=isok[3]=isok[5]=isok[7]=isok[8]=isok[10]=isok[12]=1;
}
struct node
{
      int y,m,d,h,m,s;
      node(){}
};
node add(node x,int val)
{
    x.m+=val;
    int t=x.m/60;
    x.m%=60;
      x.h+=t;
      t=x.h/24;
      x.h%=24;

      x.d+=t;
      if(x.m==2)
      {
            if(x.y==2016)
            {
                  if(x.d>29)
                        t=1;
                  else
                        t=0;
            }
            else
            {

            }
      }
}
int main()
{

    return 0;
}
