#include <bits/stdc++.h>
using namespace std;


class Flip
{
public:
    vector<vector<int> > flipChess(vector<vector<int> > A, vector<vector<int> > f)
    {
        int dx[]={0,0,1,-1};
        int dy[]={-1,1,0,0};
        int si=f.size();
        for(int i=0;i<si;++i)
        {
            for(int j=0;j<4;++j)
            {
                int x=f[i][0]+dx[j]-1;
                int y=f[i][1]+dy[j]-1;
//                cout<<"x="<<x<<" "<<"y="<<y<<endl;
                if(x>=0 && x<4 && y>=0 && y<4)
                    A[x][y]=(A[x][y]==0?1:0);
            }
        }
        vector<vector<int> > ret(A);
        for(int i=0;i<4;++i)
        {
            for(int j=0;j<4;++j)
            {
                cout<<ret[i][j]<<" ";
            }
            cout<<endl;
        }
        return ret;
    }
};

int main()
{
//    freopen("G:\\nowcoder\\1.in","r",stdin);
//    freopen("G:\\nowcoder\\1.out","w",stdout);
    int n;
    {
        Flip solution;
        vector<vector<int> > A(4);
        for(int i=0;i<4;++i)
        {
            for(int j=0;j<4;++j)
            {
                A[i].push_back(1);
            }
        }
        vector<vector<int> > f(1);
        f[0].push_back(1);
        f[0].push_back(1);
        cout<<f[0][0]<<endl;
        cout<<f[0][1]<<endl;

        solution.flipChess(A,f);
    }
    return 0;
}
/*

*/
