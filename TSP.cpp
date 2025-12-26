#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main()
{
  int n;
  cin >> n;

  vector<vector<int>> cost(n, vector<int>(n));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> cost[i][j];

  int N = 1 << n; // Total subset combinations
  vector<vector<int>> dp(N, vector<int>(n, INF));

  dp[1][0] = 0; // Starting from city 0

  for (int mask = 1; mask < N; mask++)
  {
    for (int j = 0; j < n; j++)
    {
      if (mask & (1 << j))
      {
        for (int i = 0; i < n; i++)
        {
          if (i != j && (mask & (1 << i)))
          {
            int prev_mask = mask ^ (1 << j);
            dp[mask][j] = min(dp[mask][j],
                              dp[prev_mask][i] + cost[i][j]);
          }
        }
      }
    }
  }

  // Final answer: end at any city and return to 0
  int ans = INF;
  for (int i = 1; i < n; i++)
    ans = min(ans, dp[N - 1][i] + cost[i][0]);

  cout << "Minimum TSP Cost = " << ans << endl;
  return 0;
}
