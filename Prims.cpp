#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> graph[100005];
bool visited[100005];

int main()
{
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < m; i++)
  {
    int u, v, w;
    cin >> u >> v >> w;
    graph[u].push_back({v, w});
    graph[v].push_back({u, w});
  }

  priority_queue<pair<int, int>,
                 vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;

  pq.push({0, 1}); // cost, node
  int mst_cost = 0;

  while (!pq.empty())
  {
    auto [w, u] = pq.top();
    pq.pop();

    if (visited[u])
      continue;
    visited[u] = true;
    mst_cost += w;

    for (auto [v, cost] : graph[u])
    {
      if (!visited[v])
      {
        pq.push({cost, v});
      }
    }
  }

  cout << "MST Cost = " << mst_cost << endl;
}
