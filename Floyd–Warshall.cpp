#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int distanc[105][105]; // distance matrix
int parent[105][105];  // parent matrix for path printing

int main()
{
  int n, e;
  cin >> n >> e;

  // Initialize
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      if (i == j)
        distanc[i][j] = 0;
      else
        distanc[i][j] = INF;

      parent[i][j] = -1;
    }
  }

  // Input edges
  for (int i = 0; i < e; i++)
  {
    int a, b, w;
    cin >> a >> b >> w;
    distanc[a][b] = w;
    parent[a][b] = a; // parent for path reconstruction
  }

  // Floyd–Warshall core
  for (int k = 1; k <= n; k++)
  {
    for (int i = 1; i <= n; i++)
    {
      for (int j = 1; j <= n; j++)
      {
        if (distanc[i][k] + distanc[k][j] < distanc[i][j])
        {
          distanc[i][j] = distanc[i][k] + distanc[k][j];
          parent[i][j] = parent[k][j];
        }
      }
    }
  }

  // Check negative cycle
  for (int i = 1; i <= n; i++)
  {
    if (distanc[i][i] < 0)
    {
      cout << "Negative cycle detected!" << endl;
      return 0;
    }
  }

  // Print all-pair shortest distance
  cout << "\nAll-Pairs Shortest Distance Matrix:\n";
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      if (distanc[i][j] == INF)
        cout << "INF ";
      else
        cout << distanc[i][j] << " ";
    }
    cout << endl;
  }

  // Path query
  int s, d;
  cout << "\nEnter source and destination: ";
  cin >> s >> d;

  if (distanc[s][d] == INF)
  {
    cout << "No path exists!" << endl;
    return 0;
  }

  cout << "Shortest distance from " << s << " to " << d << " is: "
       << distanc[s][d] << endl;

  // Path printing
  vector<int> path;
  int end = d;

  while (end != s)
  {
    path.push_back(end);
    end = parent[s][end];
    if (end == -1)
      break;
  }
  path.push_back(s);

  reverse(path.begin(), path.end());

  cout << "Path: ";
  for (int x : path)
    cout << x << " ";
  cout << endl;

  return 0;
}
