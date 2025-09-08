#include <bits/stdc++.h>
using namespace std;
char grid[1000][1000];
bool vis[1000][1000];
int n, m;
vector<pair<int, int>> d = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;

    return true;
}

int dfs(int si, int sj)
{

    vis[si][sj] = true;
    int cnt = 1;

    for (int i = 0; i < 4; i++)
    {
        int ci = si + d[i].first;
        int cj = sj + d[i].second;
        if (valid(ci, cj) == true && !vis[ci][cj] && grid[ci][cj] == '.')
            cnt += dfs(ci, cj);
    }
    return cnt;
}

int main()
{

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }
    memset(vis, false, sizeof(vis));

    vector<int> apartments;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            if (vis[i][j] == false && grid[i][j] == '.')
            {
                int room = dfs(i, j);
                apartments.push_back(room);
            }
        }
    }

    if (apartments.empty())
    {
        cout << 0 << endl;
    }
    else
    {
        sort(apartments.begin(), apartments.end());

        for (int x : apartments)
        {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}