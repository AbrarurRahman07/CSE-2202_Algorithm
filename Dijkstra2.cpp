#include <bits/stdc++.h>
using namespace std;

vector<int> graph[10000];
vector<int> cost[10000];

int distanc[10000];
int parent[10000];

struct node
{
public:
  int u, w;
  node(int a, int b) : u(a), w(b) {}

  bool operator<(const node &p) const
  {
    return w > p.w;
  }
};

void dijkstra(int s)
{
  for (int i = 0; i < 10000; i++)
  {
    distanc[i] = 9999999;
    parent[i] = -1;
  }
  priority_queue<node> pq;
  pq.push(node(s, 0));
  distanc[s] = 0;
  while (!pq.empty())
  {
    node top = pq.top();
    pq.pop();
    int u = top.u;
    if (top.w != distanc[u]) continue;
    for (int i = 0; i < graph[u].size(); i++)
    {
      int v = graph[u][i];
      if (distanc[u] + cost[u][i] < distanc[v])
      {
        distanc[v] = distanc[u] + cost[u][i];
        pq.push(node(v, distanc[v]));
        parent[v] = u;
      }
    }
  }
}

int main()
{
  int n, e, a, b, w, s, des;
  int res;
  cin >> n >> e;
  for (int i = 0; i < e; i++)
  {
    cin >> a >> b >> w;
    graph[a].push_back(b);
    cost[a].push_back(w);

    graph[b].push_back(a);
    cost[b].push_back(w);
  }
  cin >> s;
  dijkstra(s);
  for (int i = 1; i <= n; i++)
  {
    cout << i << " = " << distanc[i] << endl;
  }

  cout << "Enter till what you want to get destination" << endl;
  cin >> des;
  cout << "From " << s << " to " << des << " total destination is : " << distanc[des] << endl;

  /// path printing

  if (distanc[des] == -1)
  {
    cout << "NO WAY" << endl;
  }
  else
  {
    vector<int> path;
    int p =des;
    while (p != -1)
    {
      path.push_back(p);
      p = parent[p];
    }
    reverse(path.begin(), path.end());

    cout << "Shortest path is:" << endl;
    for (int i = 0; i < path.size(); i++)
    {
      cout << path[i] << " ";
    }
    cout << endl;
  }

  return 0;
}
/*
  6 8
  1 3 9
  1 6 14
  1 2 7
  2 4 15
  3 4 11
  3 6 2
  6 5 9
  5 4 6
  1



*/