#include <bits/stdc++.h>
using namespace std;

string str[2000];
int moveX[4] = {0, 0, 1, -1};
int moveY[4] = {1, -1, 0, 0};
bool visited[2000][2000] = {0};
int value[2000][2000] = {0};
int m, n, finalex = -1, finaley = -1;

void bfs(int sx, int sy)
{
    queue<pair<int, int>> q;
    q.push(make_pair(sx, sy));
    visited[sx][sy] = true;
    value[sx][sy] = 1;
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
            if (str[u][v] != '#' && !visited[u][v])
            {
                if (str[u][v] == 'B')
                    finalex = u, finaley = v;
                visited[u][v] = true;
                q.push(make_pair(u, v));
                if (value[u][v] != 0)
                    value[u][v] = min(value[u][v], value[x][y] + 1);
                else
                    value[u][v] = value[x][y] + 1;
            }
        }
    }
}

void trace(int sx, int sy)
{
    stack<pair<int, int>> q;
    stack<char> st;
    q.push(make_pair(sx, sy));
    while (!q.empty())
    {
        int x = q.top().first;
        int y = q.top().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int u = x + moveX[i];
            int v = y + moveY[i];
            if (u >= n || u < 0 || v >= m || v < 0)
                continue;
            if (value[x][y] - value[u][v] == 1 && value[u][v] != 0)
            {
                q.push(make_pair(u, v));
                if (i == 0)
                    st.push('L');
                else if (i == 1)
                    st.push('R');
                else if (i == 2)
                    st.push('U');
                else if (i == 3)
                    st.push('D');
                break;
            }
        }
    }
    cout << "YES" << endl;
    cout << value[finalex][finaley] - 1 << endl;
    while (!st.empty())
    {
        cout << st.top();
        st.pop();
    }
    return;
}

int main()
{
    cin >> n >> m;
    for (int x = 0; x < n; x++)
        cin >> str[x];
    for (int x = 0; x < n; x++)
        for (int y = 0; y < m; y++)
            if (str[x][y] == 'A')
                bfs(x, y);

    if (finalex != -1 && finaley != -1)
    {
        trace(finalex, finaley);
    }
    else
        cout << "NO";
}