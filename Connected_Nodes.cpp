#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[1005];

void dfs(int src)
{
    vector<int> nodes;
    for (int child : adj_list[src])
    {
        nodes.push_back(child);
    }

    if (nodes.size() == 0)
    {
        nodes.push_back(-1);
    }

    sort(nodes.begin(), nodes.end(), greater<int>());

    for (int x : nodes)
    {
        cout << x << " ";
    }
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
        adj_list[b].push_back(a);
    }

    int q;
    cin >> q;
    while (q--)
    {
        int a;
        cin >> a;
        dfs(a);
        cout << endl;
    }

    return 0;
}