#include <bits/stdc++.h>
using namespace std;

vector<int> graph[100005];
vector<int> cost[100005];

int distanc[100005];
int parent[100005];

const int INF = 1e9;

void bellmanFord(int n, int s)
{
  for (int i = 0; i <= n; i++)
  {
    distanc[i] = INF;
    parent[i] = -1;
  }

  distanc[s] = 0;

  // Relax edges (n - 1) times
  for (int k = 1; k <= n - 1; k++)
  {
    for (int u = 1; u <= n; u++)
    {
      for (int i = 0; i < graph[u].size(); i++)
      {
        int v = graph[u][i];
        int w = cost[u][i];

        if (distanc[u] != INF && distanc[u] + w < distanc[v])
        {
          distanc[v] = distanc[u] + w;
          parent[v] = u;
        }
      }
    }
  }

  // Check negative cycle
  for (int u = 1; u <= n; u++)
  {
    for (int i = 0; i < graph[u].size(); i++)
    {
      int v = graph[u][i];
      int w = cost[u][i];

      if (distanc[u] != INF && distanc[u] + w < distanc[v])
      {
        cout << "Negative cycle detected!" << endl;
        return;
      }
    }
  }
}

int main()
{
  int n, e;
  cin >> n >> e;

  for (int i = 0; i < e; i++)
  {
    int a, b, w;
    cin >> a >> b >> w;

    graph[a].push_back(b);
    cost[a].push_back(w);
  }

  int s;
  cin >> s;

  bellmanFord(n, s);

  cout << "\nDistance from " << s << " to all nodes:\n";
  for (int i = 1; i <= n; i++)
  {
    cout << i << " = " << distanc[i] << endl;
  }

  cout << "\nEnter destination: ";
  int des;
  cin >> des;

  if (distanc[des] == INF)
  {
    cout << "No path exists!" << endl;
    return 0;
  }

  cout << "Shortest distance from " << s << " to " << des << " is: "
       << distanc[des] << endl;

  // Print path
  vector<int> path;
  int p = des;

  while (p != -1)
  {
    path.push_back(p);
    p = parent[p];
  }

  reverse(path.begin(), path.end());

  cout << "Path: ";
  for (int x : path)
    cout << x << " ";
  cout << endl;

  return 0;
}
