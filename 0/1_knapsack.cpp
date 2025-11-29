#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, W;
  cin >> n >> W;

  vector<int> weight(n), value(n);

  for (int i = 0; i < n; i++)
  {
    cin >> weight[i] >> value[i];
  }

  // DP table: dp[i][w] = max profit using first i items with capacity w
  vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

  for (int i = 1; i <= n; i++)
  {
    for (int w = 0; w <= W; w++)
    {

      if (weight[i - 1] <= w)
      {
        dp[i][w] = max(
            value[i - 1] + dp[i - 1][w - weight[i - 1]],
            dp[i - 1][w] 
        );
      }
      else
      {
        dp[i][w] = dp[i - 1][w];
      }
    }
  }

  cout << dp[n][W] << endl;
  return 0;
}
