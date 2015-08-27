#include <iostream>
#include <cstring>
#include <queue>
#include <cstdio>
using namespace std;

int main()
{
      int T,n,m;
      scanf("%d",&T);
      while(T--)
      {
            char ch[4];
            scanf("%c %c %c %c\n",&ch[0],&ch[1],&ch[2],&ch[3]);
            int sx=ch[0]-'A',sy=ch[1]-'0',tx=ch[2]-'A',ty=ch[3]-'0';
            if((sx+sy)%2!=(tx+ty)%2){
                  puts("Impossible");
                  continue;
            }
            else{
                  printf("2 %c %c",ch[0],ch[1]);
                  while(sx+sy>tx+ty){
                        --sx,--sy;
                  }
                  while(sx+sy<tx+ty){
                        ++sx,++sy;
                  }
                  printf("%c %c %c %c\n",'A'+sx,'0'+sy,ch[2],ch[3]);
            }
      }
      return 0;
}
