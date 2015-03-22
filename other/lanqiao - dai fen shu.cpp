//  Memory   Time
//  1347K     0MS
//   by : Snarl_jsb
//   2015-03-21-18.39
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<string>
#include<climits>
#include<cmath>
#define N 1000010
#define LL long long
using namespace std;

int num[9]={1,2,3,4,5,6,7,8,9},n,idx;

int ans[N];

int fun(int w1,int w2,int w3)
{
//        getchar();
//        for(int i=0;i<9;++i)
//        {
//                printf("%d ",num[i]);
//        }
//        puts("");
//
//        puts("- - - - - - - - - - - Program Run Here ! - - - - - - - - - - - - ");
//        cout<<"w1="<<w1<<" "<<"w2="<<w2<<" "<<"w3="<<w3<<endl;
        int tmp1=0;
        for(int i=0;i<w1;++i)
        {
                tmp1*=10;
                tmp1+=num[i];
        }
        int tmp2=0;
        for(int i=w1;i<w1+w2;++i)
        {
                tmp2*=10;
                tmp2+=num[i];
        }
        int tmp3=0;
        for(int i=w1+w2;i<9;++i)
        {
                tmp3*=10;
                tmp3+=num[i];
        }
//        cout<<tmp1<<" "<<tmp2<<" "<<tmp3<<endl;
        return tmp2%tmp3==0?(tmp1+tmp2/tmp3):(-1);
}

void judge()
{
        int i,j,k;
        for(i=1;i<9;++i)
        {
                for(j=1;j<9;++j)
                {
                        if(i+j>=9) continue;
                        k=9-i-j;
                        if(k<0&&k>9) continue;
                        idx=fun(i,j,k);
                        if(idx>=0&&idx<N)
                        {
                                ans[idx]++;
                        }
                }
        }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
//    freopen("C:\\Users\\ASUS\\Desktop\\cin.cpp","r",stdin);
//    freopen("C:\\Users\\ASUS\\Desktop\\cout.cpp","w",stdout);
    while(next_permutation(num,num+9))
    {
            judge();
    }
    int n;
    while(cin>>n)
    {
            cout<<ans[n]<<endl;
    }
    return 0;
}
/*

*/
