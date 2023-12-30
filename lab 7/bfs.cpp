#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

void Bfs(vector<vector<int>> &list, vector<int> &d, vector<int> &p, vector<int> &c, int s)
{
    int infinity = INT_MAX;

    for (int u = 0; u < list.size(); u++)
    {
        d[u] = infinity;
        p[u] = -1;
        c[u] = 0;
    }
    c[s] = 1;
    d[s] = 0;
    p[s] = -1;
    queue<int> q;
    q.push(s);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : list[u])
        {
            if (c[v] == 0)
            {
                c[v] = 1;
                d[v] = d[u] + 1;
                p[v] = u;
                q.push(v);
            }
        }
        c[u] = 2;
    }
}

void print_path(vector<vector<int>> &list, int s, int v, vector<int> &d, vector<int> &p, vector<int> &c)
{
    if (s == v)
    {
        cout << "path = " << s << " ";
    }
    else if (p[v] == -1)
    {
        cout << "no path";
    }
    else
    {
        print_path(list, s, p[v], d, p, c);
        cout << v << " ";
    }
}

int main()
{
    vector<vector<int>> adj_list = {{1, 2}, {0, 2}, {0, 1, 3}, {2}};
    int start_node = 0;
    int end_node = 2;
    int inf = INT_MAX;
    int n = adj_list.size();
    vector<int> distance(n, inf);
    vector<int> prev(n, -1);
    vector<int> color(n, 0);
    Bfs(adj_list, distance, prev, color, start_node);
    print_path(adj_list, 0, end_node, distance, prev, color);
    cout << "cost: " << distance[end_node] << endl;
}