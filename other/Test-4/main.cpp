#include<cstdio>
#include<cstring>
int l1,l2;
int a[1000010],b[10010],Next[10010];

void getNext()
{
      Next[0]=0;
      int i,k;
      for(i=1,k=0;i<l2;++i)
      {
            while(b[i]!=b[k] && k>0)
                  k=Next[k-1];
            if(b[i]==b[k]) ++k;
            Next[i]=k;
      }
}
int kmp()
{
      getNext();
      for(int i=0,k=0;i<l1;++i)
      {
            while(a[i]!=b[k] && k>0)
                  k=Next[k-1];
            if(a[i]==b[k]) ++k;
            if(k==l2) return i-l2+2;
      }
      return -1;
}
int main()
{
      int t;
      scanf("%d",&t);
      while(t--)
      {
            scanf("%d %d",&l1,&l2);
            for(int i=0;i<l1;++i) scanf("%d",&a[i]);
            for(int i=0;i<l2;++i) scanf("%d",&b[i]);
            printf("%d\n",kmp());
      }
      return 0;
}
