#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
const double eps=1e-8;
const double pi=acos(-1.0);
int sgn(double x)
{
      if(fabs(x)<eps)return 0;
      if(x<0)return -1;
      return 1;
}
struct point
{
      double x,y;
      point(){}
      point(double x,double y)
      {
            this->x=x;
            this->y=y;
      }
      point operator -(point a)
      {
            return point(x-a.x,y-a.y);
      }
      point operator +(point a)
      {
            return point(x+a.x,y+a.y);
      }
      double operator /(point a)
      {
            return x*a.y-y*a.x;
      }
      double operator *(point a)
      {
            return x*a.x+y*a.y;
      }
};
struct line
{
      point s,e;
      line(){}
      line(point s,point e)
      {
            this->s=s;
            this->e=e;
      }
      point operator*(line a)
      {
            point res=s;
            double t=((s-a.s)/(a.s-a.e))/((s-e)/(a.s-a.e));
            res.x+=(e.x-s.x)*t;
            res.y+=(e.y-s.y)*t;
            return res;
      }
};
point pointtoline(point p,line l)
{
      point res;
      double t=((p-l.s)*(l.e-l.s))/((l.e-l.s)*(l.e-l.s));
      res.x=l.s.x+(l.e.x-l.s.x)*t;
      res.y=l.s.y+(l.e.y-l.s.y)*t;
      return res;
}
point work(point p,line l)
{
      point o=pointtoline(p,l);
      p=p-o;
      p.x=-p.x;p.y=-p.y;
      p=p+o;
      return p;
}
char s[110];
bool vis[110];
bool isok(int l,int r)
{
      for(int i=l;i<=r;i++)
            if(!vis[i]&&s[i]=='@')
            {
                  vis[i]=1;
                  return 1;
            }
      return 0;
}
char ss[110];
point cg(int l,int r)
{
      for(int i=0;l+i<=r;i++)
            ss[i]=s[i+l];
      ss[r-l+1]='\0';
      point res;
      sscanf(ss,"%lf,%lf",&res.x,&res.y);
      return res;
}
struct Bx
{
      bool flag;
      line l;
      Bx(){}
      Bx(bool flag,point p)
      {
            this->flag=flag;
            l.s=p;
      }
      Bx(bool flag,line l)
      {
            this->flag=flag;
            this->l=l;
      }
}bx[110];
int sk[110];
int tail,len;
int main()
{
      while(scanf("%s",s)!=EOF)
      {
            if(s[0]=='#')
                  return 0;
            len=tail=0;
            int n=strlen(s);
            memset(vis,0,sizeof(vis));
            for(int i=0;i<n;i++)
            {
                  if(s[i]=='(')
                        sk[len++]=i;
                  else if(s[i]==')')
                  {
                        int t=sk[--len];
                        if(s[i-1]!='('&&s[i-1]!=')')
                              bx[tail++]=Bx(0,cg(t+1,i-1));
                        else
                        {
                              if(isok(t+1,i-1))
                              {
                                    Bx la=bx[--tail],lb=bx[--tail];
                                    if(la.flag==0)
                                    {
                                          if(lb.flag==0)
                                                bx[tail++]=Bx(1,line(la.l.s,lb.l.s));
                                          else
                                                bx[tail++]=Bx(0,work(la.l.s,lb.l));
                                    }
                                    else
                                    {
                                          if(lb.flag==0)
                                                bx[tail++]=Bx(0,work(lb.l.s,la.l));
                                          else
                                                bx[tail++]=Bx(0,la.l*lb.l);
                                    }
                              }
                        }
                  }
            }
            Bx ans=bx[0];
            for(int i=1;i<tail;i++)
            {
                  if(ans.flag==0)
                  {
                        if(bx[i].flag==0)
                              ans=Bx(1,line(ans.l.s,bx[i].l.s));
                        else
                              ans=Bx(0,work(ans.l.s,bx[i].l));
                  }
                  else
                  {
                        if(bx[i].flag==0)
                              ans=Bx(0,work(bx[i].l.s,ans.l));
                        else
                              ans=Bx(0,ans.l*bx[i].l);
                  }
            }
            printf("%.7f %.7f\n",ans.l.s.x,ans.l.s.y);
      }
}
