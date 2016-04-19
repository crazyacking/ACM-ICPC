#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
    int movingCount(int threshold, int rows, int cols)
    {
    	if(rows==1 && cols ==1)
    		return 1;
    	int dx[4]={-1,0,1,0};
		int dy[4]={0,-1,0,1};
    	int res=0;
    	int vis[rows][cols];
    	memset(vis,0,sizeof vis);
    	queue<pair<int,int> > que;
    	que.push(make_pair(0,0));
    	while(!que.empty())
    	{
    		pair<int,int> cur=que.front();
    		que.pop();
    		int cx=cur.first,cy=cur.second;
    		for(int i=0;i<4;++i)
    		{
    			int nx,ny;
    			nx=cx+dx[i];
    			ny=cy+dy[i];
    			if((nx>=0 && nx<rows && ny>=0 && ny<cols)
    				&&(get_sum(nx)+get_sum(ny)<=threshold)
    				&& vis[nx][ny]==false)
    			{
    				vis[nx][ny]=true;
    				que.push(make_pair(nx,ny));
    				++res;
    			}
    		}
    	}    
    	return res;
    }
    int get_sum(int x)
    {
    	int res=0;
    	while(x)
    	{
    		res+=x%10;
    		x/=10;
    	}
    	return res;
    }
private:
};

int main(int argc, char const *argv[])
{
	int threshold,row,col;
	while(cin>>threshold>>row>>col)
	{
		Solution solution;
		int res=solution.movingCount(threshold,row,col);
		cout<<res<<endl;
	}
	return 0;
}