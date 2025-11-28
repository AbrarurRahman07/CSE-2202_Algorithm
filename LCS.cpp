#include <bits/stdc++.h>
using namespace std;
int main()
{
  string s, p;
  cout << "Enter two String:\n";
  cin >> s >> p;
  int n = s.size();
  int m = p.size();
  vector<vector<int>> t(n + 1, vector<int>(m + 1, 0));
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      if (s[i - 1] == p[i - 1])
      {
        t[i][j] = t[i - 1][j - 1] + 1;
      }
      else
      {
        t[i][j] = max(t[i - 1][j], t[i][j - 1]);
      }
    }
  }
  cout << "Longest common subsequence is " << t[n][m] << endl;
  int i = n, j = m;
  string r = "";
  while (i > 0 && j > 0)
  {
    if (s[i - 1] == p[j - 1])
    {
      r += s[i - 1];
      i--, j--;
    }
    else if (t[i - 1][j] > t[i][j - 1])
    {
      i--;
    }
    else
      j--;
  }

   reverse(r.begin(),r.end());
  cout << r << endl;
  return 0;
}