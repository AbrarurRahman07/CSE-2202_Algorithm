#include <bits/stdc++.h>
using namespace std;
#define V 4
#define INF INT_MAX

int dp[1 << V][V];

int graph[V][V] = {
    {0, 10, 15, 20},
    {10, 0, 35, 25},
    {15, 35, 0, 30},
    {20, 25, 30, 0}};

int tsp_held_karp()
{
  int num_masks = 1 << V;

  for (int mask = 0; mask < num_masks; ++mask)
  {
    for (int j = 0; j < V; ++j)
    {
      dp[mask][j] = INF;
    }
  }
  dp[1][0] = 0;


  for (int mask = 1; mask < num_masks; ++mask)
  {

    for (int j = 0; j < V; ++j)
    {

      if (!(mask & (1 << j)))
        continue;
      if (dp[mask][j] == INF)
        continue;
      for (int k = 0; k < V; ++k)
      {
        if (mask & (1 << k))
          continue;
        if (graph[j][k] == 0 && j != k)
          continue;
        int new_mask = mask | (1 << k);
        int new_cost = dp[mask][j] + graph[j][k];
        dp[new_mask][k] = min(dp[new_mask][k], new_cost);
      }
    }
  }
  int final_mask = (1 << V) - 1;
  int min_cost = INF;
  for (int j = 1; j < V; ++j)
  {
    if (graph[j][0] != 0 && dp[final_mask][j] != INF)
    {
      min_cost = min(min_cost, dp[final_mask][j] + graph[j][0]);
    }
  }

  return min_cost;
}

int main()
{
  cout << "The minimum cost for the Traveling Salesman Tour (DP) is: "
       << tsp_held_karp() << endl;

  return 0;
}