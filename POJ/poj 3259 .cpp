#includestdio.h
#includestdlib.h
#includemath.h
#includestring.h
const int maxn=510,inf=1000000000;;
int e,to[maxn12],next[maxn12],begin[maxn],w[maxn12];
int d[maxn],p[maxn],times[maxn],q[maxnmaxn];
int m,n,wx,f,l,flag;
void add(int x,int y,int z){
     to[++e]=y;
     next[e]=begin[x];
     begin[x]=e;
     w[e]=z;
}
void init(){
     int i,j,k,x,y,z;
     scanf(%d%d%d,&n,&m,&wx);
     e=0;
     for(i=1;i=n;i++)begin[i]=0;
     for(i=1;i=m;i++){
         scanf(%d%d%d,&x,&y,&z);
         add(x,y,z);
         add(y,x,z);
     }
     for(i=1;i=wx;i++){
         scanf(%d%d%d,&x,&y,&z);
         add(x,y,-z);
     }
     for(i=1;i=n;i++){
         d[i]=inf;
         p[i]=0;
         times[i]=0;
     }
     f=0;l=1;
     d[1]=0;q[1]=1;p[1]=1;times[1]=1;
     flag=0;
}
int main(){
    int i,j,k,t;
    scanf(%d,&t);
    while(t--){
        init();
        while(fl){
            f++;
            k=q[f];p[k]=0;
            for(i=begin[k]; i ; i=next[i])
                if(d[to[i]]d[k]+w[i]){
                    d[to[i]]=d[k]+w[i];
                    if(!p[to[i]]){
                        q[++l]=to[i];
                        p[to[i]]=1;
                        times[to[i]]++;
                        if(times[to[i]]=n){
                            flag=1;
                            break;
                        }
                    }
                }
            if(flag)break;
        }
        if(flag)
            printf(YESn);
        else
            printf(NOn);

    }
    return 0;
}
