# include <stdio.h>
# define abs(x) x>0?x:-(x);
  int gcd(int a,int b)
  {
      return b?gcd(b,a%b):a;
  }
  int main()
  {
      int i,k,t,hh,mm,ss,h,m,s,ans[4],g[4];
      scanf("%d",&t);
      while(t--)
      {
          scanf("%d:%d:%d",&hh,&mm,&ss);
          if(hh>=12)
            hh-=12;
          k=120;
          h=3600*hh+60*mm+ss;
          m=720*mm+12*ss;
          s=720*ss;
          ans[1]=abs(h-m);ans[2]=abs(h-s);ans[3]=abs(m-s);
          for(i=1;i<=3;i++)
            if(ans[i]>180*k)
              ans[i]=360*k-ans[i];
          for(i=1;i<=3;i++)
          {
              g[i]=gcd(ans[i],k);
              if(k/g[i]==1)
                printf("%d ",ans[i]/g[i]);
              else
                printf("%d/%d ",ans[i]/g[i],k/g[i]);
          }
          putchar('\n');
      }
      return 0;
  }
