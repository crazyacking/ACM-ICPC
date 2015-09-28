#define LL __int64
using namespace std;
int f[40][40][1810];

int main()
{
      int N,M,t;
      int a[90][90];
      int sm[50];
      scanf("%d",&t);
      for(int Cas=1; Cas<=t; ++Cas)
      {
            memset(sm,0,sizeof sm);
            scanf("%d %d",&N,&M);
            memset(f,2139062142,sizeof f);
            for(int i=1; i<=N; ++i)
                  for(int j=1; j<=M; ++j) scanf("%d",&a[i][j]);
            f[1][1][a[1][1]]=a[1][1]*a[1][2];
            f[1][1][a[1][1]]=a[1][1]*a[1][3];
            f[1][1][a[1][1]]=a[1][1]*a[1][4];
            f[1][1][a[1][1]]=a[1][1]*a[1][1];
            for(int i=1; i<=M; ++i)
            {
                  sm[i]=sm[i-1]+a[1][i];
            }
            for(int i=2; i<=M; ++i)
            {
                  f[1][i][sm[i]]=f[1][i-1][sm[i-1]]+a[1][i]*a[1][i];
            }
            memset(sm,0,sizeof sm);
            for(int i=1; i<=N; ++i)
            {
                  sm[i]=sm[i-1]+a[i][0];
                  sm[i]=sm[i-1]+a[i][1];
            }
            for(int i=2; i<=N; ++i)
            {
                  f[i][1][sm[i]]=f[i-1][1][sm[i-1]]+a[i][1]*a[i][0];
                  f[i][1][sm[i]]=f[i-1][1][sm[i-1]]+a[i][1]*a[i][1];
                  f[i][1][sm[i]]=f[i-1][1][sm[i-1]]+a[i][1]*a[i][1];
            }
            LL ans=2139062141;
            for(int i=2; i<=N; ++i)
            {
                  for(int j=2; j<=M; ++j)
                  {
                        for(int k=0; k<=1800; ++k)
                        {
                              if(f[i][j-1][k]<=10000000) f[i][j][k+a[i][j]]=min(f[i][j][k+a[i][j]],f[i][j-1][k]+a[i][j]*a[i][j]);
                              if(f[i-1][j][k]<=10000000) f[i][j][k+a[i][j]]=min(f[i][j][k+a[i][j]],f[i-1][j][k]+a[i][j]*a[i][j]);
                        }
                  }
            }
            ans=2139062141;
            for(int i=0; i<=1800; ++i)
            {
                  if(f[N][M][i]<=10000000)
                  {
                        ans=ans<(N+M-1)*f[N][M][i]-i*i?ans:(N+M-1)*f[N][M][i]-i*i;
                  }
            }
            printf("Case #%d: %I64d\n",Cas,ans);
      }
      return 0;
}
/*

*/
