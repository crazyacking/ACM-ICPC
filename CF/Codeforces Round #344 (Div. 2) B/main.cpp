#include<bits/stdc++.h>
using namespace std;

#define sd(mark) scanf("%d",&mark)
#define ss(mark) scanf("%s",&mark)
#define sl(mark) scanf("%lld",&mark)
#define debug(mark) printf("check%d\n",mark)
#define clr(mark) memset(mark,0,sizeof(mark))
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define ll long long
int cr[5010]= {0},tr[5010],cc[5010]= {0},tc[5010];
int main()
{
    int n,m,k,i,j,ch,x,c;
    sd(n);
    sd(m);
    sd(k);
    for(i=0; i<5010; ++i)
        tr[i]=tc[i]=-1;
    for(i=0; i<k; ++i)
    {
        sd(ch);
        sd(x);
        sd(c);
        --x;
        if(ch==1)
        {
            cr[x]=c;
            tr[x]=i;
        }
        else
        {
            cc[x]=c;
            tc[x]=i;
        }
    }
    for(i=0; i<n; ++i)
    {
        for(j=0; j<m; ++j)
        {
            if(tr[i]>tc[j])
                printf("%d ",cr[i]);
            else
                printf("%d ",cc[j]);
        }
        printf("\n");
    }
}
