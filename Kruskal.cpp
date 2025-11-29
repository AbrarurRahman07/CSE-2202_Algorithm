#include <bits/stdc++.h>
using namespace std;

struct Edge
{
  int u, v, w;
  bool operator<(const Edge &other) const
  {
    return w < other.w;
  }
};

int parent[100005];
int findParent(int x)
{
  if (parent[x] == x)
    return x;
  return parent[x] = findParent(parent[x]);
}

bool unite(int a, int b)
{
  a = findParent(a);
  b = findParent(b);
  if (a == b)
    return false;
  parent[b] = a;
  return true;
}

int main()
{
  int n, m;
  cin >> n >> m;

  vector<Edge> edges;
  for (int i = 1; i <= n; i++)
    parent[i] = i;

  for (int i = 0; i < m; i++)
  {
    int u, v, w;
    cin >> u >> v >> w;
    edges.push_back({u, v, w});
  }

  sort(edges.begin(), edges.end());

  int mst_cost = 0, edge_count = 0;

  for (auto &e : edges)
  {
    if (unite(e.u, e.v))
    {
      mst_cost += e.w;
      edge_count++;
      if (edge_count == n - 1)
        break;
    }
  }

  cout << "MST Cost = " << mst_cost << endl;
}
