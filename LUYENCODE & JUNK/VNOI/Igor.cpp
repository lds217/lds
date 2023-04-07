#include <bits/stdc++.h>
#include <fstream>
using namespace std;

int n,m,q;
string a[1000];
int moveX[4] = {0, 0, 1, -1};
int moveY[4] = {1, -1, 0, 0};
int value[10000][10000];
bool visited[5000][5000],visited2[5000][5000];


pair<int,int> bfs(int sx, int sy)
{

    int pictures = 0;
    queue<pair<int, int>> q;
    q.push(make_pair(sx, sy));
    visited[sx][sy] = true; int x,y;
    while (!q.empty())
    {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int u = x + moveX[i];
            int v = y + moveY[i];
            if (u >= n || u < 0 || v >= m || v < 0)
                continue;
             if(a[u][v]=='*')
             {
                 pictures++;
             }
            if (a[u][v]=='.' && !visited[u][v])
            {
                visited[u][v] = true;
                q.push(make_pair(u, v));
            }
        }
    }
    value[x][y]=pictures;
    return pair<int,int>(x,y);
}

void bfs2(int sx, int sy)
{
    queue<pair<int, int>> q;
    q.push(make_pair(sx, sy));
    visited2[sx][sy] = true; int u,v;
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int u = x + moveX[i];
            int v = y + moveY[i];
            if (u >= n || u < 0 || v >= m || v < 0)
                continue;
            if (a[u][v]=='.' && !visited2[u][v])
            {
                visited2[u][v] = true;
                value[u][v]=value[x][y];
                q.push(make_pair(u, v));
            }
        }
    }
}



int main()
{
    cin>>n>>m>>q;
    for(int x=0;x<n;x++)
        cin>> a[x];
    for(int i=0;i<n;i++)
        for(int j=0;j<=m;j++)
            if(a[i][j]=='.'&&visited[i][j]==0)
            {
                pair<int,int> f=bfs(i,j);
                int u=f.first,v=f.second;
               bfs2(u,v);
            }
    int u,v;
    while(q--)
    {
        cin>>u>>v;
        cout<<value[u-1][v-1]<<endl;
    }
    
}