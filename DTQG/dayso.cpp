#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define X first
#define Y second

int bx,by,fx,fy,value[100][100];
int n,m;
int <pair<int,int>> path[101][101];
bool visit[101][101];
int moveX[4]={-1,1,1,-1};
int moveY[4]={-1,-1,1,1};

void bfs(int sx, int sy)
{
    queue < pair <int,int> > q;
    q.push({sx,sy});
    value[sx][sy]=0;
    while(!q.empty())
    {
        int x=q.front().X;
        int y=q.front().Y;
        q.pop();
        for(int i=0;i<4;i++)
        {
            int u=x+moveX[i];
            int v=y+moveY[i];
            if(u<=0||u>n||v<=0||v>n)	continue;
            if(value[u][v]>value[x][y]+1&&visit[u][v]!=0)
            {
                value[u][v]=value[x][y]+1;
                q.push({u,v});
            }
        }
    }
}

int main()
{
   	cin>>n>>m>>bx>>by>>fx>>fy;
    while(m--)
    {
        int u,v;
        cin>>u>>v;
        visit[u][v]=1;
    }
   		bfs(bx,by);
 
   	cout<<value[fx][fy];
}