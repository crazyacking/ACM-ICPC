#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<string>
#include<cmath>
#include<stdlib.h>
#include<queue>
#include<map>
#include<iostream>
#include<time.h>
#include<set>
using namespace std;
#define ll long long
#define db double
const int maxn=100008;
int a[maxn],b[maxn];
struct fuck{
	int x,y;
	bool operator<(const fuck &a)	const
	{
		return x<a.x;
	}
}f;
set<fuck> st;
int main()
{
	int n,p,tmp1,tmp2,cnt,limit;
	long long x1,y1,x2,y2,difx,dify,dif;
	bool flag;
	double poss;
	srand(time(0));
	while(scanf("%d%d",&n,&p)!=EOF)
	{
		flag=false;
		limit=n*p;
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d",&a[i],&b[i]);
		}
		if(n==1||n==2)
		{
			printf("possible\n");
			continue;
		}
		int total=0;
		while(total<=2000)
		{
			tmp1=rand()%n+1;
			while(1)
			{
				tmp2 = rand()%n+1;
				if(tmp2!=tmp1)
				break;
			}
			f.x=tmp1;
			f.y=tmp2;
			//printf("%d %d\n",f.x,f.y);
			st.insert(f);
			total ++;
			//printf("%d\n",total);
		}
		//cout<<st.size()<<endl;
		set<fuck> :: iterator iter;
		for(iter=st.begin();iter!=st.end();iter++)
		{
			cnt=0;
			x1=a[iter->x];
			x2=a[iter->y];
			y1=b[iter->x];
			y2=b[iter->y];
			difx=x1-x2;
			dify=y1-y2;
			dif=y2*x1-y1*x2;
			for(int j=1;j<=n;j++)
				if((b[j]*difx)==(dify*a[j]+dif))	cnt++;
			if(100*cnt>=limit)
			{
				flag=true;
				break;
			}
		}
		if(flag)	printf("possible\n");
		else	printf("impossible\n");
	}
	return 0;
}
