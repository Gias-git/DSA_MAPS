#include <bits/stdc++.h>
using namespace std;
bool vis[105];
vector<int> adj_list[105];
bool Path_vis[105];
bool cycle;

void dfs(int src)
{
    vis[src] = true;
    Path_vis[src] = true;
    for (int child : adj_list[src])
    {
        if (vis[child] && Path_vis[child])
        {
            cycle = true;
        }
        if (!vis[child])
        {
            dfs(child);
        }
    }

    Path_vis[src] = false;
}

int main()
{

    int n, e;
    cin >> n >> e;

    while (e--)
    {
        int a, b;
        cin >> a >> b;

        adj_list[a].push_back(b);
    }

    memset(vis, false, sizeof(vis));
    memset(Path_vis, false, sizeof(Path_vis));
    cycle = false;

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dfs(i);
        }
    }

    if (cycle)
    {
        cout << "CYCLE DETECTED" << endl;
    }
    else
    {
        cout << "CYCLE NOT DETECTED" << endl;
    }

    return 0;
}