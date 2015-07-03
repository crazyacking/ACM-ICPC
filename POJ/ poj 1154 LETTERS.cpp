#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
using namespace std;
int visit[30];
int n,m;
int step[8] = {1,0,-1,0,0,1,0,-1};
int num[100][100],cou = 1,mmax = 0;;
void DFS(int i, int j)
{
	for( int k=0; k<8; k+=2)
	{
		int a = i+step[k];
		int b = j+step[k+1];
		if( a>=1 && a<=n && b>=1 && b<=m && !visit[num[a][b]] )
		{
			visit[num[a][b]] = 1;
			cou++;
			DFS(a,b);
			if( cou > mmax )
			    mmax = cou;
			cou--;
			visit[num[a][b]] = 0;
		}
	}
}
int main(void)
{
	char str[100];
	while( cin >> n >> m )
	{
		getchar();
		memset(visit,0,sizeof(visit));
		cou = 1; mmax = 1;
		for(int i=1; i<=n; i++)
		{
      		gets(str);
			for(int k=0; k<m; k++)
			    num[i][k+1] = str[k] -'A' + 1;
		}
		visit[num[1][1]] = 1;
		DFS(1,1);
		cout << mmax << endl;
	}
return 0;
}
