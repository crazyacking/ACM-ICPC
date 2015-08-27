#include <iostream>
#include <cstring>
#include <queue>
#include <cstdio>
using namespace std;
int dx[]= {-1,-1,+1,+1};
int dy[]= {-1,+1,+1,-1};
char s[10];
int r[2],c[2];
int main()
{
      int T,n,m;
      scanf("%d",&T);
      while(T--)
      {
            for(int i=0;i<2;i++)
            {
                  scanf("%s%d",s,&r[i]);
                  c[i]=s[0]-'A'+1;
            }
            if((r[0]+c[0])%2!=(r[1]+c[1])%2)
                  puts("Impossible");
            else if(r[0]==r[1]&&c[0]==c[1])
                  printf("0 %c %d\n",char(c[0]+'A'-1),r[0]);
            else if(r[0]+c[0]==r[1]+c[1]||r[0]-c[0]==r[1]-c[1])
                  printf("1 %c %d %c %d\n",char(c[0]+'A'-1),r[0],char(c[1]+'A'-1),r[1]);
            else
            {
                  bool flag=0;
                  for(int i=0;i<4;i++)
                  {
                        int tr=r[0],tc=c[0];
                        while(1)
                        {
                              tr+=dx[i];
                              tc+=dy[i];
                              if(tr<1||tc<1||tr>8||tc>8)
                                    break;
                              if(tr+tc==r[1]+c[1]||tr-tc==r[1]-c[1])
                              {
                                    flag=1;
                                    break;
                              }
                        }
                        if(flag)
                        {
                              printf("2 %c %d %c %d %c %d\n",
                              char(c[0]+'A'-1),r[0],char(tc+'A'-1),tr,char(c[1]+'A'-1),r[1]);
                              break;
                        }
                  }
            }
      }
      return 0;
}
