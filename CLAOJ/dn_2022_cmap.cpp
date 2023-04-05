#include <bits/stdc++.h>
using namespace std;

int m,n,a[1000][1000],visited[1000][1000];
int res[1000][1000];
int moveX[]={1,-1,0,0};
int moveY[]={0,0,-1,1};
int diff=0;
int c;
int final=0;

void bfs(int sx,int sy)
{
    int dup[10001];
    for(int i=0;i<=c;i++)
    	dup[i]=0;
    diff=0;
    queue <pair<int,int> > q;
    q.push({sx,sy});
    visited[sx][sy]=1;
    while(!q.empty())
    {
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        for(int i=0;i<4;i++)
        {
            int u= x + moveX[i];
            int v = y + moveY[i];
            if (u >= m || u < 0 || v >= n || v < 0)
                continue;
           	if(a[u][v]==a[sx][sy]&&visited[u][v]==0)
            {
                if(sx==0&&sy==0)
                    res[u][v]=1;
                visited[u][v]=1;
                q.push({u,v});
            }
            else
            {
                if(a[u][v]!=a[sx][sy])
                	if(sx!=0||sy!=0)
	                    if(dup[res[u][v]]==0)
	                       dup[res[u][v]]=1; 			  
            }
        }
    }
    for(int i=1;i<=c;i++)
    {
        if(dup[i]==0)
        {
            diff=i;
            break;
    	}
    }
}

void tomau(int sx,int sy)
{
    queue <pair<int,int> > q;
    q.push({sx,sy});
    res[sx][sy]=diff;
    final=max(final,diff);
    while(!q.empty())
    {
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        for(int i=0;i<4;i++)
        {
            int u= x + moveX[i];
            int v = y + moveY[i];
            if (u >= m || u < 0 || v >= n || v < 0)
                continue;
            if(a[u][v]==a[sx][sy]&&res[u][v]==0)
            {
                res[u][v]=diff;
                q.push({u,v});
            }
        }
    }
}

int main()
{
    
    cin>>m>>n>>c;
    for(int x=0;x<m;x++)
        for(int y=0;y<n;y++)
            cin>>a[x][y],res[x][y]=0;
	res[0][0]=1;
    for(int x=0;x<m;x++)
        for(int y=0;y<n;y++)
        {
            if(visited[x][y]==0)
            {
            	bfs(x,y);
              	 if(x!=0||y!=0)
                    tomau(x,y);
            }
      
        }
    cout<<final<<endl;
    for(int x=0;x<m;x++)
    {
        for(int y=0;y<n;y++)
            if(res[x][y]==0)
                cout<<4<<' ';
            else
           	    cout<<res[x][y]<<' ';
    }
	return 0;
}
