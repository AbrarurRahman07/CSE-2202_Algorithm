#include <bits/stdc++.h>
using namespace std;

int n = 4;
vector<vector<int>> dist(n);
vector<vector<int>> dp((1<<n),vector<int>(n,-1));

int tsp(int mask, int pos)
{

    if (mask == (1 << n) - 1)
        return dist[pos][0];

        if(dp[mask][pos] != -1) 
        return dp[mask][pos];

    int ans = INT_MAX;
    
    for (int city = 0; city < n; city++)
    {
        if ((mask & (1 << city)) == 0)
        {
            ans = min(ans, dist[pos][city] + tsp((mask | (1 << city)), city));
        }
    }
    return dp[mask][pos] = ans;
}

int main()
{
    dist = {{0, 10, 15, 20},
            {10, 0, 35, 25},
            {15, 35, 0, 30},
            {20, 25, 30, 0}};

    cout << tsp(1, 0) << endl;
    return 0;
}