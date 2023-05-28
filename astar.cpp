#include <bits/stdc++.h>
using namespace std;
void solve(int h_val[], vector<vector<pair<int, int>>> &graph, int src, int goal)
{
    priority_queue<pair<int, int>> q;
    q.push({h_val[0], 0});
    int dist[goal + 1] ;
    for (int i = 0; i <= goal; i++)
    {
        dist[i] = 99;
    }
    dist[0] = h_val[0];
    int par[goal + 1] = {0};
    while (!q.empty())
    {
        int dist1 = q.top().first;
        int ver = q.top().second;
        int rada = dist1 - h_val[ver];
        q.pop();
        for (auto x : graph[ver])
        {
            if (dist[x.first] > (rada + h_val[x.first] + x.second))
            {
                par[x.first] = ver;
                q.push({rada + h_val[x.first] + x.second, x.first});
                dist[x.first] = rada + h_val[x.first] + x.second; 
            }
        }
    }
    int i = 0;
    for (auto x : dist)
    {
        cout << x << " ";
        i++;
    }
    cout << endl;
    cout << "Optimal path from source to goal is : ";
    vector<int> ans;
    ans.push_back(goal);
    while (goal != 0)
    {
        ans.push_back(par[goal]);
        goal = par[goal];
    }
    reverse(ans.begin(), ans.end());
    for (auto x : ans)
    {
        cout << x << " ";
    }
}
int main()
{
    cout << "Enter th number of vertices and edges : ";
    int vertex, edges;
    cin >> vertex >> edges;
    vector<vector<pair<int, int>>> graph;
    cout << "Enter the source vertex : ";
    int src;
    cin >> src;
   // int include[vertex] = {0};
   // int weight[vertex];
    vector<pair<int, int>> v;
    for (int i = 0; i < vertex; i++)
    {
        graph.push_back(v);
    }
    //weight[src] = 0;
    for (int i = 0; i < edges; i++)
    {
        cout << "Enter two vertices and weight of edge : ";
        int x, y;
        cin >> x >> y;
        int weight;
        cin >> weight;
        graph[x].push_back({y, weight});
        graph[y].push_back({x, weight});
    }
    int h_val[vertex];
    for (int i = 0; i < vertex; i++)
    {
        cout << "Enter the h value of " << i << " th vertex" << endl;
        cin >> h_val[i];
    }
    solve(h_val, graph, 0, vertex - 1);
    return 0;
}