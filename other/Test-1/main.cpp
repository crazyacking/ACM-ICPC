// code 1
typedef double db;
typedef __int64 LL;
#define mod 1000000007
#define maxn 50005
LL n;
int r[maxn],a[maxn],M;
int POW(int a,LL b,int p)
{
      int ans=1;
      while(b)
      {
            if(b&1) ans=ans*a%p;
            a=a*a%p;
            b>>=1;
      }
      return ans;
}
int main()
{
      LL T;
      int ca=1,i;
      cin>>T;
      while(T--)
      {
            scanf("%I64d%d",&n,&M);
            printf("Case #%d: ",ca++);
            a[0]=2%M,a[1]=10%M;
            if(!r[M])
            {
                  for(i=2;; ++i)
                  {
                        a[i]=(10*a[i-1]%M-a[i-2]+M)%M;
                        if(a[i-1]==a[0]&&a[i]==a[1]) {r[M]=i-1; break;}
                  }
            }
            int p=(POW(2,n,r[M])+1)%r[M];
            for(i=2; i<=p; ++i) a[i]=(10*a[i-1]%M-a[i-2]+M)%M;
            printf("%d\n",(a[p]-1+M)%M);
      }
      return 0;
}

// code 2
const int maxn=47337;
bool vis[maxn];
int prim[maxn];
int a[maxn];
int judge(int m)
{
      a[0]=10%m;
      a[1]=98%m;
      for(int j=2;; j++)
      {
            a[j]=(a[j-1]*10-a[j-2]+m)%m;
            //int sign=0;
            if(a[j-1]==a[0]&&a[j]==a[1])
                  return j-1;
      }
}
int pow_mod(int x,int mod)
{
      long long ans=1,cur=2;
      while(x)
      {
            if(x&1)
                  ans=(ans*cur)%mod;
            cur=(cur*cur)%mod;
            x=(x>>1);
      }
      return ans;
}
int main()
{
      int t,ca=1;
      scanf("%d",&t);
      while(t--)
      {
            int m;
            long long x;
            scanf("%I64d%d",&x,&m);
            int cmr=judge(m);
            int cwt=pow_mod(x,cmr);
            printf("Case #%d: ",ca++);
            printf("%d\n",(a[cwt]-1+m)%m);
      }
      return 0;
}

// code 3
const int MAXN = 47000;
int x, m, r[MAXN], f[MAXN];

void init()
{
      if(r[m] != -1)
            return;
      f[0] = 2%m;
      f[1] = 10%m;
      for(int i = 2;; ++i)
      {
            f[i] = ((10*f[i-1]-f[i-2])%m+m)%m;
            if(f[i-1] == f[0] && f[i] == f[1])
            {
                  r[m] = i-1;
                  break;
            }
      }
}

//快速幂m^n
int quickPow(LL x, int n, int mm)
{
      int a = 1;
      while(n)
      {
            a *= n&1 ? x : 1;
            a %= mm;
            n >>= 1 ;
            x *= x;
            x %= mm;
      }
      return a;
}

void work()
{
      int k, ans;
      k = quickPow(2, x, r[m]);
      k = (k+1)%r[m];
      f[0] = 2%m;
      f[1] = 10%m;
      for(int i = 2; i <= k; ++i)
            f[i] = ((10*f[i-1]-f[i-2])%m+m)%m;
      ans = (f[k]-1+m)%m;
      printf("%d\n", ans);
}

int main()
{
      memset(r, -1, sizeof(r));
      int T;
      scanf("%d", &T);
      for(int times = 0; times < T; ++times)
      {
            printf("Case #%d: ", times+1);
            scanf("%d%d", &x, &m);
            init();
            work();
      }
      return 0;
}
