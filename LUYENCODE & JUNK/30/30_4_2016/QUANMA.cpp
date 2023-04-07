#include <bits/stdc++.h>
#include <fstream>
using namespace std;

const int MAXINT=1001;
bool visited [MAXINT][MAXINT]={0};
int mark[MAXINT][MAXINT]={0};
int moveX[] = { 2, 2, -2, -2, 1, 1, -1, -1 };
int moveY[] = { -1, 1, 1, -1, 2, -2, 2, -2 };
int xf,yf,n,m;

int bfs(int sx, int sy)
{
    queue<pair<int, int>> q;
    q.push(make_pair(sx, sy));
    visited[sx][sy] = true;
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 8; i++)
        {
            int u = x + moveX[i];
            int v = y + moveY[i];
            cout<<u<<" "<<v<<endl;
            if (u > n || u < 1 ||v > m || v < 1)
                continue;
            if (!visited[u][v])
            {
                visited[u][v] = true;
                if(mark[u][v]!=0)
                    mark[u][v]=min(mark[u][v],mark[x][y]+1);
                else
                    mark[u][v]=mark[x][y]+1;
                q.push(make_pair(u, v));
            }
        }
         for(int x=1;x<=n;x++){
        for (int y=1;y<=m;y++)
            cout<<mark[x][y]<<" ";
            cout<<endl;
    }
    }
   // if(mark[xf][yf])
    return mark[xf][yf];
}

int main()
{
    int xo,yo;
    ifstream f;
    f.open("QUANMA.INP");
    cin>>n>>m;
    cin>>xo>>yo>>xf>>yf;
    f.close();
    ofstream f1;
    f1.open("QUANMA.OUT");
    cout<<bfs(xo,yo)<<endl;
   
}