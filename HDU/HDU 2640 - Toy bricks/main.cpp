#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	
	return 0;
}

/* - TLE code - */
.



/* - error code - */
// #include <bits/stdc++.h>
// using namespace std;

// const int MAXN=100,MAXM=100;

// char mat[MAXN][MAXM];

// bool check(int row,int col,int x,int y)
// {
// 	if(!((x+2<row) && (y-1>=0) && (y+1<col)))
// 		return false;
// 	if(!(mat[x+1][y]=='.' && mat[x+2][y]=='.' && mat[x][y-1]=='.' && mat[x][y]=='.' && mat[x][y+1]=='.'))
// 		return false;
// 	return true;
// }
// int main(int argc, char const *argv[])
// {
// 	int T;
// 	cin>>T;
// 	while(T--)
// 	{
// 		int row,col;
// 		cin>>row,col;
// 		for(int i=0;i<row;++i)
// 			cin>>mat[i];
// 		int ans=0;
// 		for(int i=0;i<row;++i)
// 		{
// 			for(int j=0;j<col;++j)
// 			{
// 				if(mat[i][j]=='.')
// 				{
// 					if(check(row,col,i,j))
// 						++ans;
// 				}
// 			}
// 		}
// 		cout<<ans<<endl;
// 	}
// 	return 0;
// }