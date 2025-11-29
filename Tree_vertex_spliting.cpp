#include <iostream>
#include <vector>
using namespace std;

vector<vector<pair<int, int>>> Tree(8);

vector<pair<int, int>> cutEdges;

int T = 7;
int splits{};

int dfs(int u, int parent)
{
  int sum = 0;

  for (auto edge : Tree[u])
  {
    int v = edge.first;
    int w = edge.second;

    if (v == parent)
      continue;
    int childSum = dfs(v, u) + w;

    if (childSum + sum > T)
    {
      splits++;
      cutEdges.push_back({u, v});
    }
    else
    {
      sum += childSum;
    }
  }
  return sum;
}

int main()
{

  auto addEdge = [&](int u, int v, int w)
  {
    Tree[u].push_back({v, w});
    Tree[v].push_back({u, w});
  };

  addEdge(1, 2, 3);
  addEdge(1, 3, 2);
  addEdge(2, 4, 4);
  addEdge(2, 5, 1);
  addEdge(3, 6, 1);
  addEdge(3, 7, 2);
  dfs(1, 0);

  cout << "Number of cuts: " << splits << endl;

  for (auto &i : cutEdges)
  {
    cout << i.first << " " << i.second << endl;
  }
}